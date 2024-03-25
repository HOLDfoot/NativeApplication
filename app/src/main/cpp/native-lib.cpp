#include <jni.h>

#include <string>
#include <android/log.h>

#define LOG_TAG  "C_TAG"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG ,__VA_ARGS__) // 定义LOGI类型

extern "C" {
#include <libavcodec/avcodec.h>
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativeapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    /*  std::string hello = "Hello from C++";
      return env->NewStringUTF(hello.c_str());*/
    //std::string hello = "avcodec configuration info ";
    std::string config = avcodec_configuration();

    LOGI("configuration %s\n", config.c_str());

    return env->NewStringUTF(config.c_str());
}