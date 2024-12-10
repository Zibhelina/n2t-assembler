/*
/*returns: machine code instruction as a string*/
decode:
    let machine_instruction = "0000000000000000"
    if instruction[0] == '@':
        // type A instruction
        value = pad_zeros(decimal_to_binary(instruction[1..]))
        machine_instruction = "0" + value
    else:
        // type B instruction
        dest_bits = get_dest_bits(instruction)
        comp_bits = get_comp_bits(instruction)
        jump_bits = get_jump_bits(instruction)
        machine instruction = "111" + comp_bits + dest_bits + jump_bits
    return machine_instruction
/*
input: a string, and an integer
returns: a new string containing the contents of the string input, but with the length matching the provided integer. It pads the string with zeros from left to right.
*/
pad:

/*returns: a 3-bit sequence corresponding to the assembly instruction destination*/
get_dest_bits:
    let dest_bits = "000"
    if is_there_dest(instruction):
        for each ch in instruction:
            if ch == M:
                dest_bits[2] = "1"
            else if ch == D:
                dest_bits[1] = "1"
            else if ch == A:
                dest_bits[0] = "1"
    return dest_bits

/*returns: a 7-bit binary sequence corresponding to the assembly instruction comparison field*/
get_comp_bits:
    let comp_bits = "0000000"
    comp_field_indexes = get_comp_field()
    if comp_field_index[0] == -1:
        return exception
    comp_field_length = comp_field_index[1] - comp_field_index[0]
    if (comp_field_length == 0):

/*returns: a 3-bit binary sequence corresponding to the assembly instruction jump field*/
get_jump_bits:
    let jmp_bits = "000"
    let jmp_field_indexes = get_jmp_field()
    if ()
    return jmp_bits;

/*returns: array containing starting and end indexes of where the destination section is in assembly instruction: [start_index, end_index]. If there is no destination section in the assembly instruction, it will return [-1,-1]*/
get_dest_field:

/*returns: array containing starting and end indexes of where the destination section is in assembly instruction: [start_index, end_index]. If there is no destination section in the assembly instruction, it will return [-1,-1]*/
get_comp_field:

/*returns: array containing starting and end indexes of where the destination section is in assembly instruction: [start_index, end_index]. If there is no destination section in the assembly instruction, it will return [-1,-1]*/
get_jump_field:

/*
returns: true or false depending on whether an equal sign was found in the instruction
*/
is_there_dest:
    for ch in instruction:
        if(ch == '=')
            return true
    return false

/*
C-instructions can be grouped in three:
    * dest = comp; jump
    * comp; jump
    * comp
*/
