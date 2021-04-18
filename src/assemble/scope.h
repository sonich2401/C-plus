#pragma once

#ifndef SCOPE_H
#define SCOPE_H


#include "../typedefs.h"
#include "../cppstdlib/vector/vector.h"
#include "loadfile.h"


typedef struct {
  string name;
  string type;
}var_def;



typedef struct function_scope;

typedef struct{
  vector varibles; //var_def
  uint16 begin, end;

  vector defines;
  vector scopes; //function_scope *
}function_scope;


function_scope * function_scope_create(string * function_start);

void fill_function_scope(function_scope * o, string * function_start);

#endif