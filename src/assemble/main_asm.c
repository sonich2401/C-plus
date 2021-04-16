
#include "main_asm.h"
#include "loadfile.h"
#include "../cppstdlib/substr/substr.h"
#include "../cppstdlib/vector/vector.h"

typedef struct{
    string name;

    vector code; //string

    uint32 start;
    uint32 end;
} function;

void deconstruct_function(function * o){
    free(o->name);
    vector_deconstruct(&o->code);
}




typedef struct{
    string name;

    vector defines; //string
    vector functions; //function

    uint32 start;
    uint32 end;
}class_struct;

void deconstruct_class_struct(class_struct * o){
    free(o->name);

    vector_deconstruct(&o->defines);
    vector_deconstruct(&o->functions);

    //free(&o->functions);
}

//Create a struct from a file at a given position
class_struct * create_struct(rFile * file, uint32 line_start){
    class_struct * ret = malloc(sizeof(class_struct));

    ret->start = line_start;
    
    vector_init(&ret->defines, sizeof(string), NULL);
    vector_init(&ret->functions, sizeof(string), NULL);

    string * rStruct = &file->dat[line_start]; //Move the cursor to the correct line of the file
    uint16 struct_name_pos =  rfind(rStruct[0], "struct",0);
    struct_name_pos =rfind(rStruct[0], " ",0);
    uint16 last_pos = struct_name_pos;


    int32 name_end_pos = rfind(rStruct[0], "{",0);
    if(name_end_pos == -1){
        ret->name = substr(rStruct[0], last_pos, strlen(rStruct[0]));
    }else{
        ret->name = substr(rStruct[0], last_pos, name_end_pos);
    }

    return ret;
}




typedef struct{
    vector * structs; //class_struct
    vector * classes; //class_struct
    vector * function_refs; //uint32
}source_defines;

void source_defines_init(source_defines * o){
    o->classes = vector_create(sizeof(class_struct), deconstruct_class_struct);
    o->structs = vector_create(sizeof(class_struct), deconstruct_class_struct);
    o->function_refs = vector_create(sizeof(uint32), NULL);
}


void assemble(options * file_list){
    rFile ** files = malloc(file_list->file_count * sizeof(rFile*));

    source_defines ** defines = malloc(file_list->file_count * sizeof(source_defines));
    

    for(uint16 file_index = 0; file_index < file_list->file_count; file_index++){
        defines[file_index] = malloc(sizeof(source_defines));
        source_defines_init(defines[file_index]);
        
        //files[file_index] = malloc(sizeof(rFile));
        files[file_index] = loadTextFile(file_list->files[file_index]); //Load the file
       
        for(uint32 line_pos = 0; line_pos < files[file_index]->linec; line_pos++ ){
            if(rfind(files[file_index]->dat[line_pos], "struct ",0) != -1){
                class_struct * tmp = create_struct(files[file_index], line_pos);
                vector_push_back(defines[file_index]->structs, tmp);
            }  
            if(rfind(files[file_index]->dat[line_pos], "class ", 0)!= -1){
                vector_push_back(defines[file_index]->classes, create_struct(&files[file_index], line_pos));
            }//END OF IF
        }
    }

    for(uint16 i =0; i < vector_size(defines[0]->structs); i++){
        printf("DEFINE: %s\n", ((class_struct*)vector_index(defines[0]->structs, i))->name  );
    }

    //Cleanup
    for(uint16 file_index = 0; file_index < file_list->file_count; file_index++){
        free(files[file_index]->dat);
        free(files[file_index]->fn);
    }

    free(files);
}