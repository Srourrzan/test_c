# CMake generated Testfile for 
# Source directory: /workspaces/test_c/image_filter/opencv/modules/core
# Build directory: /workspaces/test_c/build/modules/core
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_core "/workspaces/test_c/build/bin/opencv_test_core" "--gtest_output=xml:opencv_test_core.xml")
set_tests_properties(opencv_test_core PROPERTIES  LABELS "Main;opencv_core;Accuracy" WORKING_DIRECTORY "/workspaces/test_c/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/workspaces/test_c/image_filter/opencv/cmake/OpenCVUtils.cmake;1799;add_test;/workspaces/test_c/image_filter/opencv/cmake/OpenCVModule.cmake;1365;ocv_add_test_from_target;/workspaces/test_c/image_filter/opencv/modules/core/CMakeLists.txt;205;ocv_add_accuracy_tests;/workspaces/test_c/image_filter/opencv/modules/core/CMakeLists.txt;0;")
add_test(opencv_perf_core "/workspaces/test_c/build/bin/opencv_perf_core" "--gtest_output=xml:opencv_perf_core.xml")
set_tests_properties(opencv_perf_core PROPERTIES  LABELS "Main;opencv_core;Performance" WORKING_DIRECTORY "/workspaces/test_c/build/test-reports/performance" _BACKTRACE_TRIPLES "/workspaces/test_c/image_filter/opencv/cmake/OpenCVUtils.cmake;1799;add_test;/workspaces/test_c/image_filter/opencv/cmake/OpenCVModule.cmake;1264;ocv_add_test_from_target;/workspaces/test_c/image_filter/opencv/modules/core/CMakeLists.txt;206;ocv_add_perf_tests;/workspaces/test_c/image_filter/opencv/modules/core/CMakeLists.txt;0;")
add_test(opencv_sanity_core "/workspaces/test_c/build/bin/opencv_perf_core" "--gtest_output=xml:opencv_perf_core.xml" "--perf_min_samples=1" "--perf_force_samples=1" "--perf_verify_sanity")
set_tests_properties(opencv_sanity_core PROPERTIES  LABELS "Main;opencv_core;Sanity" WORKING_DIRECTORY "/workspaces/test_c/build/test-reports/sanity" _BACKTRACE_TRIPLES "/workspaces/test_c/image_filter/opencv/cmake/OpenCVUtils.cmake;1799;add_test;/workspaces/test_c/image_filter/opencv/cmake/OpenCVModule.cmake;1265;ocv_add_test_from_target;/workspaces/test_c/image_filter/opencv/modules/core/CMakeLists.txt;206;ocv_add_perf_tests;/workspaces/test_c/image_filter/opencv/modules/core/CMakeLists.txt;0;")
