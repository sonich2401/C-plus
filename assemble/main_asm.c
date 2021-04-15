
#include "main_asm.h"
#include "loadfile.h"
#include "../cppstdlib/substr/substr.h"
#include "../cppstdlib/vector/vector.h"

typedef struct{
    string name;

    string * code;

    uint32 start;
    uint32 end;
} function;

typedef struct{
    string name;

    string * defines;
    function * functions;

    uint32 start;
    uint32 end;
}class_struct;

void init_struct(class_struct * o){

}

//Create a struct from a file at a given position
class_struct * create_struct(rFile * file, uint32 line_start){
    class_struct * ret;
    ret->start = line_start;

    string * rStruct = &file->dat[line_start]; //Move the cursor to the correct line of the file
    uint16 struct_name_pos =  rfind(rStruct[0], "struct ",0);


}

void assemble(options * file_list){
    rFile * files = malloc(file_list->file_count * sizeof(rFile));



    for(uint16 file_index = 0; file_index < file_list->file_count; file_index++){
        files[file_index] = loadTextFile(file_list->files[file_index]); //Load the file
        for(uint32 line_pos = 0; line_pos < files[file_index].linec; line_pos++ ){
            if( // if line contains struct or class, then
                rfind(files[file_index].dat[line_pos], "struct ",0) != -1
                ||
                rfind(files[file_index].dat[line_pos], "class ", 0)!= -1
            ){
                
            }//END OF IF
        }
    }

    //Cleanup
    for(uint16 file_index = 0; file_index < file_list->file_count; file_index++){
        free(files[file_index].dat);
        free(files[file_index].fn);
    }

    free(files);
}