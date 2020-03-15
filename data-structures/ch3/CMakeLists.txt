cmake_minimum_required(VERSION 2.8.9)
project(AlgrithmExercises)

#允许gdb调试
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

# Add the source in project root directory
#aux_source_directory(. DIRSRCS)

#Bring the headers, such as Student.h into the project
include_directories(include)

# Add block directories
#add_subdirectory(lib)

#Can manually add the sources using the set command as follows:
#set(LIB_SOURCES lib/list.c)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB MAIN_SOURCES "main/*.c")
file(GLOB LIB_SOURCES "lib/*.c")
file(GLOB TEST_SOURCES "test/*.c")

add_executable(out ${LIB_SOURCES} ${MAIN_SOURCES} ${TEST_SOURCES})
