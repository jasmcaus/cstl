import shutil 
import os 

"""
    Most of the code for this project is written as part of ease of use at Hazel Org, the organization behind the creation of 
    the Hazel Programming Language (check it out btw). 

    This script copies the latest code from there and pastes it here, available for use without explicitely using Hazel. 
"""

SOURCE = r'F:\Documents\Dev\Github\Hazel\hazel\core'
HERE = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'cstl')

for file in os.listdir(SOURCE):
    path = os.path.join(SOURCE, file)
    destination = os.path.join(HERE, file)

    shutil.copy(path, destination)