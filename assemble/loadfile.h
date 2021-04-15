#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../typedefs.h"


#define LOAD_FILE_MAX_LINES 500
#define LOAD_FILE_MAX_CHARS 300

string ** loadTextFile(char * file_path){

    string ** ret;
    unsigned long max_line = LOAD_FILE_MAX_LINES;
    unsigned long cur_line = 0;
    ret = malloc(sizeof(string *) * max_line );

   FILE *file = fopen (  file_path, "r" );
   if ( file != NULL )
   {
      char line [ LOAD_FILE_MAX_CHARS ]; 

      while ( fgets ( line, sizeof(line), file ) != NULL)
      {
        if(feof(file)){return ret;}//Check if end of file

        if(cur_line+1 >= max_line){
            ret = realloc(ret, max_line + (50 * sizeof(string * )));
            max_line += 50;
        }
        printf("%li\n", cur_line);
        ret[cur_line] = malloc(strlen(line)+1);
        strcpy(ret[cur_line++],line);
      }
      fclose ( file );
   }
   return 0;
}

#undef LOAD_FILE_MAX_LINES
#undef LOAD_FILE_MAX_CHARS
