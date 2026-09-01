```makefile
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic

BUILD_DIR = build

SOURCES := $(shell find . -type f -name "*.c" -not -path "./$(BUILD_DIR)/*")
TARGETS := $(patsubst ./%.c,$(BUILD_DIR)/%,$(SOURCES))

.PHONY: all clean rebuild list

all: $(TARGETS)

$(BUILD_DIR)/%: %.c
	@mkdir -p "$(dir $@)"
	@$(CC) $(CFLAGS) "$<" -o "$@"

clean:
	@rm -rf "$(BUILD_DIR)"

rebuild: clean
	@$(MAKE) all

list:
	@echo "Source files:"
	@$(foreach src,$(SOURCES),echo "$(src)";)
```
