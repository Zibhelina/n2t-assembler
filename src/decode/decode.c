#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#include "decode.h"

void decimal_to_binary(char* decimal_buffer, size_t decimal_buffer_size, char* binary_buffer, size_t binary_buffer_size) {
    // char* -> decimal
    int decimal = 0;
    int exponent = decimal_buffer_size - 1;
    for(int i = 0; i < decimal_buffer_size; i++) {
        decimal += pow(10, exponent) * (int)(decimal_buffer[i]-48);
        exponent--;
    }    

    // decimal -> char*
    int i = binary_buffer_size - 1;
    while(decimal != 0) {
        if(i < 0)
            break;
        
        int remainder = decimal % 2;
        decimal /= 2;
        
        binary_buffer[i] = (char)(remainder + 48);
        i--;
    }
}

void decode_dest_field(char* dest_buffer, size_t dest_buffer_size, char* decoded_intruction_buffer, size_t dest_offset) {
    for(size_t i = 0; i < dest_buffer_size; i++) {
        if(dest_buffer[i] == 'A') {
            decoded_intruction_buffer[dest_offset + 0] = '1';
        } else if(dest_buffer[i] == 'M') {
            decoded_intruction_buffer[dest_offset + 1] = '1';
        } else if(dest_buffer[i] == 'D'){
            decoded_intruction_buffer[dest_offset + 2] = '1';
        }
    }
}

