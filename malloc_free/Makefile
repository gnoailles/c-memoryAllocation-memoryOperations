TARGET  = malloc_free
TARGET_LIB = malloc_free.so

CC       = g++
CFLAGS   = -m64 -W -Wextra -Wall -Werror -I./includes

LINKER   = g++
LFLAGS   = -m64 -I./includes

SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
LIBDIR   = lib

SOURCES  := $(shell find $(SRCDIR) -name '*.c')
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
SHARED_OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(LIBDIR)/$(OBJDIR)/%.o)
SHARED_OBJECTS  :=$(filter-out $(LIBDIR)/$(OBJDIR)/main.o, $(SHARED_OBJECTS))
RM       = rm -rf

.PHONY: all
all: $(BINDIR)/$(TARGET) | $(BINDIR)

$(BINDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"


.PHONY: sharedlib
sharedlib: $(LIBDIR)/$(TARGET_LIB)

$(LIBDIR)/$(TARGET_LIB) : $(SHARED_OBJECTS)
	@mkdir -p $(LIBDIR)
	@$(LINKER) $(SHARED_OBJECTS) -shared $(LFLAGS) -o $@
	@echo "Linking shared lib complete!"


$(SHARED_OBJECTS): $(LIBDIR)/$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -fPIC $(CFLAGS) -c $< -o $@
	@echo "Compiled shared "$<" successfully!"



.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@$(RM) $(SHARED_OBJECTS)
	@echo "Cleanup complete!"

.PHONY: fclean
fclean: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
	@$(RM) $(LIBDIR)/$(TARGET_LIB)
	@echo "Shared Library removed!"

.PHONY: re
re  : fclean all sharedlib
