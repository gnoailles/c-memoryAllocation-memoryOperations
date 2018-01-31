cmake_minimum_required(VERSION 3.8)
project(malloc_free)

set(CMAKE_CXX_STANDARD 11)

include_directories("includes")

set(SOURCE_FILES
        includes/malloc_custom.h
        src/malloc_custom.c
        src/main.c src/free_custom.c includes/free_custom.h src/memset_custom.c includes/memset_custom.h includes/memdef.h)

add_executable(malloc_free ${SOURCE_FILES})