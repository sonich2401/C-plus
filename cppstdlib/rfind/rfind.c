#include "rfind.h"
uint32 rfind(string src, string find, uint32 offset)
{
    uint32 src_len = strlen(src);
    uint32 find_len = strlen(find);

    for(uint32 pos = 0 ; pos < src_len; pos++){
        char * next_pos = strchr(src, find[0]); //Search for starting of the word in string * find
        uint32 index_nex_pos = next_pos - src; // subtract offsets to get index
        if(next_pos != NULL){ //if the char is found
            //Check if proceeding letters are a match
            for(uint32 find_pos = 0; find_pos < find_len && index_nex_pos + find_pos < src_len; find_pos++){
                if(src[find_pos + index_nex_pos] != find[find_pos]){
                    return -1; //It wasnt a perfect match :(
                }
            }
            //If we didn't return from the for loop then its a match
            return index_nex_pos;
        }
    }
    return -1; //Default
}