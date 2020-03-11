 # MAKE

 set(object_src object.cc primitives/box.cc primitives/sphere.cc csg/union.cc csg/intersection.cc)

 add_library(object ${object_src})