void decode_comp_field(char* comp_buffer, size_t comp_buffer_size, char* decoded_instruction_buffer, size_t comp_offset) {
    if(comp_buffer_size == 1) {
            if(comp_buffer[0] == '0') {
                decoded_instruction_buffer[comp_offset + 0] = '0';
                decoded_instruction_buffer[comp_offset + 1] = '1';
                decoded_instruction_buffer[comp_offset + 2] = '0';
                decoded_instruction_buffer[comp_offset + 3] = '1';
                decoded_instruction_buffer[comp_offset + 4] = '0';
                decoded_instruction_buffer[comp_offset + 5] = '1';
                decoded_instruction_buffer[comp_offset + 6] = '0';
            } else if(comp_buffer[0] == '1') {
                decoded_instruction_buffer[comp_offset + 0] = '0';
                decoded_instruction_buffer[comp_offset + 1] = '1';
                decoded_instruction_buffer[comp_offset + 2] = '1';
                decoded_instruction_buffer[comp_offset + 3] = '1';
                decoded_instruction_buffer[comp_offset + 4] = '1';
                decoded_instruction_buffer[comp_offset + 5] = '1';
                decoded_instruction_buffer[comp_offset + 6] = '1';
            } else if(comp_buffer[0] == 'A') {
                decoded_instruction_buffer[comp_offset + 0] = '0';
                decoded_instruction_buffer[comp_offset + 1] = '1';
                decoded_instruction_buffer[comp_offset + 2] = '1';
                decoded_instruction_buffer[comp_offset + 3] = '0';
                decoded_instruction_buffer[comp_offset + 4] = '0';
                decoded_instruction_buffer[comp_offset + 5] = '0';
                decoded_instruction_buffer[comp_offset + 6] = '0';
            } else if(comp_buffer[0] == 'M') {
                decoded_instruction_buffer[comp_offset + 0] = '1';
                decoded_instruction_buffer[comp_offset + 1] = '1';
                decoded_instruction_buffer[comp_offset + 2] = '1';
                decoded_instruction_buffer[comp_offset + 3] = '0';
                decoded_instruction_buffer[comp_offset + 4] = '0';
                decoded_instruction_buffer[comp_offset + 5] = '0';
                decoded_instruction_buffer[comp_offset + 6] = '0';
            } else if(comp_buffer[0] == 'D') {
                decoded_instruction_buffer[comp_offset + 0] = '0';
                decoded_instruction_buffer[comp_offset + 1] = '0';
                decoded_instruction_buffer[comp_offset + 2] = '0';
                decoded_instruction_buffer[comp_offset + 3] = '1';
                decoded_instruction_buffer[comp_offset + 4] = '1';
                decoded_instruction_buffer[comp_offset + 5] = '0';
                decoded_instruction_buffer[comp_offset + 6] = '0';
            }
        } else if (comp_buffer_size == 2) {
            if(comp_buffer[0] == '-') {
                if(comp_buffer[1] == '1') {
                    decoded_instruction_buffer[comp_offset + 0] = '0';
                    decoded_instruction_buffer[comp_offset + 1] = '1';
                    decoded_instruction_buffer[comp_offset + 2] = '1';
                    decoded_instruction_buffer[comp_offset + 3] = '1';
                    decoded_instruction_buffer[comp_offset + 4] = '0';
                    decoded_instruction_buffer[comp_offset + 5] = '1';
                    decoded_instruction_buffer[comp_offset + 6] = '0';
                } else if(comp_buffer[1] == 'A') {
                    decoded_instruction_buffer[comp_offset + 0] = '0';
                    decoded_instruction_buffer[comp_offset + 1] = '1';
                    decoded_instruction_buffer[comp_offset + 2] = '1';
                    decoded_instruction_buffer[comp_offset + 3] = '0';
                    decoded_instruction_buffer[comp_offset + 4] = '0';
                    decoded_instruction_buffer[comp_offset + 5] = '0';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                } else if(comp_buffer[1] == 'M') {
                    decoded_instruction_buffer[comp_offset + 0] = '1';
                    decoded_instruction_buffer[comp_offset + 1] = '1';
                    decoded_instruction_buffer[comp_offset + 2] = '1';
                    decoded_instruction_buffer[comp_offset + 3] = '0';
                    decoded_instruction_buffer[comp_offset + 4] = '0';
                    decoded_instruction_buffer[comp_offset + 5] = '0';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                } else if(comp_buffer[1] == 'D') {
                    decoded_instruction_buffer[comp_offset + 0] = '0';
                    decoded_instruction_buffer[comp_offset + 1] = '0';
                    decoded_instruction_buffer[comp_offset + 2] = '0';
                    decoded_instruction_buffer[comp_offset + 3] = '1';
                    decoded_instruction_buffer[comp_offset + 4] = '1';
                    decoded_instruction_buffer[comp_offset + 5] = '1';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                }
            } else if(comp_buffer[0] == '!') {
                if(comp_buffer[1] == 'A') {
                    decoded_instruction_buffer[comp_offset + 0] = '0';
                    decoded_instruction_buffer[comp_offset + 1] = '1';
                    decoded_instruction_buffer[comp_offset + 2] = '1';
                    decoded_instruction_buffer[comp_offset + 3] = '0';
                    decoded_instruction_buffer[comp_offset + 4] = '0';
                    decoded_instruction_buffer[comp_offset + 5] = '0';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                } else if(comp_buffer[1] == 'M') {
                    decoded_instruction_buffer[comp_offset + 0] = '1';
                    decoded_instruction_buffer[comp_offset + 1] = '1';
                    decoded_instruction_buffer[comp_offset + 2] = '1';
                    decoded_instruction_buffer[comp_offset + 3] = '0';
                    decoded_instruction_buffer[comp_offset + 4] = '0';
                    decoded_instruction_buffer[comp_offset + 5] = '0';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                } else if(comp_buffer[1] == 'D') {
                    decoded_instruction_buffer[comp_offset + 0] = '0';
                    decoded_instruction_buffer[comp_offset + 1] = '0';
                    decoded_instruction_buffer[comp_offset + 2] = '0';
                    decoded_instruction_buffer[comp_offset + 3] = '1';
                    decoded_instruction_buffer[comp_offset + 4] = '1';
                    decoded_instruction_buffer[comp_offset + 5] = '0';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                }
            }
        } else if (comp_buffer_size == 3) {
            if(comp_buffer[0] == 'A') {
                if(comp_buffer[1] == '+') {
                    decoded_instruction_buffer[comp_offset + 0] = '0';
                    decoded_instruction_buffer[comp_offset + 1] = '1';
                    decoded_instruction_buffer[comp_offset + 2] = '1';
                    decoded_instruction_buffer[comp_offset + 3] = '0';
                    decoded_instruction_buffer[comp_offset + 4] = '1';
                    decoded_instruction_buffer[comp_offset + 5] = '1';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                } else if(comp_buffer[1] == '-') {
                    if(comp_buffer[2] == '1') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '1';
                        decoded_instruction_buffer[comp_offset + 2] = '1';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '0';
                    } else if(comp_buffer[2] == 'D') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '0';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '1';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '1';
                    }
                }
            } else if(comp_buffer[0] == 'M') {
                if(comp_buffer[1] == '+') {
                    decoded_instruction_buffer[comp_offset + 0] = '1';
                    decoded_instruction_buffer[comp_offset + 1] = '1';
                    decoded_instruction_buffer[comp_offset + 2] = '1';
                    decoded_instruction_buffer[comp_offset + 3] = '0';
                    decoded_instruction_buffer[comp_offset + 4] = '1';
                    decoded_instruction_buffer[comp_offset + 5] = '1';
                    decoded_instruction_buffer[comp_offset + 6] = '1';
                } else if(comp_buffer[1] == '-') {
                    if(comp_buffer[2] == '1') {
                        decoded_instruction_buffer[comp_offset + 0] = '1';
                        decoded_instruction_buffer[comp_offset + 1] = '1';
                        decoded_instruction_buffer[comp_offset + 2] = '1';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '0';
                    } else if(comp_buffer[2] == 'D') {
                        decoded_instruction_buffer[comp_offset + 0] = '1';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '0';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '1';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '1';
                    }
                }
            } else if(comp_buffer[0] == 'D') {
                if(comp_buffer[1] == '+') {
                    if(comp_buffer[2] == '1') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '1';
                        decoded_instruction_buffer[comp_offset + 3] = '1';
                        decoded_instruction_buffer[comp_offset + 4] = '1';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '1';
                    } else if(comp_buffer[2] == 'A') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '0';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '0';
                    } else if(comp_buffer[2] == 'M') {
                        decoded_instruction_buffer[comp_offset + 0] = '1';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '0';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '0';
                    }
                } else if(comp_buffer[1] == '-') {
                    if(comp_buffer[2] == '1') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '0';
                        decoded_instruction_buffer[comp_offset + 3] = '1';
                        decoded_instruction_buffer[comp_offset + 4] = '1';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '0';
                    } else if(comp_buffer[2] == 'A') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '1';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '1';
                    } else if(comp_buffer[2] == 'M') {
                        decoded_instruction_buffer[comp_offset + 0] = '1';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '1';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '1';
                        decoded_instruction_buffer[comp_offset + 6] = '1';
                    }
                } else if(comp_buffer[1] == '&') {
                    if(comp_buffer[2] == 'A') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '0';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '0';
                        decoded_instruction_buffer[comp_offset + 6] = '0';
                    } else if(comp_buffer[2] == 'M') {
                        decoded_instruction_buffer[comp_offset + 0] = '1';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '0';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '0';
                        decoded_instruction_buffer[comp_offset + 5] = '0';
                        decoded_instruction_buffer[comp_offset + 6] = '0';
                    }
                } else if(comp_buffer[1] == '|') {
                    if(comp_buffer[2] == 'A') {
                        decoded_instruction_buffer[comp_offset + 0] = '0';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '1';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '1';
                        decoded_instruction_buffer[comp_offset + 5] = '0';
                        decoded_instruction_buffer[comp_offset + 6] = '1';
                    } else if(comp_buffer[2] == 'M') {
                        decoded_instruction_buffer[comp_offset + 0] = '1';
                        decoded_instruction_buffer[comp_offset + 1] = '0';
                        decoded_instruction_buffer[comp_offset + 2] = '1';
                        decoded_instruction_buffer[comp_offset + 3] = '0';
                        decoded_instruction_buffer[comp_offset + 4] = '1';
                        decoded_instruction_buffer[comp_offset + 5] = '0';
                        decoded_instruction_buffer[comp_offset + 6] = '1';
                    }
                }
            }
        }
}

