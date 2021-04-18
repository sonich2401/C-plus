#include "../../typedefs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef rfind_FAIL
    #define rfind_FAIL -1
#endif

//Find the index of a word in a string given the keyword that your looking for
int32 rfind(string src, string find, uint32 offset);


//Find the last index of a word in a string given the keyword that your looking for
int32 rfind_l(string src, string find, uint32 offset);