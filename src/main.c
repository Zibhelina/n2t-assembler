#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <regex.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "constants.h"
#include "linked_list/linked_list.h"
#include "validate/validate.h"
#include "decode/decode.h"

const size_t DECODED_INSTRUCTION_BUFFER_SIZE = 16;

int main() {

    FILE *assembly_code = fopen("../craft_table/assembly_code.as", "r");
    FILE *machine_code = fopen("../craft_table/machine_code.as", "w");

    if (assembly_code == NULL) {
        printf("assembly code file could not be opened.");
        return 1;
    }

    if(machine_code == NULL) {
        printf("machine code file could not be opened.");
        fclose(assembly_code);
        return 1;
    }

    int ch;
    bool is_end_of_file = false;
    while ((ch = fgetc(assembly_code)) != EOF) {
        Linked_List linked_list = create_linked_list();

        while(ch != '\n') {
            if(ch == ' ') {
                ch = fgetc(assembly_code);
                continue;
            }
            else if(ch == EOF){
                is_end_of_file = true;
                break;
            }

            linked_list.add_to_end(&linked_list.head, &linked_list.tail, &linked_list.length, (char)ch);
            ch = fgetc(assembly_code);
        }

        // linked list -> array
        size_t instruction_buffer_size = linked_list.length;
        char* instruction_buffer = (char*) calloc(instruction_buffer_size + 1, sizeof(char));
        linked_list.fill_buffer(linked_list.head, instruction_buffer);
        instruction_buffer[instruction_buffer_size] = '\0';
        
        // validate
        bool* validation_result = (bool*) calloc(2, sizeof(bool));
        validate(instruction_buffer, instruction_buffer_size, validation_result);
        bool is_instruction_valid = validation_result[0];
        bool instruction_type = validation_result[1];
        
        if(is_instruction_valid == true) {
            // decode

            char* decoded_instruction_buffer = (char*) malloc((DECODED_INSTRUCTION_BUFFER_SIZE+1) * sizeof(char));
            strcpy(decoded_instruction_buffer, "0000000000000000\0");
            decoding(instruction_buffer, instruction_buffer_size, instruction_type, decoded_instruction_buffer);
            
            fprintf(machine_code, "%s", decoded_instruction_buffer);
            fprintf(machine_code, "\n");

            free(decoded_instruction_buffer);
        }

        free(instruction_buffer);
        free(validation_result);
        linked_list.destroy(&linked_list.head, &linked_list.tail, &linked_list.length);

        if(is_instruction_valid == false) {
            printf("\nSyntax error at instruction: %s", instruction_buffer);
            break;
        }

        if(is_end_of_file == true) {
            break;
        }
    }

    fclose(assembly_code);
    fclose(machine_code);
    
    return 0;
}