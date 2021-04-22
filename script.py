import shutil 
import os 

"""
    Most of the code for this project is written as part of ease of use at Hazel Org, the organization behind the creation of 
    the Hazel Programming Language (check it out btw). 

    This script copies the latest code from there and pastes it here, available for use without explicitely using Hazel. 
"""

SOURCE = r'F:\Documents\Dev\Github\Hazel\Hazel\Core'
HERE = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'CSTL')

for file in os.listdir(SOURCE):
    path = os.path.join(SOURCE, file)

    if not path.endswith('HCore.h'):
        destination = os.path.join(HERE, file)
    else:
        destination = os.path.join(HERE, 'CSTL.h')

    # Copy contents
    shutil.copy(path, destination)

    # Replace any #includes
    with open(destination) as f:
        s = f.read();
    
    s = s.replace('#include <Hazel/Core/', '#include <CSTL/')

    with open(destination, 'w') as f:
        f.write(s)
