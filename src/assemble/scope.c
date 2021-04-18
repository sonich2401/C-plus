#include "scope.h"
#include "../cppstdlib/rfind/rfind.h"
#include "../cppstdlib/substr/substr.h"
#include "../util/type_decode/type_decode.h"


uint16 find_function_end(string * function_start);

function_scope * function_scope_create(string * function_start){
  function_scope * ret = malloc(sizeof(function_scope));

  fill_function_scope(ret, function_start);


  return ret;
}

const string std_types[] = {
  "int ",
  "long ",
  "short ",
  "float ",
  "double ",
  "char ",
  "void "
};


void fill_function_scope(function_scope * o, string * function_start){
  o->end = find_function_end(&function_start[0]);

  for(uint16 i = 0; i < o->end; i++){
    for(uint16 i1 = 0; i1 < o->defines.total_data; i1++){
      if(rfind(function_start[i], ((string *)o->defines.dat)[i1],0) != rfind_FAIL){ //If there is a data type named
        if(rfind(function_start[i], "(",0)!= rfind_FAIL){//Is it a function?
          if(rfind(function_start[i],")",0) != rfind_FAIL){
            //vector_push_back(&o->scopes, function_scope_create(function_start + i));
            //vector_push_back(&o->defines,((var_def *)vector_back(&o->scopes))->name);
          }
        }
      }
    }
  }
}

uint16 find_function_end(string * function_start){
  uint16 in_scope=1; //How manny scopes have we been in?
  uint16 i;
  for(i = 1; in_scope > 0; i++){
    printf("DEBGG: %i:%s:\n",i,function_start[i]);
    if(rfind(function_start[i], "{", 0)!=rfind_FAIL){
      in_scope++;
    }
    if(rfind(function_start[i], "}", 0)!=rfind_FAIL){
      in_scope--;
    }
  }
  return i;
}