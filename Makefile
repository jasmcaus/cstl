.PHONY: all echo

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s
#Suppress display of executed commands.
$(VERBOSE).SILENT:

all:
	python3 script.py
.PHONY: all

echo:
	echo Working!
.PHONY: echo