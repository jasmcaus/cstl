cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# CSTL's Internal Tests
# We use Tau, a custom unit testing framework built by Jason Dsouza <@jasmcaus>

# Tau requires at least C11/C++11
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fetch Tau, our custom C/C++ testing library
message("--------- [INFO] Fetching Tau from GitHub")
include(FetchContent)
FetchContent_Declare(
    Tau
    URL https://github.com/jasmcaus/tau/archive/dev.zip
)
FetchContent_MakeAvailable(Tau)

file(GLOB 
    CSTL_INTERNAL_TESTS_SOURCES
    "test_*.c"
    "test_*.cxx"
    "test_*.cpp"
)

add_executable(
    CSTLInternalTests
    main.c
    "${CSTL_INTERNAL_TESTS_SOURCES}"
)

install(
    TARGETS CSTLInternalTests
    RUNTIME DESTINATION ${TAU_BIN_DIR}
)

target_include_directories(
    CSTLInternalTests 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# The CSTL INTERFACE library
target_link_libraries(CSTLInternalTests PRIVATE 
    CSTL Tau
)
