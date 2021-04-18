#include  <stdio.h>

#include "argv/useage.h"
#include "argv/argv.h"
#include "util/replace/replace.h"

#include "assemble/main_asm.h"

int main(int argc, void * argv[]){
    
    options main_options;

    main_options = argv_decode(argc, argv); //Do crap with argv and send it back

    bool returncode = displayUsage(main_options.error); //If error is the default value this function will do nothing

    if(!returncode){ //If there was no errors then
        printf("Assembling ...\n");
        for(uint8 i = 0; i < main_options.file_count; i++){
            printf("\t%s\n", main_options.files[i]);
        }

        assemble(&main_options);

        if(main_options.use_make == false){ //Make sure we dont leak memory
          printf("HERE\n");
            //free(main_options.gcc_command);
            printf("HERE\n");
        }
        for(uint16 i = 0; i < main_options.file_count; i++){
          free(main_options.files[i]);
        }
        free(main_options.files);
    }

    //Cleanu

    printf("END OF LINE ...\n");
    return 0;
}