# Install script for directory: /workspaces/test_c/image_filter/opencv

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "ippicv-readme.htm" FILES "/workspaces/test_c/build/3rdparty/ippicv/ippicv_lnx/icv/readme.htm")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "ippicv-EULA.txt" FILES "/workspaces/test_c/build/3rdparty/ippicv/ippicv_lnx/EULA.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "ippicv-third-party-programs.txt" FILES "/workspaces/test_c/build/3rdparty/ippicv/ippicv_lnx/third-party-programs.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "ippiw-support.txt" FILES "/workspaces/test_c/build/3rdparty/ippicv/ippicv_lnx/icv/../iw/../support.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "ippiw-third-party-programs.txt" FILES "/workspaces/test_c/build/3rdparty/ippicv/ippicv_lnx/icv/../iw/../third-party-programs.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "ippiw-EULA.txt" FILES "/workspaces/test_c/build/3rdparty/ippicv/ippicv_lnx/icv/../iw/../EULA.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "flatbuffers-LICENSE.txt" FILES "/workspaces/test_c/image_filter/opencv/3rdparty/flatbuffers/LICENSE.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "opencl-headers-LICENSE.txt" FILES "/workspaces/test_c/image_filter/opencv/3rdparty/include/opencl/LICENSE.txt")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlicensesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/licenses/opencv4" TYPE FILE RENAME "ade-LICENSE" FILES "/workspaces/test_c/build/3rdparty/ade/ade-0.1.2e/LICENSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv4/opencv2" TYPE FILE FILES "/workspaces/test_c/build/cvconfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv4/opencv2" TYPE FILE FILES "/workspaces/test_c/build/opencv2/opencv_modules.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/opencv4/OpenCVModules.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/opencv4/OpenCVModules.cmake"
         "/workspaces/test_c/build/CMakeFiles/Export/lib/cmake/opencv4/OpenCVModules.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/opencv4/OpenCVModules-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/opencv4/OpenCVModules.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/opencv4" TYPE FILE FILES "/workspaces/test_c/build/CMakeFiles/Export/lib/cmake/opencv4/OpenCVModules.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/opencv4" TYPE FILE FILES "/workspaces/test_c/build/CMakeFiles/Export/lib/cmake/opencv4/OpenCVModules-debug.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/opencv4" TYPE FILE FILES
    "/workspaces/test_c/build/unix-install/OpenCVConfig-version.cmake"
    "/workspaces/test_c/build/unix-install/OpenCVConfig.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xscriptsx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE FILES "/workspaces/test_c/build/CMakeFiles/install/setup_vars_opencv4.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdevx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/opencv4" TYPE FILE FILES
    "/workspaces/test_c/image_filter/opencv/platforms/scripts/valgrind.supp"
    "/workspaces/test_c/image_filter/opencv/platforms/scripts/valgrind_3rdparty.supp"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/workspaces/test_c/build/3rdparty/libjpeg-turbo/cmake_install.cmake")
  include("/workspaces/test_c/build/3rdparty/libtiff/cmake_install.cmake")
  include("/workspaces/test_c/build/3rdparty/libwebp/cmake_install.cmake")
  include("/workspaces/test_c/build/3rdparty/openjpeg/cmake_install.cmake")
  include("/workspaces/test_c/build/3rdparty/openexr/cmake_install.cmake")
  include("/workspaces/test_c/build/3rdparty/ippiw/cmake_install.cmake")
  include("/workspaces/test_c/build/3rdparty/protobuf/cmake_install.cmake")
  include("/workspaces/test_c/build/3rdparty/ittnotify/cmake_install.cmake")
  include("/workspaces/test_c/build/include/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/calib3d/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/core/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/dnn/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/features2d/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/flann/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/gapi/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/highgui/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/imgcodecs/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/imgproc/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/java/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/js/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/ml/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/objc/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/objdetect/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/photo/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/python/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/stitching/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/ts/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/video/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/videoio/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/.firstpass/world/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/core/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/flann/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/imgproc/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/ml/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/photo/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/python_tests/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/dnn/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/features2d/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/imgcodecs/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/videoio/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/calib3d/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/highgui/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/objdetect/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/stitching/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/ts/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/video/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/gapi/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/java_bindings_generator/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/js_bindings_generator/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/objc_bindings_generator/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/python_bindings_generator/cmake_install.cmake")
  include("/workspaces/test_c/build/modules/java/cmake_install.cmake")
  include("/workspaces/test_c/build/doc/cmake_install.cmake")
  include("/workspaces/test_c/build/data/cmake_install.cmake")
  include("/workspaces/test_c/build/apps/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/workspaces/test_c/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
