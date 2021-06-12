.PHONY: all echo

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s
#Suppress display of executed commands.
$(VERBOSE).SILENT:

all:
	python script.py 
.PHONY: all

echo:
	echo Working!
.PHONY: echo 

clean:
	rmdir /S /Q CSTL && mkdir CSTL
.PHONY: clean