#MAKE

cmake_minimum_required(VERSION 3.0)
project(raymarcher LANGUAGES CXX)
option(BUILD_DEBUG "Build with debug compile options." OFF)
option(BUILD_TEST "Build with the package as well as the tests." OFF)
set(BUILD_SHARED_LIBS ON)


# if (BUILD_DEBUG)
#    add_compile_options(-Wall -Wextra -pedantic  -std=c++17 -g3 -D RAY_DEBUG -fno-inline -O0)
# else()
     add_compile_options(-fopenmp -Wall -Wextra -pedantic -Werror -std=c++17 -O3)
# endif ()

include_directories(src)

add_subdirectory(src)

add_executable(raymarcher src/main.cc)

set(libraries scene parser texture object light utils)
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    set(libraries PUBLIC OpenMP::OpenMP_CXX ${libraries})
endif()

target_link_libraries(raymarcher ${libraries})

if (BUILD_TEST)
    add_subdirectory(tests)
endif (BUILD_TEST)