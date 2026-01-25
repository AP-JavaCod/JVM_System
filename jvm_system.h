#pragma once
#include <jni.h>

#ifndef JVM_SYSTEM_H_
#define JVM_SYSTEM_H_

namespace field {

	//Static Field

	jobject getStaticObject(JNIEnv*, jclass, const char*, const char*);
	jobject getStaticObject(JNIEnv*, jobject, const char*, const char*);
	jobject getStaticObject(JNIEnv*, const char*, const char*, const char*);

	jboolean getStaticBoolean(JNIEnv*, jclass, const char*);
	jboolean getStaticBoolean(JNIEnv*, jobject, const char*);
	jboolean getStaticBoolean(JNIEnv*, const char*, const char*);

	jbyte getStaticByte(JNIEnv*, jclass, const char*);
	jbyte getStaticByte(JNIEnv*, jobject, const char*);
	jbyte getStaticByte(JNIEnv*, const char*, const char*);

	jshort getStaticShort(JNIEnv*, jclass, const char*);
	jshort getStaticShort(JNIEnv*, jobject, const char*);
	jshort getStaticShort(JNIEnv*, const char*, const char*);

	jint getStaticInt(JNIEnv*, jclass, const char*);
	jint getStaticInt(JNIEnv*, jobject, const char*);
	jint getStaticInt(JNIEnv*, const char*, const char*);

	jlong getStaticLong(JNIEnv*, jclass, const char*);
	jlong getStaticLong(JNIEnv*, jobject, const char*);
	jlong getStaticLong(JNIEnv*, const char*, const char*);

	jfloat getStaticFloat(JNIEnv*, jclass, const char*);
	jfloat getStaticFloat(JNIEnv*, jobject, const char*);
	jfloat getStaticFloat(JNIEnv*, const char*, const char*);

	jdouble getStaticDouble(JNIEnv*, jclass, const char*);
	jdouble getStaticDouble(JNIEnv*, jobject, const char*);
	jdouble getStaticDouble(JNIEnv*, const char*, const char*);

	jchar getStaticChar(JNIEnv*, jclass, const char*);
	jchar getStaticChar(JNIEnv*, jobject, const char*);
	jchar getStaticChar(JNIEnv*, const char*, const char*);

	void setStaticObject(JNIEnv*, jclass, jobject, const char*, const char*);
	void setStaticObject(JNIEnv*, jobject, jobject, const char*, const char*);
	void setStaticObject(JNIEnv*, const char*, jobject, const char*, const char*);

	void setStaticBoolean(JNIEnv*, jclass, jboolean, const char*);
	void setStaticBoolean(JNIEnv*, jobject, jboolean, const char*);
	void setStaticBoolean(JNIEnv*, const char*, jboolean, const char*);

	void setStaticByte(JNIEnv*, jclass, jbyte, const char*);
	void setStaticByte(JNIEnv*, jobject, jbyte, const char*);
	void setStaticByte(JNIEnv*, const char*, jbyte, const char*);

	void setStaticShort(JNIEnv*, jclass, jshort, const char*);
	void setStaticShort(JNIEnv*, jobject, jshort, const char*);
	void setStaticShort(JNIEnv*, const char*, jshort, const char*);

	void setStaticInt(JNIEnv*, jclass, jint, const char*);
	void setStaticInt(JNIEnv*, jobject, jint, const char*);
	void setStaticInt(JNIEnv*, const char*, jint, const char*);

	void setStaticLong(JNIEnv*, jclass, jlong, const char*);
	void setStaticLong(JNIEnv*, jobject, jlong, const char*);
	void setStaticLong(JNIEnv*, const char*, jlong, const char*);

	void setStaticFloat(JNIEnv*, jclass, jfloat, const char*);
	void setStaticFloat(JNIEnv*, jobject, jfloat, const char*);
	void setStaticFloat(JNIEnv*, const char*, jfloat, const char*);

	void setStaticDouble(JNIEnv*, jclass, jdouble, const char*);
	void setStaticDouble(JNIEnv*, jobject, jdouble, const char*);
	void setStaticDouble(JNIEnv*, const char*, jdouble, const char*);

	void setStaticChar(JNIEnv*, jclass, jchar, const char*);
	void setStaticChar(JNIEnv*, jobject, jchar, const char*);
	void setStaticChar(JNIEnv*, const char*, jchar, const char*);

	//Not-static field

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

	//Static method

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

	//Not-static method

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
