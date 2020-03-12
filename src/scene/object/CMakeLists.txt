 # MAKE

 set(object_src object.cc primitives/box.cc primitives/sphere.cc primitives/plane.cc
         csg/union.cc csg/intersection.cc csg/smoothunion.cc csg/difference.cc)

 add_library(object ${object_src})
