# CMake generated Testfile for 
# Source directory: /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/meshing/mesh_s7_8x8_periodic
# Build directory: /Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/meshing/mesh_s7_8x8_periodic
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(full_mesh_8x8_s7_periodic "/usr/local/Cellar/cmake/3.18.4/bin/cmake" "-DMESHDRIVER=/Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/meshing/../../meshing_scripts/create_full_mesh.py" "-DOUTDIR=/Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/buildClang2/tests_cpp/meshing/mesh_s7_8x8_periodic" "-Dnx=8" "-Dny=8" "-Dss=7" "-P" "/Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/meshing/mesh_s7_8x8_periodic/../test2d.cmake")
set_tests_properties(full_mesh_8x8_s7_periodic PROPERTIES  _BACKTRACE_TRIPLES "/Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/meshing/mesh_s7_8x8_periodic/CMakeLists.txt;8;add_test;/Users/fnrizzi/Desktop/work/ROM/gitrepos/pressio-demoapps/tests_cpp/meshing/mesh_s7_8x8_periodic/CMakeLists.txt;0;")
