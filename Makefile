# compiler, linker, and options
CC := cc
CFLAGS :=

# virtual environment (optional)
VENV := venv

# directories
INCLUDE := include
SRC := src
OBJ += obj
PACKAGE := z

# headers
HEADERS := $(INCLUDE)/core/storage.h

# core package components
CORE := $(PACKAGE)/__init__.py
CORE += $(PACKAGE)/core/__init__.py
CORE += $(PACKAGE)/core/storage.o

# default rule - make (almost) everything
all: $(CORE)

# python module - copy source file from source to target
$(PACKAGE)/%.py: $(SRC)/%.py
	mkdir -p $(@D)
	cp $< $@

# python extension module - build intermediate objects
$(OBJ)/%.o: $(SRC)/%.c $(HEADERS)

# python extension module - run linker to create shared object
#$(PACKAGE)/%.so: $(OBJ)/%.o
#	echo 'hi'

# virtual environment - activate using `source venv/bin/activate`
$(VENV):
	python -m venv $(VENV)

# cleanup rule
clean:
	rm -rf $(OBJ)
	rm -rf $(PACKAGE)
