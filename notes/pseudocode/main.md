# Difficulty level 1:

* This involves translating a simplified version of assembly code to machine language.
* It is said to be simplified because it does not handle symbols
* The algorithm for implementing this simple assembler is something like this:

main:
    open_file(assembly_code)
    open_file(machine_code)
    if(assembly_code || machine_code did not open successfully):
        raise_error("files could not be open.")
    for each instruction in assembly_code:
        trimmed_instruction = trim(instruction) /*trim removes white spaces and comments*/
        if(validate(trimmed_instruction))
            validated_instruction = trimmed_instruction
            decoded_instruction = decode(validated_instruction)
            machine_code.push(decoded_instruction)
        else
            raise_error("invalid instruction: {instruction}")
    close_file(assembly_code)
    close_file(machine_code)