#ifndef DECODE_H
#define DECODE_H

#include "../constants.h"
#include <stddef.h>

void decimal_to_binary(char* decimal_buffer, size_t decimal_buffer_size, char* binary_buffer, size_t binary_buffer_size);
void decode_dest_field(char* dest_buffer, size_t dest_buffer_size, char* decoded_intruction_buffer, size_t dest_offset);
void decode_comp_field(char* comp_buffer, size_t comp_buffer_size, char* decoded_instruction_buffer, size_t comp_offset);
void decode_jump_field(char* jump_buffer, char* decoded_intruction_buffer, size_t jump_offset);
void decoding(char* instruction_buffer, size_t intruction_buffer_size, bool instruction_type, char* decoded_intruction_buffer);

#endif