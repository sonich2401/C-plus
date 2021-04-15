#include  <stdio.h>

#include "useage.h"
#include "argv.h"

#include "assemble/main_asm.h"

int main(int argc, void * argv[]){
    options main_options;

    main_options = argv_decode(argc, argv); //Do crap with argv and send it back

    bool returncode = displayUsage(main_options.error); //If error is the default value this function will do nothing

    if(!returncode){ //If there was no errors then proceed



        if(main_options.use_make = false){ //Make sure we dont leak memory
            free(main_options.gcc_command);
        }
    }
    printf("END OF LINE ...\n");
    return 0;
}