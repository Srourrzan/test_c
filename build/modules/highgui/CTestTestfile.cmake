# CMake generated Testfile for 
# Source directory: /workspaces/test_c/image_filter/opencv/modules/highgui
# Build directory: /workspaces/test_c/build/modules/highgui
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_highgui "/workspaces/test_c/build/bin/opencv_test_highgui" "--gtest_output=xml:opencv_test_highgui.xml")
set_tests_properties(opencv_test_highgui PROPERTIES  LABELS "Main;opencv_highgui;Accuracy" WORKING_DIRECTORY "/workspaces/test_c/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/workspaces/test_c/image_filter/opencv/cmake/OpenCVUtils.cmake;1799;add_test;/workspaces/test_c/image_filter/opencv/cmake/OpenCVModule.cmake;1365;ocv_add_test_from_target;/workspaces/test_c/image_filter/opencv/modules/highgui/CMakeLists.txt;311;ocv_add_accuracy_tests;/workspaces/test_c/image_filter/opencv/modules/highgui/CMakeLists.txt;0;")
