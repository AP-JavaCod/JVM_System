#pragma once
#include <jni.h>

#ifndef JVM_SYSTEM_H_
#define JVM_SYSTEM_H_

namespace field {

	jfieldID getFieldID(JNIEnv*, jobject, const char*, const char*);

	jobject getObject(JNIEnv*, jobject, const char*, const char*);
	jboolean getBoolean(JNIEnv*, jobject, const char*);
	jbyte getByte(JNIEnv*, jobject, const char*);
	jshort getShort(JNIEnv*, jobject, const char*);
	jint getInt(JNIEnv*, jobject, const char*);
	jlong getLong(JNIEnv*, jobject, const char*);
	jfloat getFloat(JNIEnv*, jobject, const char*);
	jdouble getDouble(JNIEnv*, jobject, const char*);
	jchar getChar(JNIEnv*, jobject, const char*);

	void setObject(JNIEnv*, jobject, jobject, const char*, const char*);
	void setBoolean(JNIEnv*, jobject, jboolean, const char*);
	void setByte(JNIEnv*, jobject, jbyte, const char*);
	void setShort(JNIEnv*, jobject, jshort, const char*);
	void setInt(JNIEnv*, jobject, jint, const char*);
	void setLong(JNIEnv*, jobject, jlong, const char*);
	void setFloat(JNIEnv*, jobject, jfloat, const char*);
	void setDouble(JNIEnv*, jobject, jdouble, const char*);
	void setChar(JNIEnv*, jobject, jchar, const char*);

}

namespace method {

	void callStaticVoidMethod(JNIEnv*, jclass, const char*, const char* ...);
	void callStaticVoidMethod(JNIEnv*, jobject, const char*, const char*, ...);
	void callStaticVoidMethod(JNIEnv*, const char*, const char*, const char*, ...);
	void callStaticVoidMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jobject callStaticObjectMethod(JNIEnv*, jclass, const char*, const char* ...);
	jobject callStaticObjectMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jobject callStaticObjectMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jobject callStaticObjectMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jboolean callStaticBooleanMethod(JNIEnv*, jclass, const char*, const char* ...);
	jboolean callStaticBooleanMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jboolean callStaticBooleanMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jboolean callStaticBooleanMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jbyte callStaticByteMethod(JNIEnv*, jclass, const char*, const char* ...);
	jbyte callStaticByteMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jbyte callStaticByteMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jbyte callStaticByteMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jshort callStaticShortMethod(JNIEnv*, jclass, const char*, const char* ...);
	jshort callStaticShortMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jshort callStaticShortMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jshort callStaticShortMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jint callStaticIntMethod(JNIEnv*, jclass, const char*, const char* ...);
	jint callStaticIntMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jint callStaticIntMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jint callStaticIntMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jlong callStaticLongMethod(JNIEnv*, jclass, const char*, const char* ...);
	jlong callStaticLongMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jlong callStaticLongMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jlong callStaticLongMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jfloat callStaticFloatMethod(JNIEnv*, jclass, const char*, const char* ...);
	jfloat callStaticFloatMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jfloat callStaticFloatMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jfloat callStaticFloatMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jdouble callStaticDoubleMethod(JNIEnv*, jclass, const char*, const char* ...);
	jdouble callStaticDoubleMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jdouble callStaticDoubleMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jdouble callStaticDoubleMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	jchar callStaticCharMethod(JNIEnv*, jclass, const char*, const char* ...);
	jchar callStaticCharMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jchar callStaticCharMethod(JNIEnv*, const char*, const char*, const char*, ...);
	jchar callStaticCharMethodV(JNIEnv*, jclass, const char*, const char*, va_list);

	void callVoidMethod(JNIEnv*, jobject, const char*, const char*, ...);
	void callVoidMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jobject callObjectMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jobject callObjectMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jboolean callBooleanMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jboolean callBooleanMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jbyte callByteMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jbyte callByteMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jshort callShortMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jshort callShortMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jint callIntMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jint callIntMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jlong callLongMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jlong callLongMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jfloat callFloatMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jfloat callFloatMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jdouble callDoubleMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jdouble callDoubleMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

	jchar callCharMethod(JNIEnv*, jobject, const char*, const char*, ...);
	jchar callCharMethodV(JNIEnv*, jobject, const char*, const char*, va_list);

}

jobject createJavaClass(JNIEnv*, jclass, const char*, ...);
jobject createJavaClass(JNIEnv*, jobject, const char*, ...);
jobject createJavaClass(JNIEnv*, const char*, const char*, ...);

jobject createJavaClassV(JNIEnv*, jclass, const char*, va_list);

#endif
