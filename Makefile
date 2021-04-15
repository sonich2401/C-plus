DATE :=

CC := gcc

C_FILES := main.c assemble/main_asm.c

BUILD := c+

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)

endif

all:
	$(CC) -o $(BUILD) $(C_FILES)