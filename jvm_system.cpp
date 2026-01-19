#include "jvm_system.h"

jfieldID field::getFieldID(JNIEnv* env, jobject obj, const char* nameField, const char* typeField){
	jclass classJ = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(classJ, nameField, typeField);
	return id;
}

jobject field::getObject(JNIEnv* env, jobject obj, const char* nameField, const char* typeField){
	jfieldID id = getFieldID(env, obj, nameField, typeField);
	jobject res = env->GetObjectField(obj, id);
	return res;
}

jboolean field::getBoolean(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "Z");
	jboolean res = env->GetBooleanField(obj, id);
	return res;
}

jbyte field::getByte(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "B");
	jbyte res = env->GetByteField(obj, id);
	return res;
}

jshort field::getShort(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "S");
	jshort res = env->GetShortField(obj, id);
	return res;
}

jint field::getInt(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "I");
	jint res = env->GetIntField(obj, id);
	return res;
}

jlong field::getLong(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "J");
	jlong res = env->GetLongField(obj, id);
	return res;
}

jfloat field::getFloat(JNIEnv*env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "F");
	jfloat res = env->GetFloatField(obj, id);
	return res;
}

jdouble field::getDouble(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "D");
	jdouble res = env->GetDoubleField(obj, id);
	return res;
}

jchar field::getChar(JNIEnv* env, jobject obj, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "C");
	jchar res = env->GetCharField(obj, id);
	return res;
}

void field::setObject(JNIEnv* env, jobject obj, jobject value, const char* nameField, const char* typeField){
	jfieldID id = getFieldID(env, obj, nameField, typeField);
	env->SetObjectField(obj, id, value);
}

void field::setBoolean(JNIEnv* env, jobject obj, jboolean value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "Z");
	env->SetBooleanField(obj, id, value);
}

void field::setByte(JNIEnv* env, jobject obj, jbyte value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "B");
	env->SetByteField(obj, id, value);
}

void field::setShort(JNIEnv* env, jobject obj, jshort value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "S");
	env->GetShortField(obj, id);
}

void field::setInt(JNIEnv* env, jobject obj, jint value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "I");
	env->SetIntField(obj, id, value);
}

void field::setLong(JNIEnv* env, jobject obj, jlong value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "J");
	env->SetLongField(obj, id, value);
}

void field::setFloat(JNIEnv* env, jobject obj, jfloat value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "F");
	env->SetFloatField(obj, id, value);
}

void field::setDouble(JNIEnv* env, jobject obj, jdouble value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "D");
	env->SetDoubleField(obj, id, value);
}

void field::setChar(JNIEnv* env, jobject obj, jchar value, const char* nameField){
	jfieldID id = getFieldID(env, obj, nameField, "C");
	env->SetCharField(obj, id, value);
}

void method::callStaticVoidMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	va_start(arg, signature);
	callStaticVoidMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
}

void method::callStaticVoidMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	va_start(arg, signature);
	callStaticVoidMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
}

void method::callStaticVoidMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	va_start(arg, signature);
	callStaticVoidMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
}

void method::callStaticVoidMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	env->CallStaticVoidMethodV(classJ, id, arg);
}

jobject method::callStaticObjectMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jobject res;
	va_start(arg, signature);
	res = callStaticObjectMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jobject method::callStaticObjectMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jobject res;
	va_start(arg, signature);
	res = callStaticObjectMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jobject method::callStaticObjectMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jobject res;
	va_start(arg, signature);
	res = callStaticObjectMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jobject method::callStaticObjectMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticObjectMethodV(classJ, id, arg);
}

jboolean method::callStaticBooleanMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jboolean res;
	va_start(arg, signature);
	res = callStaticBooleanMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jboolean method::callStaticBooleanMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jboolean res;
	va_start(arg, signature);
	res = callStaticBooleanMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jboolean method::callStaticBooleanMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jboolean res;
	va_start(arg, signature);
	res = callStaticBooleanMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jboolean method::callStaticBooleanMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticBooleanMethodV(classJ, id, arg);
}

jbyte method::callStaticByteMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jbyte res;
	va_start(arg, signature);
	res = callStaticByteMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jbyte method::callStaticByteMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jbyte res;
	va_start(arg, signature);
	res = callStaticByteMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jbyte method::callStaticByteMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jbyte res;
	va_start(arg, signature);
	res = callStaticByteMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jbyte method::callStaticByteMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticByteMethodV(classJ, id, arg);
}

