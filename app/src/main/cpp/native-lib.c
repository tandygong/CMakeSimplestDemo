#include <jni.h>
#include <com_example_gzx_ndk_build_NativeUtils.h>


jint
Java_com_example_gzx_cmakesimplestdemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject jobject1) {
//    std::string hello = "Hello from C++";
    //return env->NewStringUTF(hello.c_str());

    return Java_com_example_gzx_ndk_1build_NativeUtils_getAge(env, jobject1) + 99;
}
