PROGNAME = true
rm       = rm -f

all: $(PROGNAME)

$(PROGNAME).o: $(PROGNAME).asm
	@echo "\nCompiling..."
	nasm -f elf64 $(PROGNAME).asm

$(PROGNAME): $(PROGNAME).o
	ld -s -o $(PROGNAME) $(PROGNAME).o
	@echo "Compiled $(PROGNAME) successfully!\n"

.PHONY: clean
clean:
	@echo "\nCleaning..."
	$(rm) $(PROGNAME).o
	@echo "Cleanup complete!\n"

.PHONY: remove
remove:
	@echo "\nRemoving object and executable..."
	$(rm) $(PROGNAME).o $(PROGNAME)
	@echo "Executable removed!\n"

