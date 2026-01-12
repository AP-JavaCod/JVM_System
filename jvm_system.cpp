#include "jvm_system.h"

jfieldID getFieldID(JNIEnv* env, jobject obj, const char* nameField, const char* typeField){
	jclass classJ = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(classJ, nameField, typeField);
	return id;
}

jobject getFieldObject(JNIEnv* env, jobject obj, const char* nameField, const char* typeField){
	jfieldID id = getFieldID(env, obj, nameField, typeField);
	jobject res = env->GetObjectField(obj, id);
	return res;
}

jboolean getFieldBoolean(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "Z");
	jboolean res = env->GetBooleanField(obj, id);
	return res;
}

jbyte getFieldByte(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "B");
	jbyte res = env->GetByteField(obj, id);
	return res;
}

jshort getFieldShort(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "S");
	jshort res = env->GetShortField(obj, id);
	return res;
}

jint getFieldInt(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "I");
	jint res = env->GetIntField(obj, id);
	return res;
}

jlong getFieldLong(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "J");
	jlong res = env->GetLongField(obj, id);
	return res;
}

jfloat getFieldFloat(JNIEnv*env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "F");
	jfloat res = env->GetFloatField(obj, id);
	return res;
}

jdouble getFieldDouble(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "D");
	jdouble res = env->GetDoubleField(obj, id);
	return res;
}

jchar getFieldChar(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "C");
	jchar res = env->GetCharField(obj, id);
	return res;
}

void setFieldObject(JNIEnv* env, jobject obj, jobject value, const char* nameField, const char* typeField){
	jfieldID id = getFieldID(env, obj, nameField, typeField);
	env->SetObjectField(obj, id, value);
}

void setFieldBoolean(JNIEnv* env, jobject obj, jboolean value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "Z");
	env->SetBooleanField(obj, id, value);
}

void setFieldByte(JNIEnv* env, jobject obj, jbyte value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "B");
	env->SetByteField(obj, id, value);
}

void setFieldShort(JNIEnv* env, jobject obj, jshort value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "S");
	env->GetShortField(obj, id);
}

void setFieldInt(JNIEnv* env, jobject obj, jint value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "I");
	env->SetIntField(obj, id, value);
}

void setFieldLong(JNIEnv* env, jobject obj, jlong value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "J");
	env->SetLongField(obj, id, value);
}

void setFieldFloat(JNIEnv* env, jobject obj, jfloat value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "F");
	env->SetFloatField(obj, id, value);
}

void setFieldDouble(JNIEnv* env, jobject obj, jdouble value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "D");
	env->SetDoubleField(obj, id, value);
}

void setFieldChar(JNIEnv* env, jobject obj, jchar value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "C");
	env->SetCharField(obj, id, value);
}

jmethodID getMethodID(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return id;
}

jobject createJavaClass(JNIEnv* env, jclass classJ, const char* signature, ...){
	va_list arg;
	jobject res;
	va_start(arg, signature);
	res = createJavaClassV(env, classJ, signature, arg);
	va_end(arg);
	return res;
}

jobject createJavaClass(JNIEnv* env, jobject obj, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jobject res;
	va_start(arg, signature);
	res = createJavaClassV(env, classJ, signature, arg);
	va_end(arg);
	return res;
}

jobject createJavaClass(JNIEnv* env, const char* nameClass, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jobject res;
	va_start(arg, signature);
	res = createJavaClassV(env, classJ, signature, arg);
	va_end(arg);
	return res;
}

jobject createJavaClassV(JNIEnv* env, jclass classJ, const char* signature, va_list args){
	jmethodID id = env->GetMethodID(classJ, "<init>", signature);
	jobject res = env->NewObjectV(classJ, id, args);
	return res;
}
