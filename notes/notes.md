`fopen` gets filename as input, the kind of operation we plan on performing with this file, and returns a pointer to a file handler. A file handler is a structure that contains critical information about the file that enable us to manipulate it.

`fgets` is getting a buffer, the buffer size, and the file handler pointer. With this information it's going to populate the buffer we provide with the line it is reading from the file. It's going to continue populating the buffer until the line ends or the size limit is exceeded. Once this is done, it uses the file handler pointer to change one of its internal parameters responsible for keeping track of our current position in the file. So the next time this function is called, it's going to read the next line.

I'm trying to decide which data structure would be best for dealing with the trimmed instruction. I am undecided between using an array versus a linked list.
Using an array makes it easier to access data in O(1), which may be useful in the decoding process, but it has some waste of memory given that most bytes would be unused once trimmed. Using a linked list would cost me the O(1) access that I need for the decoding part, but it would make it less wasteful.

The smallest instruction there is would occupy 2 out of 20 spots in the instruction buffer, so 18 unused places, with each place being 4 bytes (because it's an int buffer), so I would be wasting 18 * 4 bytes = 72 bytes.

How about creating a linked list, O(n), to 

plan 1:
* create an instruction buffer of fixed size - O(1)
* populate the instruction buffer with fgets() - O(?)
* create an populate a new trimmed_instruction buffer - O(n)
* use this buffer for the validation process and decoding process.
// plan 1 is very efficient O(n), but it is not very efficient in terms of the memory usage.
