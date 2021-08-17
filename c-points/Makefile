# ------------------------------------------------
# Generic Makefile
#
# Author: Murilo Chianfa <github.com/MuriloChianfa>
# Date  : 2021-08-14
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = example

CC       = gcc
CFLAGS   = -std=c99 -Wall -I.

LINKER   = gcc
LFLAGS   = -Wall -I. -lm

SRCDIR   = src
OBJDIR   = obj
BINDIR   = .

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f
rmdir    = rm -rf

$(BINDIR)/$(TARGET): $(OBJECTS)
	@echo "\nLinking..."
	$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!\n"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@echo "\nCompiling $< to $@"
	@[ -d "$(OBJDIR)" ] || mkdir $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@echo "\nCleaning..."
	$(rm) $(OBJECTS)
	@$(rmdir) $(OBJDIR)
	@echo "Cleanup complete!\n"

.PHONY: remove
remove: clean
	@echo "Removing executable..."
	$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!\n"

