
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

# default rule - make (almost) everything
all: $(Z) 

# python build configuration
config:
	python $(BIN)/getconfig.py > python.cnf

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
	rm -rf $(OBJ) $(PACKAGE)

# keep intermediate objects around
.PRECIOUS: $(OBJ)/%.o
