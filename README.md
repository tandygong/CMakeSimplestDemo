# CMakeSimplestDemo
AndroidStudio2.2+ cmake  prebuild-lib
目前出现第三方库不能被native-lib 成功链接问题
xxx/xxx/libndk_build_test.so need by xxx/xxx/native-libs.so,miss and no rule make it

update 1:
已经解决上述问题：
解决方法：
set(libs_DIR ${CMAKE_SOURCE_DIR}/libs)
CmakeLists中，添加perbuild so库:
add libaray()
set_target_properties(ndk_build_test   PROPERTIES IMPORTED_LOCATION  ${libs_DIR}/${ANDROID_ABI}/libndk_build_test.so)

猜想 ：其中libndk_build_test.so文件的位置要相对于CmakeLists的位置，也就是相对于CMAKE_SOURCE_DIR的位置

update 2:
验证1的猜想：
把CMakeLists文件的位置从app/ 文件夹下移动到app/src/main/cpp/ 文件夹下，更新 build.gradle中CMakeLists 的Path
修改CMakeLists:
set(libs_DIR ${CMAKE_SOURCE_DIR}/../../../libs)

关于头文件
include_directories( ${libs_DIR}/include/) 如果用libs/include是无法找到并编译成功的

最后能成功编译运行并验证

总结：在CmakeLists中在所有绝对路径前面都隐式的含有${CMAKE_SOURCE_DIR}，都是在该目录下找文件的，使用相对路径即可

好吧，终于可以用CMake脚本方式编ffmpeg了