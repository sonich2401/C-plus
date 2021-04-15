#include <stdio.h>
#include <string.h>
#include "typedefs.h"

#ifndef DATE //To make VS Code happy (No effect on code output)
    #define DATE "NULL"
#endif



//true = THERE IS A ERROR, false = no error :_ ) 
bool displayUsage(char * error){
    bool ret = false;

    if(strcmp(error, "None")){
        printf(
            "C+ Useage:\n"
                "\tc+ -options <arg> [files]\n"
            "~~~~~~~~~~~~~~~\n"
            "Options:\n"
    //            "\t-s <arg>: Supress output\n"
    //                "\t\t g - Supress all gcc console output\n"
    //                "\t\t cp - Supress all C+ console output\n"
      //          "\t-c: Build Cleanup\n"
   //                 "\t\tDon't delete .c files created by c+\n"
                "\t-v <arg (default = 2)>: Verbosity\n"
                    "\t\t[1 - 5]:\n"
                        "\t\t\t1 = Errors only\n"
                        "\t\t\t2 = Errors and Warnings\n"
                        "\t\t\t3 = Option 2 but will prints current process\n"
                        "\t\t\t4 = Option 3 but tells you what file is being processed\n"
                        "\t\t\t5 = Option 4 but tells you everything\n"
    //            "\t-a Makefile Creation\n"
    //                "\t\tAutomaticly attempt to make a makefile based on #include\n"
            "~~~~~~~~~~~~~~~\n"
        );


        ret = true;
    }

    if(strcmp(error, "Help")){//Print the error if there is one
        if(ret != true){return ret;}
        printf(
            "ERROR:\n"
                "\t%s\n" //print error
            "~~~~~~~~~~~~~~~\n"
        , error);
    }else {
        printf("Build Date: %s\n~~~~~~~~~~~~~~~\n", DATE);
    }

    return ret;
}//END OF FUNC