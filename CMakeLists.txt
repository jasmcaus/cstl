cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(CSTL_VERSION 1.0.0)

project(CSTL 
        VERSION ${CSTL_VERSION}
        DESCRIPTION "CSTL: The C/C++ Unofficial Standard Library"
        LANGUAGES C CXX
)

# CMake's FATAL_ERROR is ignored on CMake versions >2.6 
# Hence we explicitely check for correct enforcement of CMake configurations.
if (${CMAKE_VERSION} VERSION_LESS "3.20")
    message(
        ERROR "You are currently on CMake Version ${CMAKE_VERSION}, but CSTL supports CMake 3.20 above."
        "Please update your CMake installation."
    )
endif()

        
# ------ Disable CMAKE_INSTALL_MESSAGE  ------
set(CMAKE_INSTALL_MESSAGE NEVER)

# ------ Setting the C Standard ------
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

## 
## Options
##

# Determine if CSTL is built as a subproject (using add_subdirectory) or if it is the main project being built
set(IS_MAIN_PROJECT OFF)
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(IS_MAIN_PROJECT ON)
endif()


if (POLICY CMP0077)
    # Allow CMake 3.13+ to override options when using FetchContent/add_subdirectory.
    cmake_policy(SET CMP0077 NEW)
endif()


option(CSTL_BUILDINTERNALTESTS "Build unit tests." ${IS_MAIN_PROJECT})
option(CSTL_HIDE_INTERNAL_SYMBOLS "Hide internal symbols" ON)

if (CSTL_HIDE_INTERNAL_SYMBOLS)
    set(CMAKE_C_VISIBILITY_PRESET hidden)
    set(CMAKE_CXX_VISIBILITY_PRESET hidden)
    set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
endif()


## 
## Configurations
##

# ------Compiler and linker options ------
# In case of Makefiles, if the user does not setup CMAKE_BUILD_TYPE, assume it's Release: 
if(CMAKE_GENERATOR MATCHES "Makefiles|Ninja" AND "${CMAKE_BUILD_TYPE}" STREQUAL "")
    message(STATUS "[INFO] Build type not set - defaulting to Release")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build from: [Debug, Release, RelWithDebInfo, MinSizeRel]." FORCE)
endif()