void decode_jump_field(char* jump_buffer, char* decoded_intruction_buffer, size_t jump_offset) {
    if(jump_buffer[1] == 'G' && jump_buffer[2] == 'T') {
        decoded_intruction_buffer[jump_offset + 0] = 0;
        decoded_intruction_buffer[jump_offset + 1] = 0;
        decoded_intruction_buffer[jump_offset + 2] = 1;
        printf("%s", decoded_intruction_buffer);
    } else if (jump_buffer[1] == 'E' && jump_buffer[2] == 'Q') {
        decoded_intruction_buffer[jump_offset + 0] = 0;
        decoded_intruction_buffer[jump_offset + 1] = 1;
        decoded_intruction_buffer[jump_offset + 2] = 0;
    } else if (jump_buffer[1] == 'G' && jump_buffer[2] == 'E') {
        decoded_intruction_buffer[jump_offset + 0] = 0;
        decoded_intruction_buffer[jump_offset + 1] = 1;
        decoded_intruction_buffer[jump_offset + 2] = 1;
    } else if (jump_buffer[1] == 'L' && jump_buffer[2] == 'T') {
        decoded_intruction_buffer[jump_offset + 0] = 1;
        decoded_intruction_buffer[jump_offset + 1] = 0;
        decoded_intruction_buffer[jump_offset + 2] = 0;
    } else if (jump_buffer[1] == 'N' && jump_buffer[2] == 'E') {
        decoded_intruction_buffer[jump_offset + 0] = 1;
        decoded_intruction_buffer[jump_offset + 1] = 0;
        decoded_intruction_buffer[jump_offset + 2] = 1;
    } else if (jump_buffer[1] == 'L' && jump_buffer[2] == 'E') {
        decoded_intruction_buffer[jump_offset + 0] = 1;
        decoded_intruction_buffer[jump_offset + 1] = 1;
        decoded_intruction_buffer[jump_offset + 2] = 0;
    } else if (jump_buffer[1] == 'M' && jump_buffer[2] == 'P') {
        decoded_intruction_buffer[jump_offset + 0] = 1;
        decoded_intruction_buffer[jump_offset + 1] = 1;
        decoded_intruction_buffer[jump_offset + 2] = 1;
    }
}