jshort method::callStaticShortMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jshort res;
	va_start(arg, signature);
	res = callStaticShortMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jshort method::callStaticShortMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jshort res;
	va_start(arg, signature);
	res = callStaticShortMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jshort method::callStaticShortMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jshort res;
	va_start(arg, signature);
	res = callStaticShortMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jshort method::callStaticShortMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticShortMethodV(classJ, id, arg);
}

jint method::callStaticIntMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jint res;
	va_start(arg, signature);
	res = callStaticIntMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jint method::callStaticIntMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jint res;
	va_start(arg, signature);
	res = callStaticIntMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jint method::callStaticIntMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jint res;
	va_start(arg, signature);
	res = callStaticIntMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jint method::callStaticIntMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticIntMethodV(classJ, id, arg);
}

jlong method::callStaticLongMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jlong res;
	va_start(arg, signature);
	res = callStaticLongMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jlong method::callStaticLongMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jlong res;
	va_start(arg, signature);
	res = callStaticLongMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jlong method::callStaticLongMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jlong res;
	va_start(arg, signature);
	res = callStaticLongMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jlong method::callStaticLongMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticLongMethodV(classJ, id, arg);
}

jfloat method::callStaticFloatMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jfloat res;
	va_start(arg, signature);
	res = callStaticFloatMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jfloat method::callStaticFloatMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jfloat res;
	va_start(arg, signature);
	res = callStaticFloatMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jfloat method::callStaticFloatMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jfloat res;
	va_start(arg, signature);
	res = callStaticFloatMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jfloat method::callStaticFloatMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticFloatMethodV(classJ, id, arg);
}

jdouble method::callStaticDoubleMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jdouble res;
	va_start(arg, signature);
	res = callStaticDoubleMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jdouble method::callStaticDoubleMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jdouble res;
	va_start(arg, signature);
	res = callStaticDoubleMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jdouble method::callStaticDoubleMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jdouble res;
	va_start(arg, signature);
	res = callStaticDoubleMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jdouble method::callStaticDoubleMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticDoubleMethodV(classJ, id, arg);
}

jchar method::callStaticCharMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	jchar res;
	va_start(arg, signature);
	res = callStaticCharMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jchar method::callStaticCharMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->GetObjectClass(obj);
	jchar res;
	va_start(arg, signature);
	res = callStaticCharMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jchar method::callStaticCharMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass classJ = env->FindClass(nameClass);
	jchar res;
	va_start(arg, signature);
	res = callStaticCharMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jchar method::callStaticCharMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallStaticCharMethodV(classJ, id, arg);
}


void method::callVoidMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	va_start(arg, signature);
	callVoidMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
}

void method::callVoidMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	env->CallVoidMethodV(obj, id, arg);
}

jobject method::callObjectMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jobject res;
	va_start(arg, signature);
	res = callObjectMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jobject method::callObjectMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallObjectMethodV(obj, id, arg);
}

jboolean method::callBooleanMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jboolean res;
	va_start(arg, signature);
	res = callBooleanMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jboolean method::callBooleanMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallBooleanMethodV(obj, id, arg);
}

jbyte method::callByteMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jbyte res;
	va_start(arg, signature);
	res = callByteMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jbyte method::callByteMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallByteMethodV(obj, id, arg);
}

jshort method::callShortMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jshort res;
	va_start(arg, signature);
	res = callShortMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jshort method::callShortMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallShortMethodV(obj, id, arg);
}

jint method::callIntMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jint res;
	va_start(arg, signature);
	res = callIntMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jint method::callIntMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallIntMethodV(obj, id, arg);
}

jlong method::callLongMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jlong res;
	va_start(arg, signature);
	res = callLongMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jlong method::callLongMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallLongMethodV(obj, id, arg);
}

jfloat method::callFloatMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jfloat res;
	va_start(arg, signature);
	res = callFloatMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jfloat method::callFloatMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallFloatMethodV(obj, id, arg);
}

jdouble method::callDoubleMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jdouble res;
	va_start(arg, signature);
	res = callDoubleMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jdouble method::callDoubleMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallDoubleMethodV(obj, id, arg);
}

jchar method::callCharMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jchar res;
	va_start(arg, signature);
	res = callCharMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jchar method::callCharMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	return env->CallCharMethodV(obj, id, arg);
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
