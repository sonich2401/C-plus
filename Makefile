DATE :=
CC := gcc

SOURCES := assemble cppstdlib/rfind cppstdlib/vector argv
INCLUDE := $(SOURCES)

C_FILES := $(foreach dir,$(SOURCES),  $(wildcard $(dir)/*.c) ) $(wildcard *.c)
H_FILES := $(wildcard $(SOURCES)/*.h) $(wildcard *.h)

BUILD := c+
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
 DATE := -DDATE="\"`date`\""
endif

all:
	$(CC) -o $(BUILD) $(DATE) $(C_FILES)