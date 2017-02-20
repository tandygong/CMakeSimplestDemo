# CMakeSimplestDemo
AndroidStudio2.2+ cmake  prebuild-lib
目前出现第三方库不能被native-lib 成功链接问题

update 1:
已经解决上述问题：
解决方法：
set(libs_DIR ${CMAKE_SOURCE_DIR}/libs)
CmakeLists中，添加perbuild so库:
add libaray()
set_target_properties(ndk_build_test   PROPERTIES IMPORTED_LOCATION  ${libs_DIR}/${ANDROID_ABI}/libndk_build_test.so)

其中libndk_build_test.so文件的位置要相对于CmakeLists的位置，也就是相对于CMake_SOURCE_Dir的位置