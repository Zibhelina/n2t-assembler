#include <stdio.h>
#include <regex.h>
#include <stdbool.h>
#include <stdlib.h>

void validate(char* buffer, size_t buffer_length, bool* result) {
    result[0] = false;
    result[1] = false;

    regex_t regex_A;
    if(regcomp(&regex_A, "^(@[0-9]+)$", REG_EXTENDED) != 0) {
        printf("Regular expression A compilation failed\n");
        regfree(&regex_A);
        return;
    }

    regex_t regex_B;
    if(regcomp(&regex_B, "^(((M|D|MD|A|AM|AD|AMD)=)?(0|1|-1|D|A|M|!D|!A|!M|-D|-A|-M|D\\+1|A\\+1|M\\+1|D-1|A-1|M-1|D\\+A|D\\+M|D-A|D-M|A-D|M-D|D&A|D&M|D\\|A|D\\|M)(;(JGT|JEQ|JGE|JLT|JNE|JLE|JMP))?)$", REG_EXTENDED) != 0) {
        printf("Regular expression B compilation failed\n");
        regfree(&regex_A);
        regfree(&regex_B);
        return;
    }

    int check_type_A = regexec(&regex_A, buffer, 0, NULL, 0);
    int check_type_B = regexec(&regex_B, buffer, 0, NULL, 0);
    
    if(check_type_A == 0) {
        result[0] = true;
        result[1] = false;
    }
    else if(check_type_B == 0) {
        result[0] = true;
        result[1] = true;
    }
    
    regfree(&regex_A);
    regfree(&regex_B);
}