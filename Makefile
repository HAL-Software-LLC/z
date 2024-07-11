
# python compiler, linker, and options
-include python.cnf

# virtual environment (optional)
VENV := venv

# directories
BIN := bin
INCLUDE := include
SRC := src
OBJ += obj
PACKAGE := z

# headers
HEADERS := $(INCLUDE)/storage.h

# core package components
Z := $(PACKAGE)/__init__.py
Z += $(PACKAGE)/storage.so

# instructions
INSTRUCTIONS := $(PACKAGE)/instructions/__init__.py
INSTRUCTIONS += $(PACKAGE)/instructions/s360.py
INSTRUCTIONS += $(PACKAGE)/instructions/s370.py
INSTRUCTIONS += $(PACKAGE)/instructions/s390.py
INSTRUCTIONS += $(PACKAGE)/instructions/z13.py
INSTRUCTIONS += $(PACKAGE)/instructions/z14.py
INSTRUCTIONS += $(PACKAGE)/instructions/z15.py
INSTRUCTIONS += $(PACKAGE)/instructions/z16.py

# assembly instructions
INSTRUCTIONS += $(PACKAGE)/instructions/assembly/__init__.py

# control instructions
INSTRUCTIONS += $(PACKAGE)/instructions/control/__init__.py

# decimal instructions
INSTRUCTIONS += $(PACKAGE)/instructions/decimal/__init__.py

# float instructions
INSTRUCTIONS += $(PACKAGE)/instructions/float/__init__.py

# general instructions
INSTRUCTIONS += $(PACKAGE)/instructions/general/__init__.py

# io instructions
INSTRUCTIONS += $(PACKAGE)/instructions/io/__init__.py

# vector instructions
INSTRUCTIONS += $(PACKAGE)/instructions/vector/__init__.py

# default rule - make (almost) everything
all: $(Z) $(INSTRUCTIONS)

# python build configuration
config:
	python $(BIN)/getconfig.py > python.cnf
	cat python.cnf

# python module - copy source file from source to target
$(PACKAGE)/%.py: $(SRC)/%.py
	mkdir -p $(@D)
	cp $< $@

# python extension module - build intermediate objects
$(OBJ)/%.o: $(SRC)/%.c $(HEADERS)
	mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I$(INCLUDEPY) -c -o $@ $<

# python extension module - run linker to create shared object
$(PACKAGE)/%.so: $(OBJ)/%.o
	$(BLDSHARED) $(LDFLAGS) $< -o $@ -L$(abspath .) -Wl,-rpath=$(abspath .)

# virtual environment - activate using `source venv/bin/activate`
$(VENV):
	python -m venv $(VENV)

# cleanup rule
clean:
	rm -rf $(OBJ) $(PACKAGE) python.cnf

# keep intermediate objects around
.PRECIOUS: $(OBJ)/%.o
