#pragma once
#include <jni.h>

#ifndef JVM_SYSTEM_H_
#define JVM_SYSTEM_H_

jfieldID getFieldID(JNIEnv*, jobject, const char*, const char*);

jobject getFieldObject(JNIEnv*, jobject, const char*, const char*);
jboolean getFieldBoolean(JNIEnv*, jobject, const char*);
jbyte getFieldByte(JNIEnv*, jobject, const char*);
jshort getFieldShort(JNIEnv*, jobject, const char*);
jint getFieldInt(JNIEnv*, jobject, const char*);
jlong getFieldLong(JNIEnv*, jobject, const char*);
jfloat getFieldFloat(JNIEnv*, jobject, const char*);
jdouble getFieldDouble(JNIEnv*, jobject, const char*);
jchar getFieldChar(JNIEnv*, jobject, const char*);

void setFieldObject(JNIEnv*, jobject, jobject, const char*, const char*);
void setFieldBoolean(JNIEnv*, jobject, jboolean, const char*);
void setFieldByte(JNIEnv*, jobject, jbyte, const char*);
void setFieldShort(JNIEnv*, jobject, jshort, const char*);
void setFieldInt(JNIEnv*, jobject, jint, const char*);
void setFieldLong(JNIEnv*, jobject, jlong, const char*);
void setFieldFloat(JNIEnv*, jobject, jfloat, const char*);
void setFieldDouble(JNIEnv*, jobject, jdouble, const char*);
void setFieldChar(JNIEnv*, jobject, jchar, const char*);

jmethodID getMethodID(JNIEnv*, jobject, const char*, const char*);

jobject createJavaClass(JNIEnv*, jclass, const char*, ...);
jobject createJavaClass(JNIEnv*, jobject, const char*, ...);
jobject createJavaClass(JNIEnv*, const char*, const char*, ...);

jobject createJavaClassV(JNIEnv*, jclass, const char*, va_list);

#endif
