import shutil 
import os 

"""
    Most of the code for this project is written as part of ease of use at Hazel Org, the organization behind the creation of 
    the Hazel Programming Language (check it out btw). 

    This script copies the latest code from there and pastes it here, available for use without explicitely using Hazel. 
"""

SOURCE = r'F:\Documents\Dev\Github\Hazel\Hazel\Core'
HERE = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'CSTL')

HAZEL_COPYRIGHT = \
"""
_ _    _           ______   _______        
| |  | |    /\    /___  /   |  ____|| |    
| |__| |   /  \      / /    | |__   | |       Hazel - The Fast, Expressive & Elegant Programming Language
|  __  |  / /\ \    / /     |  __|  | |       Languages: C, C++, and Assembly
| |  | | / ____ \  / /___   | |____ | |____   https://github.com/HazelLang/Hazel/
|_|_ |_|/_/    \_\/_______\ |______|_\______|
"""

CSTL_COPYRIGHT = \
"""
  ______ ____ ________ _
 / ____/ ____|__   __/| |
| |    | (_     | |   | |      CSTL - The neatest rewrite of the C/C++ Standard Library
| |    \___ \   | |   | |      Language: C
| |___ ____) |  | |   | |____  https://github.com/jasmcaus/CSTL
 \_____\_____/  |_|   \______| 
"""

for file in os.listdir(SOURCE):
    path = os.path.join(SOURCE, file)

    if not path.endswith(('HCore.h', 'CMake_Macros.h')):
        destination = os.path.join(HERE, file)
    else:
        destination = os.path.join(HERE, 'CSTL.h')

    # Copy contents
    shutil.copy(path, destination)

    # Replace any #includes
    with open(destination) as f:
        s = f.read();
    
    s = s.replace('#include <Hazel/Core/', '#include <CSTL/')
    s = s.replace("HAZEL_", "CSTL_")
    s = s.replace(HAZEL_COPYRIGHT, CSTL_COPYRIGHT)
    s = s.replace("namespace Hazel", "namespace cstl")

    with open(destination, 'w') as f:
        f.write(s)