void decoding(char* instruction_buffer, size_t intruction_buffer_size, bool instruction_type, char* decoded_intruction_buffer) {
    if(instruction_type == false) {
        // instruction type A
        decoded_intruction_buffer[0] = '0';
        char* decimal_buffer = instruction_buffer + 1;
        size_t decimal_buffer_size = intruction_buffer_size - 1;
        char* binary_buffer = decoded_intruction_buffer + 1;
        size_t binary_buffer_size = DECODED_INSTRUCTION_BUFFER_SIZE - 1;
        decimal_to_binary(decimal_buffer, decimal_buffer_size, binary_buffer, binary_buffer_size);
    } else {
        // instruction type B
        //strcpy(decoded_intruction_buffer, "111");
        decoded_intruction_buffer[0] = '1';
        decoded_intruction_buffer[1] = '1';
        decoded_intruction_buffer[2] = '1';
        
        // find which fields are contained in the instruction
        bool field_tracker[2] = {false, false};
        bool dest_flag = true;
        bool comp_flag = true;
        bool jump_flag = false;

        size_t max_field_size = 3;
        
        char* dest_buffer = malloc(sizeof(char) * max_field_size);
        char* comp_buffer = malloc(sizeof(char) * max_field_size);
        char* jump_buffer = malloc(sizeof(char) * max_field_size);

        size_t dest_index, comp_index, jump_index;
        dest_index = comp_index = jump_index = 0;

        for(size_t i = 0; i < intruction_buffer_size; i++) {
            switch(instruction_buffer[i]) {
                case '=':
                    field_tracker[0] = true;
                    dest_flag = false;
                    comp_index = 0;
                    continue;
                case ';':
                    field_tracker[1] = true;
                    comp_flag = false;
                    jump_flag = true;
                    jump_index = 0;
                    continue;
            }
            if(dest_flag == true && comp_flag == true) {
                dest_buffer[dest_index] = instruction_buffer[i];
                comp_buffer[comp_index] = instruction_buffer[i];
                dest_index++;
                comp_index++;
            }
            else if(comp_flag == true) {
                comp_buffer[comp_index] = instruction_buffer[i];
                comp_index++;
                //printf("\nafter increment comp index: %zu\n", comp_index);
            } else {
                jump_buffer[jump_index] = instruction_buffer[i];
                jump_index++;
            }
        }
        
        // instruction type B1 - 00 -      comp
        // instruction type B2 - 01 -      comp;jump
        // instruction type B3 - 10 - dest=comp
        // instruction type B4 - 11 - dest=comp;jump

        size_t dest_buffer_size, comp_buffer_size, jump_buffer_size;
        dest_buffer_size = dest_index;
        comp_buffer_size = comp_index;
        jump_buffer_size = jump_index;

        // compute comp
        if(field_tracker[0] == true) {
            size_t dest_offset = 10;
            decode_dest_field(dest_buffer, dest_buffer_size, decoded_intruction_buffer, dest_offset);
        }
        if(field_tracker[1] == true) {
            size_t jump_offset = 13;
            decode_jump_field(jump_buffer, decoded_intruction_buffer, jump_offset);   
        }
        
        size_t comp_offset = 3;
        decode_comp_field(comp_buffer, comp_buffer_size, decoded_intruction_buffer, comp_offset);

        /*
        if(field_tracker[0] == false) {
            // B1 or B2
            if(field_tracker[1] == false) {
                // B1
                printf("\ncomp index: %zu\n", comp_index);
                printf("\ncomp buffer: %s\n", comp_buffer);
            } else {
                // B2
                
                printf("\ncomp index: %zu\n", comp_index);
                printf("\njump index: %zu\n", jump_index);
                printf("\ncomp buffer: %s\n", comp_buffer);
                printf("\njump buffer: %s\n", jump_buffer);
            }
        } else {
            if(field_tracker[1] == false) {
                // B3

                printf("\ndest index: %zu\n", dest_index);
                printf("\ncomp index: %zu\n", comp_index);
                printf("\ndest buffer: %s\n", dest_buffer);
                printf("\ncomp buffer: %s\n", comp_buffer);
            } else {
                // B4

                printf("\ndest index: %zu\n", dest_index);
                printf("\ncomp index: %zu\n", comp_index);
                printf("\njump index: %zu\n", jump_index);
                printf("\ndest buffer: %s\n", dest_buffer);
                printf("\ncomp buffer: %s\n", comp_buffer);
                printf("\njump buffer: %s\n", jump_buffer);
            }
        }
        */

        free(dest_buffer);
        free(comp_buffer);
        free(jump_buffer);
    }
}
