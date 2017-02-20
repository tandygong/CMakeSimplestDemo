
cmake_minimum_required(VERSION 3.4.1)

set(libs_DIR ${CMAKE_SOURCE_DIR}/../../../libs)

include_directories( ${libs_DIR}/include/)

add_library( native-lib
             SHARED
             ${CMAKE_SOURCE_DIR}/native-lib.c )

find_library( # Sets the name of the path variable.
              log-lib
              log )

add_library( ndk_build_test  SHARED  IMPORTED )
set_target_properties(ndk_build_test   PROPERTIES IMPORTED_LOCATION  ${libs_DIR}/${ANDROID_ABI}/libndk_build_test.so)



target_link_libraries( # Specifies the target library.
                        native-lib
                        ndk_build_test
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
