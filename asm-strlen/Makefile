PROGNAME = strlen
rm     = rm -f

all: $(PROGNAME)

print-uint32.o: ../print-uint32-asm/print-uint32.asm
	@echo "\nCompiling..."
	nasm -f elf64 ../print-uint32-asm/print-uint32.asm
	@echo "Compiled print-uint32 successfully!\n"

$(PROGNAME).o: $(PROGNAME).asm
	@echo "Compiling..."
	nasm -f elf64 $(PROGNAME).asm

$(PROGNAME): print-uint32.o $(PROGNAME).o
	ld -s -o $(PROGNAME) $(PROGNAME).o ../print-uint32-asm/print-uint32.o
	@echo "Compiled $(PROGNAME) successfully!\n"

.PHONY: clean
clean:
	@echo "\nCleaning..."
	$(rm) $(PROGNAME).o
	$(rm) ../print-uint32-asm/print-uint32.o
	@echo "Cleanup complete!\n"

.PHONY: remove
remove:
	@echo "\nRemoving object and executable..."
	$(rm) $(PROGNAME).o $(PROGNAME)
	$(rm) ../print-uint32-asm/print-uint32.o
	@echo "Executable removed!\n"

