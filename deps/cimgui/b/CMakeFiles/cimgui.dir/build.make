# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\mingw64\bin\cmake.exe

# The command to remove a file.
RM = D:\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b

# Include any dependencies generated for this target.
include CMakeFiles/cimgui.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cimgui.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cimgui.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cimgui.dir/flags.make

CMakeFiles/cimgui.dir/cimgui.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/cimgui.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/cimgui.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/cimgui.cpp
CMakeFiles/cimgui.dir/cimgui.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cimgui.dir/cimgui.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/cimgui.cpp.obj -MF CMakeFiles\cimgui.dir\cimgui.cpp.obj.d -o CMakeFiles\cimgui.dir\cimgui.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\cimgui.cpp

CMakeFiles/cimgui.dir/cimgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/cimgui.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\cimgui.cpp > CMakeFiles\cimgui.dir\cimgui.cpp.i

CMakeFiles/cimgui.dir/cimgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/cimgui.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\cimgui.cpp -o CMakeFiles\cimgui.dir\cimgui.cpp.s

CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/imgui/backends/imgui_impl_glfw.cpp
CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj -MF CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_glfw.cpp.obj.d -o CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_glfw.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\backends\imgui_impl_glfw.cpp

CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\backends\imgui_impl_glfw.cpp > CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_glfw.cpp.i

CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\backends\imgui_impl_glfw.cpp -o CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_glfw.cpp.s

CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/imgui/backends/imgui_impl_opengl3.cpp
CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj -MF CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_opengl3.cpp.obj.d -o CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_opengl3.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\backends\imgui_impl_opengl3.cpp

CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\backends\imgui_impl_opengl3.cpp > CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_opengl3.cpp.i

CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\backends\imgui_impl_opengl3.cpp -o CMakeFiles\cimgui.dir\imgui\backends\imgui_impl_opengl3.cpp.s

CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/imgui/imgui.cpp
CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj -MF CMakeFiles\cimgui.dir\imgui\imgui.cpp.obj.d -o CMakeFiles\cimgui.dir\imgui\imgui.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui.cpp

CMakeFiles/cimgui.dir/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/imgui/imgui.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui.cpp > CMakeFiles\cimgui.dir\imgui\imgui.cpp.i

CMakeFiles/cimgui.dir/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/imgui/imgui.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui.cpp -o CMakeFiles\cimgui.dir\imgui\imgui.cpp.s

CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/imgui/imgui_demo.cpp
CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj -MF CMakeFiles\cimgui.dir\imgui\imgui_demo.cpp.obj.d -o CMakeFiles\cimgui.dir\imgui\imgui_demo.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_demo.cpp

CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_demo.cpp > CMakeFiles\cimgui.dir\imgui\imgui_demo.cpp.i

CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_demo.cpp -o CMakeFiles\cimgui.dir\imgui\imgui_demo.cpp.s

CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/imgui/imgui_draw.cpp
CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj -MF CMakeFiles\cimgui.dir\imgui\imgui_draw.cpp.obj.d -o CMakeFiles\cimgui.dir\imgui\imgui_draw.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_draw.cpp

CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_draw.cpp > CMakeFiles\cimgui.dir\imgui\imgui_draw.cpp.i

CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_draw.cpp -o CMakeFiles\cimgui.dir\imgui\imgui_draw.cpp.s

CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/imgui/imgui_tables.cpp
CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj -MF CMakeFiles\cimgui.dir\imgui\imgui_tables.cpp.obj.d -o CMakeFiles\cimgui.dir\imgui\imgui_tables.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_tables.cpp

CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_tables.cpp > CMakeFiles\cimgui.dir\imgui\imgui_tables.cpp.i

CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_tables.cpp -o CMakeFiles\cimgui.dir\imgui\imgui_tables.cpp.s

CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj: CMakeFiles/cimgui.dir/flags.make
CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj: CMakeFiles/cimgui.dir/includes_CXX.rsp
CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj: C:/Vinay/OneDrive/Desktop/Test2DEngine/deps/cimgui/imgui/imgui_widgets.cpp
CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj: CMakeFiles/cimgui.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj -MF CMakeFiles\cimgui.dir\imgui\imgui_widgets.cpp.obj.d -o CMakeFiles\cimgui.dir\imgui\imgui_widgets.cpp.obj -c C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_widgets.cpp

CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_widgets.cpp > CMakeFiles\cimgui.dir\imgui\imgui_widgets.cpp.i

CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\imgui\imgui_widgets.cpp -o CMakeFiles\cimgui.dir\imgui\imgui_widgets.cpp.s

# Object files for target cimgui
cimgui_OBJECTS = \
"CMakeFiles/cimgui.dir/cimgui.cpp.obj" \
"CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj" \
"CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj" \
"CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj" \
"CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj" \
"CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj" \
"CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj" \
"CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj"

# External object files for target cimgui
cimgui_EXTERNAL_OBJECTS =

cimgui.dll: CMakeFiles/cimgui.dir/cimgui.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_glfw.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/imgui/backends/imgui_impl_opengl3.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/imgui/imgui.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/imgui/imgui_demo.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/imgui/imgui_draw.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/imgui/imgui_tables.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/imgui/imgui_widgets.cpp.obj
cimgui.dll: CMakeFiles/cimgui.dir/build.make
cimgui.dll: CMakeFiles/cimgui.dir/linkLibs.rsp
cimgui.dll: CMakeFiles/cimgui.dir/objects1.rsp
cimgui.dll: CMakeFiles/cimgui.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX shared library cimgui.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cimgui.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cimgui.dir/build: cimgui.dll
.PHONY : CMakeFiles/cimgui.dir/build

CMakeFiles/cimgui.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cimgui.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cimgui.dir/clean

CMakeFiles/cimgui.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b C:\Vinay\OneDrive\Desktop\Test2DEngine\deps\cimgui\b\CMakeFiles\cimgui.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cimgui.dir/depend
