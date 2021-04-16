#include "argv.h"

const string useage_errors[] = {
    "No arguments!",
    "No valid GCC command!",
    "Not enough arguments!",
    "Invalid Argument!",
    "[1-5] is the only valid -v range!",
    "Help"
};

void init_options(options * o){
    o->auto_make = false;
    o->delete_c =  true;
    o->use_make = false;
    o->supress = 0;
    o->verb = 2;
    o->error = "None";
    o->gcc_command = "ERROR";
}

options argv_decode(int argc, void * argv[]){
    string * argv_s = (string *)argv;

    options ret;
    init_options(&ret);

    if(argc < 2){ //Error checking
        ret.error = malloc(strlen(useage_errors[2]) + 1);
        memcpy(ret.error, useage_errors[2], strlen(useage_errors[2]) + 1);
        return ret;
    }

    if(argv_s[1][0] == '-' && argv_s[1][1] == 'h'){ //Display the help message
    printf("Here\n");
        ret.error = malloc(strlen(useage_errors[5]) + 1);
        memcpy(ret.error, useage_errors[5], strlen(useage_errors[5]) + 1);
        return ret;
    }


    int cur_arg;
    for(cur_arg = 1; cur_arg < argc; cur_arg++){ //Iterate through all args
        if(argv_s[cur_arg][0] == '-'){ //Is the current arg a option?
            //Auto make
            if(argv_s[cur_arg][1] == 'a'){
                ret.auto_make = true;
                continue;
            }

            //Veribose output
            if(argv_s[cur_arg][1] == 'v'){
                cur_arg++; //Check for the option they entered
                ret.verb = stoi(argv_s[cur_arg]);
                if(ret.verb < 1 || ret.verb > 5){ //Check for errors
                    ret.error = malloc(strlen(useage_errors[4]) + 1);
                    memcpy(ret.error, useage_errors[4], strlen(useage_errors[4]) + 1);
                    return ret; //Return the errors
                }
                continue;
            }

                //Clean build
            if(argv_s[cur_arg][1] == 'c'){
                ret.delete_c = false;
                continue;
            }


            //SetDirectory


            //Supress errors
            if(argv_s[cur_arg][1] == 's'){
                cur_arg++; //Check for the option they entered
                ret.supress += (argv_s[cur_arg][0] == 'c');
                ret.supress += (argv_s[cur_arg][0] == 'g');
                if((argv_s[cur_arg][0] != 'c') && (argv_s[cur_arg][0] != 'g')){ //Check for errors
                    ret.error = malloc(strlen(useage_errors[3]) + 1);
                    memcpy(ret.error, useage_errors[3], strlen(useage_errors[3]) + 1);
                    return ret; //Return the function with the error
                }
                continue;
            }
        }//END OF OPTION CHECK


        //GCC CHECK
        /*if(argv_s[cur_arg][0] == 'g' && argv_s[cur_arg][1] =='c'){ //Check if we are begining the GCC command
            break;
        }else if(argv_s[cur_arg][0] == 'M' || argv_s[cur_arg][0] == 'm'){ //Check if we are accepting a makefile
            if(argv_s[cur_arg][1] == 'a'){
                ret.use_make = true;
                ret.gcc_command = argv_s[cur_arg];
                break;
            }else{ //ERROR
                ret.error = malloc(strlen(useage_errors[1]) + 1);
                memcpy(ret.error, useage_errors[1], strlen(useage_errors[1]) + 1);
                return ret; 
            }
        }//END OF GCC CHECK
        */  //Decided this functionality could be removed due to OS complexity

        //Check for file def
        if(rfind(argv_s[cur_arg],".cp",0) | rfind(argv_s[cur_arg],".hp",0) != -1){
            
            break; //Get out of for loop
        }


    }//END OF FOR LOOP


/*
    //ADD GCC STRING IN
    if(ret.use_make == false){
        ret.gcc_command = malloc(300);
        for(int i = cur_arg; i < argc - 1; i++){
            //printf("DEBUG: %s\n", argv_s[i]);
            sprintf(ret.gcc_command, "%s%s ",ret.gcc_command, argv_s[i]);
        }
       //printf("DEBUG: %s\n", argv_s[argc-1]);
        sprintf(ret.gcc_command, "%s%s",ret.gcc_command, argv_s[argc - 1]);
    }
    */


    //Add files to the list

    ret.file_count = argc - cur_arg;
    if(ret.file_count > 0){
        ret.files = malloc(ret.file_count * sizeof(string));
        for(uint16 i = 0; i < ret.file_count; i++){
            ret.files[i] = malloc(strlen(argv_s[cur_arg + i])+1);
            strcpy(ret.files[i],argv_s[cur_arg + i]);
        }
    }


    return ret;
}