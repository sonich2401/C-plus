UNAME := $(shell uname)
DATE :=

VS_PATH = C://"Program Files (x86)"/"Microsoft Visual Studio"/2019/Community/VC/Tools/MSVC/"14.27.29110"/bin/Hostx64/x64

ifeq ($(UNAME), Linux)
	CC := gcc
else
	CC := $(VS_PATH)/cl.exe
endif

SOURCES := assemble cppstdlib/rfind cppstdlib/vector cppstdlib/substr argv
INCLUDE := $(SOURCES)

C_FILES := $(foreach dir,$(SOURCES),  $(wildcard $(dir)/*.c) ) $(wildcard *.c)
H_FILES := $(wildcard $(SOURCES)/*.h) $(wildcard *.h)

BUILD := c+


ifeq ($(UNAME), Linux)
	DATE := -DDATE="\"`date`\""
	CMD := $(CC) -o $(BUILD) $(DATE) $(C_FILES)
else
	DATE := /DDATE="\"`date`\""
	CMD_ARGS := /TC /Fe$(BUILD)
	CMD := $(CC) $(CMD_ARGS) $(BUILD) $(C_FILES)
endif

all:
	@$(CC) -o $(BUILD) -Wno-incompatible-pointer-types $(DATE) $(C_FILES)
		