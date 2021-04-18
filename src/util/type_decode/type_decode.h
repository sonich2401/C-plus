#include "../../typedefs.h"
#include "../../cppstdlib/vector/vector.h"
#include "../../cppstdlib/rfind/rfind.h"
#include "../../cppstdlib/substr/substr.h"
#include "../split/split.h"
#include "../str_add/str_add.h"

typedef struct {
  string name;
  string type;
}type_name;

typedef struct{
  type_name type;
  vector args; //type_name
}var_define;



type_name * create_type_name(string substring){
  type_name * ret = malloc(sizeof(type_name));
  
  vector str_split = split(substring, " "); //Baiscly like argv and argc
  
  ret->name = str_split[vector_size(&str_split)];


  ret->type = malloc(strlen(substr)); //Make sure we have a big enough buffer by making a buffer the size of the original string
  uint32 index = 0;
  for(uint8 i = 0; i < vector_size(&str_split); i++){ // add the splits together
    memcpy(ret->type + index, (string)str_split.dat[i], strlen((string)str_split.dat[i]));
    index += strlen((string)str_split.dat[i]);
  }

  return ret;
}

var_define * create_var(string line){
  var_define * ret = malloc(sizeof(var_define));

  return ret;
}