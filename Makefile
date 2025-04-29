# Toolchain
CC = /home/user/utils/riscv/bin/riscv64-unknown-linux-gnu-gcc
OBJCOPY = /home/user/utils/riscv/bin/riscv64-unknown-linux-gnu-objcopy

ISP = /home/user/utils/wchisp/wchisp
SOURCES = main.c ch32v307.c
BUILD_DIR = ./build
TARGET = firmware
SRC_DIRS = . ch32v307


# Flags
CFLAGS = -Os -nostdlib -march=rv32imac -mabi=ilp32 $(addprefix -I, $(SRC_DIRS))
LDFLAGS = -Tld/ch32v307.ld

# Files
SRC = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJ =	$(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC))

ELF = $(BUILD_DIR)/$(TARGET).elf
BIN = $(BUILD_DIR)/$(TARGET).bin

all : $(BIN)

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(ELF): $(OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

flash: $(BIN)
	$(ISP) flash $<

info:
	$(ISP) info

clean:
	rm $(BUILD_DIR)/*

.PHONY: all clean flash






