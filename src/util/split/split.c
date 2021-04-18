#include "split.h"
#include "../../cppstdlib/rfind/rfind.h"
#include "../../cppstdlib/substr/substr.h"

vector split(string src, string token){
  uint32 last_found = 0;
  last_found = rfind(src, token, last_found);

  vector * tmp = vector_create(sizeof(string), NULL);
  vector ret;
  memcpy(&ret, tmp, sizeof(vector));

  while(last_found != rfind_FAIL){

    int32 current_found = rfind(src, token, last_found);

    if(current_found != rfind_FAIL){
      vector_push_back(&ret, substr(src, last_found, current_found));
    }

    last_found = current_found;
  }

  return ret;
}