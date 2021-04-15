#pragma once
#include <stdio.h>
#include <string.h>
#include "../typedefs.h"
#include "../cppstdlib/stoi/stoi.h"
#include "../cppstdlib/rfind/rfind.h"


#ifndef USE_ERRORS_ARGV_H
#define USE_ERRORS_ARGV_H
extern const string useage_errors[];
#endif

typedef struct {
    string gcc_command;
    bool auto_make;
    bool delete_c;
    bool use_make;
    int supress; // 0 = none, 1 = gcc, 2 = c+
    int verb; // 0 = disabled
    uint16 file_count;
    string * files;
    string error;
}options;

void init_options(options * o);


options argv_decode(int argc, void * argv[]);