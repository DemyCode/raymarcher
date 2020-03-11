#MAKE

add_subdirectory(parser)

set(utils_src
        vector3.cc vertex.cc
        color.cc
        image.cc
        ray.cc)

add_library(utils ${utils_src})