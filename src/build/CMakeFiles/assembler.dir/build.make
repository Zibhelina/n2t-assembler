# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build

# Include any dependencies generated for this target.
include CMakeFiles/assembler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/assembler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/assembler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assembler.dir/flags.make

CMakeFiles/assembler.dir/codegen:
.PHONY : CMakeFiles/assembler.dir/codegen

CMakeFiles/assembler.dir/main.c.o: CMakeFiles/assembler.dir/flags.make
CMakeFiles/assembler.dir/main.c.o: /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/main.c
CMakeFiles/assembler.dir/main.c.o: CMakeFiles/assembler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/assembler.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/assembler.dir/main.c.o -MF CMakeFiles/assembler.dir/main.c.o.d -o CMakeFiles/assembler.dir/main.c.o -c /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/main.c

CMakeFiles/assembler.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/assembler.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/main.c > CMakeFiles/assembler.dir/main.c.i

CMakeFiles/assembler.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/assembler.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/main.c -o CMakeFiles/assembler.dir/main.c.s

CMakeFiles/assembler.dir/linked_list/linked_list.c.o: CMakeFiles/assembler.dir/flags.make
CMakeFiles/assembler.dir/linked_list/linked_list.c.o: /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/linked_list/linked_list.c
CMakeFiles/assembler.dir/linked_list/linked_list.c.o: CMakeFiles/assembler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/assembler.dir/linked_list/linked_list.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/assembler.dir/linked_list/linked_list.c.o -MF CMakeFiles/assembler.dir/linked_list/linked_list.c.o.d -o CMakeFiles/assembler.dir/linked_list/linked_list.c.o -c /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/linked_list/linked_list.c

CMakeFiles/assembler.dir/linked_list/linked_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/assembler.dir/linked_list/linked_list.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/linked_list/linked_list.c > CMakeFiles/assembler.dir/linked_list/linked_list.c.i

CMakeFiles/assembler.dir/linked_list/linked_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/assembler.dir/linked_list/linked_list.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/linked_list/linked_list.c -o CMakeFiles/assembler.dir/linked_list/linked_list.c.s

CMakeFiles/assembler.dir/decode/decode.c.o: CMakeFiles/assembler.dir/flags.make
CMakeFiles/assembler.dir/decode/decode.c.o: /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/decode/decode.c
CMakeFiles/assembler.dir/decode/decode.c.o: CMakeFiles/assembler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/assembler.dir/decode/decode.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/assembler.dir/decode/decode.c.o -MF CMakeFiles/assembler.dir/decode/decode.c.o.d -o CMakeFiles/assembler.dir/decode/decode.c.o -c /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/decode/decode.c

CMakeFiles/assembler.dir/decode/decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/assembler.dir/decode/decode.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/decode/decode.c > CMakeFiles/assembler.dir/decode/decode.c.i

CMakeFiles/assembler.dir/decode/decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/assembler.dir/decode/decode.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/decode/decode.c -o CMakeFiles/assembler.dir/decode/decode.c.s

CMakeFiles/assembler.dir/validate/validate.c.o: CMakeFiles/assembler.dir/flags.make
CMakeFiles/assembler.dir/validate/validate.c.o: /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/validate/validate.c
CMakeFiles/assembler.dir/validate/validate.c.o: CMakeFiles/assembler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/assembler.dir/validate/validate.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/assembler.dir/validate/validate.c.o -MF CMakeFiles/assembler.dir/validate/validate.c.o.d -o CMakeFiles/assembler.dir/validate/validate.c.o -c /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/validate/validate.c

CMakeFiles/assembler.dir/validate/validate.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/assembler.dir/validate/validate.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/validate/validate.c > CMakeFiles/assembler.dir/validate/validate.c.i

CMakeFiles/assembler.dir/validate/validate.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/assembler.dir/validate/validate.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/validate/validate.c -o CMakeFiles/assembler.dir/validate/validate.c.s

# Object files for target assembler
assembler_OBJECTS = \
"CMakeFiles/assembler.dir/main.c.o" \
"CMakeFiles/assembler.dir/linked_list/linked_list.c.o" \
"CMakeFiles/assembler.dir/decode/decode.c.o" \
"CMakeFiles/assembler.dir/validate/validate.c.o"

# External object files for target assembler
assembler_EXTERNAL_OBJECTS =

assembler: CMakeFiles/assembler.dir/main.c.o
assembler: CMakeFiles/assembler.dir/linked_list/linked_list.c.o
assembler: CMakeFiles/assembler.dir/decode/decode.c.o
assembler: CMakeFiles/assembler.dir/validate/validate.c.o
assembler: CMakeFiles/assembler.dir/build.make
assembler: CMakeFiles/assembler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable assembler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assembler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assembler.dir/build: assembler
.PHONY : CMakeFiles/assembler.dir/build

CMakeFiles/assembler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assembler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assembler.dir/clean

CMakeFiles/assembler.dir/depend:
	cd /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build /Users/zibhelina/Documents/vault/knowledge_base/level_2/computer_science/courses/nand2tetris_course/project_06/src/build/CMakeFiles/assembler.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/assembler.dir/depend

