#include  <stdio.h>

#include "argv/useage.h"
#include "argv/argv.h"

#include "assemble/main_asm.h"

int main(int argc, void * argv[]){
    
    options main_options;

    main_options = argv_decode(argc, argv); //Do crap with argv and send it back

    bool returncode = displayUsage(main_options.error); //If error is the default value this function will do nothing

    if(!returncode){ //If there was no errors then

        for(uint8 i = 0; i < main_options.file_count; i++){
            printf("%s\n", main_options.files[i]);
        }

        assemble(&main_options);

        if(main_options.use_make = false){ //Make sure we dont leak memory
            free(main_options.gcc_command);
        }
    }

    //Cleanup

    for(uint16 i = 0; i < main_options.file_count; i++){
        free(main_options.files[i]);
    }
    free(main_options.files);

    printf("END OF LINE ...\n");
    return 0;
}