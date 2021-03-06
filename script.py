import shutil 
import os 

"""
    Most of the code for this project is written as part of ease of use at Adorad Org, the organization behind the creation of 
    the Adorad Programming Language (check it out btw). 

    This script copies the latest code from there and pastes it here, available for use without explicitely using Adorad. 
"""

SOURCE = r'/home/jas/Documents/dev/adorad/adorad/core'
HERE = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'cstl')

ADORAD_COPYRIGHT = \
"""
          _____   ____  _____            _____  
    /\   |  __ \ / __ \|  __ \     /\   |  __ \ 
   /  \  | |  | | |  | | |__) |   /  \  | |  | | Adorad - The Fast, Expressive & Elegant Programming Language
  / /\ \ | |  | | |  | |  _  /   / /\ \ | |  | | Languages: C, C++, and Assembly
 / ____ \| |__| | |__| | | \ \  / ____ \| |__| | https://github.com/adorad/adorad/
/_/    \_\_____/ \____/|_|  \_\/_/    \_\_____/ 
"""

CSTL_COPYRIGHT = \
"""
  ______ ____ ________ _
 / ____/ ____|__   __/| |
| |    | (_     | |   | |      CSTL - The Coreten Standard Library
| |    \___ \   | |   | |      Languages: C, C++ and Assembly
| |___ ____) |  | |   | |____  https://github.com/jasmcaus/cstl
 \_____\_____/  |_|   \______| 
"""

A = """\

#ifndef CORETEN_USING_CUSTOM_GENERATED_MACROS
    #include <adorad/core/cmake_macros.h>
#endif // CORETEN_USING_CUSTOM_GENERATED_MACROS
"""

B = """\

#ifndef _ADORAD_
      #define _ADORAD_
#endif // _ADORAD_

"""

def run():
    if not os.path.exists(HERE):
        os.mkdir(HERE)

    for file in os.listdir(SOURCE):
        path = os.path.join(SOURCE, file)

        if path.endswith(('cmake_macros.h', 'CMakeLists.txt')):
            continue

        if not path.endswith('adcore.h'):
            destination = os.path.join(HERE, file)
        else:
            destination = os.path.join(HERE, 'cstl.h')

        # Copy contents
        shutil.copy(path, destination)

        # Replace any #includes
        with open(destination) as f:
            s = f.read();

        s = s.replace(A, '')
        # s = s.replace(B, '')
        s = s.replace('typedef cstlBuffer Buff;\n', '')
        s = s.replace('typedef cstlVector Vec;', '')
        s = s.replace('#ifndef _ADORAD_', '')
        s = s.replace('#endif // _ADORAD_', '')
        s = s.replace('#include <adorad/core/', '#include <cstl/')
        s = s.replace("ADORAD", "CORETEN")
        s = s.replace(ADORAD_COPYRIGHT, CSTL_COPYRIGHT)
        s = s.replace("namespace adorad", "namespace coreten")

        s = s.replace('\n#ifndef ADORAD', '')
        s = s.replace('#endif // ADORAD', '')
        # s = s.replace('\n#ifdef CORETEN_IMPL', '')
        # s = s.replace('#ifdef CORETEN_IMPL', '')
        # s = s.replace('\n#endif // CORETEN_IMPL', '')
        # s = s.replace('#endif // CORETEN_IMPL', '')

        with open(destination, 'w') as f:
            f.write(s)


if __name__ == '__main__':
    run()
