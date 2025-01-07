# CMake generated Testfile for 
# Source directory: /workspaces/test_c/image_filter/opencv/modules/ml
# Build directory: /workspaces/test_c/image_filter/build/modules/ml
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_ml "/workspaces/test_c/image_filter/build/bin/opencv_test_ml" "--gtest_output=xml:opencv_test_ml.xml")
set_tests_properties(opencv_test_ml PROPERTIES  LABELS "Main;opencv_ml;Accuracy" WORKING_DIRECTORY "/workspaces/test_c/image_filter/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/workspaces/test_c/image_filter/opencv/cmake/OpenCVUtils.cmake;1799;add_test;/workspaces/test_c/image_filter/opencv/cmake/OpenCVModule.cmake;1365;ocv_add_test_from_target;/workspaces/test_c/image_filter/opencv/cmake/OpenCVModule.cmake;1123;ocv_add_accuracy_tests;/workspaces/test_c/image_filter/opencv/modules/ml/CMakeLists.txt;2;ocv_define_module;/workspaces/test_c/image_filter/opencv/modules/ml/CMakeLists.txt;0;")