# ------ A List of Compiler Flags ------
# A (more or less comprehensive) list is here: https://caiorss.github.io/C-Cpp-Notes/compiler-flags-options.html
if(NOT MSVC)
    if("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
        string(APPEND CMAKE_C_FLAGS " -std=gnu11")
    else()
        string(APPEND CMAKE_C_FLAGS " -std=c11")
    endif()

    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        string(APPEND CMAKE_CXX_FLAGS " -std=gnu++11")
    else()
        string(APPEND CMAKE_CXX_FLAGS " -std=c++11")
    endif()

    # Optimizations
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        string(APPEND COMPILE_FLAGS " -O2")
    endif()
    
    string(APPEND COMPILE_FLAGS " -Wall")
    string(APPEND COMPILE_FLAGS " -Wextra")
    
    if(WERROR)
        check_cxx_compiler_flag("-Werror" COMPILER_SUPPORT_WERROR)
        if(NOT COMPILER_SUPPORT_WERROR)
            set(WERROR FALSE)
        else()
            string(APPEND COMPILE_FLAGS " -Werror")   
        endif()
    endif(WERROR)

# For MSVC 
else()
    string(APPEND CMAKE_C_FLAGS " /std:c11")
    # MSVC complains that this isn't a valid cmdline option.
    # Am I going wrong here, somehow?
    # string(APPEND CMAKE_CXX_FLAGS " /std:c++11")

    # Build in parallel
    string(APPEND COMPILE_FLAGS " /m:4")

    # Optimizations
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        string(APPEND COMPILE_FLAGS " /O2")
    endif()

    string(APPEND COMPILE_FLAGS " /Wall")
    # string(APPEND COMPILE_FLAGS " /WX")  # Treats Linker Warnings as Errors
    
    # Ignore some MSVC warnings
    string(APPEND COMPILE_FLAGS " /wd4061")
    string(APPEND COMPILE_FLAGS " /wd4090")
    string(APPEND COMPILE_FLAGS " /wd4100")
    string(APPEND COMPILE_FLAGS " /wd4127")
    string(APPEND COMPILE_FLAGS " /wd4201")
    string(APPEND COMPILE_FLAGS " /wd4242")
    string(APPEND COMPILE_FLAGS " /wd4514")
    string(APPEND COMPILE_FLAGS " /wd4668")
    string(APPEND COMPILE_FLAGS " /wd4710")
    string(APPEND COMPILE_FLAGS " /wd4711")
    string(APPEND COMPILE_FLAGS " /wd4820")
    string(APPEND COMPILE_FLAGS " /wd4996")
    string(APPEND COMPILE_FLAGS " /wd5045")
    string(APPEND COMPILE_FLAGS " /wd5105")
endif()


# This library will be platform-independent, but still be installable following best practices. 
# We include GNUInstallDirs (included in CMake) which provides us with a set of variables containing installation 
# directories for various artifacts.
include(GNUInstallDirs)

# ------ Options ------
set(CSTL_ROOT_DIR                    ${CMAKE_CURRENT_SOURCE_DIR})
set(CSTL_BIN_DIR                     ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(CSTL_LIB_DIR                     ${CMAKE_CURRENT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY   ${CSTL_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY   ${CSTL_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY   ${CSTL_LIB_DIR})

set(CSTL_TARGET_NAME           ${PROJECT_NAME}Targets)
set(CSTL_TARGETS_CMAKE         ${CMAKE_CURRENT_BINARY_DIR}/${CSTL_TARGET_NAME}.cmake)

set(CSTL_HEADERS_INCLUDE_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/CSTL)

# CMake Configurations (from the ``cmake`` folder)
set(CSTL_CMAKE_CONFIGVERSION_IN      ${CMAKE_CURRENT_SOURCE_DIR}/cmake/ConfigVersion.cmake.in)
set(CSTL_CMAKE_CONFIGVERSION         ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake)
set(CSTL_CMAKE_CONFIG_IN             ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in)
set(CSTL_CMAKE_CONFIG                ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake)
set(CSTL_CMAKE_CONFIGS_INSTALL_DIR   "lib/cmake/${PROJECT_NAME}" CACHE INTERNAL "")
set(CSTL_CMAKE_PKGCONFIG_IN          ${CMAKE_CURRENT_SOURCE_DIR}/cmake/pkg-config.pc.in)
set(CSTL_CMAKE_PKGCONFIG             ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-Pkg-Config.pc)


# ------ Main Build ------
# Main Build File for the main CSTL Library
# Note that this library must have _minimal_ dependencies 

# Where CSTL's .h files can be found.
set(
    CSTL_BUILD_INCLUDE_DIRS
    "${CSTL_ROOT_DIR}/cstl"
    "${CSTL_ROOT_DIR}"
)
include_directories(${CSTL_BUILD_INCLUDE_DIRS})

# Create the CSTL Interface Library
# Interfaces are best for header-only libraries
add_library(CSTL INTERFACE)
# Add an alias so that CSTL can be used with add_subdirectory
add_library(CSTL::CSTL ALIAS CSTL)

if (${CMAKE_VERSION} VERSION_LESS "3.8.0")
    target_compile_features(CSTL INTERFACE c_range_for)
else()
    target_compile_features(CSTL INTERFACE c_std_11)
endif()

set_target_properties(CSTL PROPERTIES VERSION ${CSTL_VERSION})

target_include_directories(
    CSTL 
    INTERFACE 
    # If CSTL is used directly by another cmake target (such as when building tests or when it is included 
    # as a sub-directory)
    # $<BUILD_INTERFACE:"${CSTL_HEADERS_INCLUDE_DIR}">
    "$<BUILD_INTERFACE:${CSTL_BUILD_INCLUDE_DIRS}>"
    # The path if CSTL is installed
    # $<INSTALL_INTERFACE:"include">
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}}>"
)


# ------ Installations ------
# Only perform the installation if CSTL is built as the main project (i.e not included as an external project, 
# or a subdirectory) or destinations might break.
if(IS_MAIN_PROJECT)
    ## Installation header files, generate and install cmake config files for find_package()
    include(CMakePackageConfigHelpers)

    # We write a custom package version config file instead of `write_basic_package_version_file` to ensure that it's 
    # architecture-independent

    # ConfigVersion.cmake.in --> CSTLConfigVersion.cmake
    configure_file(
        ${CSTL_CMAKE_CONFIGVERSION_IN}
        ${CSTL_CMAKE_CONFIGVERSION}
        @ONLY
    )
    # config.cmake.in --> CSTLConfig.cmake
    configure_file(
        ${CSTL_CMAKE_CONFIG_IN}
        ${CSTL_CMAKE_CONFIG}
        @ONLY
    )
    # Install a pkg-config file, so other tools can find this.
    configure_file(
        ${CSTL_CMAKE_PKGCONFIG_IN}
        ${CSTL_CMAKE_PKGCONFIG}
    )
    # Install the pkg-config file to lib/pkgconfig
    install(
        FILES ${CSTL_CMAKE_PKGCONFIG}
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
    )

    # Move CSTLConfig.cmake and CSTLConfigVersion.cmake  ---> lib/cmake/CSTL/...
    install(
        FILES "${CMAKE_CURRENT_BINARY_DIR}/CSTLConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/CSTLConfigVersion.cmake" 
        DESTINATION "lib/cmake/CSTL"
    )

    # ./include --> include
    install(
        DIRECTORY ${CSTL_HEADERS_INCLUDE_DIR}
        DESTINATION CSTL
    )


    # Export CSTLTargets from CSTLTargets.cmake
    export(
        TARGETS CSTL
        FILE ${CSTL_TARGETS_CMAKE}
    )

    install(
        EXPORT ${CSTL_TARGET_NAME}
        DESTINATION lib/cmake/CSTL
    )
endif() # IS_MAIN_PROJECT

# install(
#     TARGETS CSTL
#     EXPORT "${CSTL_TARGET_NAME}Targets"
#     INCLUDES DESTINATION ${CSTL_HEADERS_INCLUDE_DIR}
# )
install(
    TARGETS CSTL
    EXPORT ${CSTL_TARGET_NAME}
    ARCHIVE DESTINATION "lib"
    LIBRARY DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    ## This results in an error:
    ## ``INTERFACE_INCLUDE_DIRECTORIES`` property contains path ... which is prefixed in the source directory. 
    ##
    ## There may be something I'm missing out - if you know how to fix this, please send in a PR :)
    # INCLUDES DESTINATION ${CSTL_HEADERS_INCLUDE_DIR)
)

# Header files are copied to the install directory
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/cstl
    DESTINATION include
)

# If at least one test option is ON, we need to enter the `test` directory
# The relevant options will be parsed and the appropriate tests will be called
if(CSTL_BUILDINTERNALTESTS)
    add_subdirectory(test)
endif()
