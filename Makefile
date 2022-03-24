.PHONY: all echo

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s
#Suppress display of executed commands.
$(VERBOSE).SILENT:
MAKEFLAGS += --silent

all:
	python3 script.py
	git aa
	git c 'Update core'
	git po dev
.PHONY: all

echo:
	echo Working!
.PHONY: echo

test:
	gcc test.c -o test.exe -I .
	./test.exe
.PHONY: test 