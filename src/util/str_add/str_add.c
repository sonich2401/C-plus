#include "str_add.h"
#include <string.h>
#include <stdlib.h>

string str_add(string a, string b){
  uint32 newlen = strlen(a) + strlen(b);
  string newstr = malloc(newlen);

  for(uint32 i=0; i<strlen(a);i++){
    newstr[i] = a[i];
  }
  for(uint32 i=0; i<strlen(b);i++){
    newstr[i + strlen(a)] = b[i];
  }

  return newstr;
}