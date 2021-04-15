DATE :=
CC := gcc

SOURCES := assemble, cppstdlib/rfind
INCLUDE := $(SOURCES)

C_FILES := $(wildcard $(SOURCES)/*.c) $(wildcard *.c)
H_FILES := $(wildcard $(SOURCES)/*.h) $(wildcard *.h)

BUILD := c+
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
 DATE := -DDATE="\"`date`\""
endif

all:
	$(CC) -o $(BUILD) $(DATE) $(C_FILES)