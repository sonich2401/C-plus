#include "../../typedefs.h"
#include "../../cppstdlib/vector/vector.h"


typedef struct {
  string name;
  string type;
}type_name;

typedef struct{
  type_name type;
  vector args; //type_name
}var_define;



type_name * create_type_name(string substring);