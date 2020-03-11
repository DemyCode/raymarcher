#MAKE

add_subdirectory(light)
add_subdirectory(object)
add_subdirectory(texture)

set(scene_src
        scene.cc
        camera.cc)

add_library(scene ${scene_src})