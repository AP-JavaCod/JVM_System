#include "jvm_system.h"

const char* exception::ClassCastException = "java/lang/ClassCastException";
const char* exception::NullPointerException = "java/lang/NullPointerException";
const char* exception::ArrayIndexOutOfBoundsException = "java/lang/ArrayIndexOutOfBoundsException";
const char* exception::NoSuchFieldException = "java/lang/NoSuchFieldException";
const char* exception::NoSuchMethodException = "java/lang/NoSuchMethodException";

exception::JavaException::JavaException(const char* nameException, const char* message) : nameClassException{nameException}, message{message} {};

exception::JavaException::JavaException(const char* message) : JavaException("java/lang/Exception", message) {};

const char* exception::JavaException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW{
	return message;
}

jint exception::JavaException::throwJavaException(JNIEnv* env) const{
	jclass classException = env->FindClass(nameClassException);
	return env->ThrowNew(classException, message);
}

jobject field::getStaticObject(JNIEnv* env, jclass cl, const char* nameField, const char* typeField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, typeField);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jobject res = env->GetStaticObjectField(cl, id);
	return res;
}

jobject field::getStaticObject(JNIEnv* env, jobject obj, const char* nameFile, const char* typeField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jobject res = getStaticObject(env, cl, nameFile, typeField);
	return res;
}

jobject field::getStaticObject(JNIEnv* env, const char* nameClass, const char* nameFile, const char* typeField){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jobject res = getStaticObject(env, cl, nameFile, typeField);
	return res;
}

jboolean field::getStaticBoolean(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "Z");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, " no field");
	}
	jboolean res = env->GetStaticBooleanField(cl, id);
	return res;
}

jboolean field::getStaticBoolean(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jboolean res = getStaticBoolean(env, cl, nameFile);
	return res;
}

jboolean field::getStaticBoolean(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jboolean res = getStaticBoolean(env, cl, nameFile);
	return res;
}

jbyte field::getStaticByte(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "B");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, " no field");
	}
	jbyte res = env->GetStaticByteField(cl, id);
	return res;
}

jbyte field::getStaticByte(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jbyte res = getStaticByte(env, cl, nameFile);
	return res;
}

jbyte field::getStaticByte(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jbyte res = getStaticByte(env, cl, nameFile);
	return res;
}

jshort field::getStaticShort(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "S");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jshort res = env->GetStaticShortField(cl, id);
	return res;
}

jshort field::getStaticShort(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "no null");
	}
	jclass cl = env->GetObjectClass(obj);
	jshort res = getStaticShort(env, cl, nameFile);
	return res;
}

jshort field::getStaticShort(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jshort res = getStaticShort(env, cl, nameFile);
	return res;
}

jint field::getStaticInt(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "I");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jint res = env->GetStaticIntField(cl, id);
	return res;
}

jint field::getStaticInt(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jint res = getStaticInt(env, cl, nameFile);
	return res;
}

jint field::getStaticInt(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jint res = getStaticInt(env, cl, nameFile);
	return res;
}

jlong field::getStaticLong(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "J");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	long res = env->GetStaticLongField(cl, id);
	return res;
}

jlong field::getStaticLong(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jlong res = getStaticLong(env, cl, nameFile);
	return res;
}

jlong field::getStaticLong(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jlong res = getStaticLong(env, cl, nameFile);
	return res;
}

jfloat field::getStaticFloat(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "F");
	if(cl == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jfloat res = env->GetStaticFloatField(cl, id);
	return res;
}

jfloat field::getStaticFloat(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfloat res = getStaticFloat(env, cl, nameFile);
	return res;
}

jfloat field::getStaticFloat(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jfloat res = getStaticFloat(env, cl, nameFile);
	return res;
}

jdouble field::getStaticDouble(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "D");
	if(cl == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no filed");
	}
	jdouble res = env->GetStaticDoubleField(cl, id);
	return res;
}

jdouble field::getStaticDouble(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jdouble res = getStaticDouble(env, cl, nameFile);
	return res;
}

jdouble field::getStaticDouble(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jdouble res = getStaticDouble(env, cl, nameFile);
	return res;
}

jchar field::getStaticChar(JNIEnv* env, jclass cl, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "C");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jchar res = env->GetStaticCharField(cl, id);
	return res;
}

jchar field::getStaticChar(JNIEnv* env, jobject obj, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jchar res = getStaticChar(env, cl, nameFile);
	return res;
}

jchar field::getStaticChar(JNIEnv* env, const char* nameClass, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jchar res = getStaticChar(env, cl, nameFile);
	return res;
}

void field::setStaticObject(JNIEnv* env, jclass cl, jobject value, const char* nameField, const char* typeField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, typeField);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticObjectField(cl, id, value);
}

void field::setStaticObject(JNIEnv* env, jobject obj, jobject value, const char* nameFile, const char* typeField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticObject(env, cl, value, nameFile, typeField);
}

void field::setStaticObject(JNIEnv* env, const char* nameClass, jobject value, const char* nameFile, const char* typeField){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticObject(env, cl, value, nameFile, typeField);
}

void field::setStaticBoolean(JNIEnv* env, jclass cl, jboolean value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "Z");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticBooleanField(cl, id, value);
}

void field::setStaticBoolean(JNIEnv* env, jobject obj, jboolean value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticBoolean(env, cl, value, nameFile);
}

void field::setStaticBoolean(JNIEnv* env, const char* nameClass, jboolean value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticBoolean(env, cl, value, nameFile);
}

void field::setStaticByte(JNIEnv* env, jclass cl, jbyte value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "B");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticByteField(cl, id, value);
}

void field::setStaticByte(JNIEnv* env, jobject obj, jbyte value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticByte(env, cl, value, nameFile);
}

void field::setStaticByte(JNIEnv* env, const char* nameClass, jbyte value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticByte(env, cl, value, nameFile);
}

void field::setStaticShort(JNIEnv* env, jclass cl, jshort value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "S");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticShortField(cl, id, value);
}

void field::setStaticShort(JNIEnv* env, jobject obj, jshort value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticShort(env, cl, value, nameFile);
}

void field::setStaticShort(JNIEnv* env, const char* nameClass, jshort value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticShort(env, cl, value, nameFile);
}

void field::setStaticInt(JNIEnv* env, jclass cl, jint value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "I");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticIntField(cl, id, value);
}

void field::setStaticInt(JNIEnv* env, jobject obj, jint value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticInt(env, cl, value, nameFile);
}

void field::setStaticInt(JNIEnv* env, const char* nameClass, jint value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticInt(env, cl, value, nameFile);
}

void field::setStaticLong(JNIEnv* env, jclass cl, jlong value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "J");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticLongField(cl, id, value);
}

void field::setStaticLong(JNIEnv* env, jobject obj, jlong value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticLong(env, cl, value, nameFile);
}

void field::setStaticLong(JNIEnv* env, const char* nameClass, jlong value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticLong(env, cl, value, nameFile);
}

void field::setStaticFloat(JNIEnv* env, jclass cl, jfloat value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "F");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticFloatField(cl, id, value);
}

void field::setStaticFloat(JNIEnv* env, jobject obj, jfloat value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticFloat(env, cl, value, nameFile);
}

void field::setStaticFloat(JNIEnv* env, const char* nameClass, jfloat value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticFloat(env, cl, value, nameFile);
}

void field::setStaticDouble(JNIEnv* env, jclass cl, jdouble value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "D");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticDoubleField(cl, id, value);
}

void field::setStaticDouble(JNIEnv* env, jobject obj, jdouble value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticDouble(env, cl, value, nameFile);
}

void field::setStaticDouble(JNIEnv* env, const char* nameClass, jdouble value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticDouble(env, cl, value, nameFile);
}

void field::setStaticChar(JNIEnv* env, jclass cl, jchar value, const char* nameField){
	jfieldID id = env->GetStaticFieldID(cl, nameField, "C");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetStaticCharField(cl, id, value);
}

void field::setStaticChar(JNIEnv* env, jobject obj, jchar value, const char* nameFile){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	setStaticChar(env, cl, value, nameFile);
}

void field::setStaticChar(JNIEnv* env, const char* nameClass, jchar value, const char* nameFile){
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	setStaticChar(env, cl, value, nameFile);
}

jobject field::getObject(JNIEnv* env, jobject obj, const char* nameField, const char* typeField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, typeField);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jobject res = env->GetObjectField(obj, id);
	return res;
}

jboolean field::getBoolean(JNIEnv* env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "Z");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jboolean res = env->GetBooleanField(obj, id);
	return res;
}

jbyte field::getByte(JNIEnv* env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "B");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jbyte res = env->GetByteField(obj, id);
	return res;
}

jshort field::getShort(JNIEnv* env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "S");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jshort res = env->GetShortField(obj, id);
	return res;
}

jint field::getInt(JNIEnv* env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "I");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jint res = env->GetIntField(obj, id);
	return res;
}

jlong field::getLong(JNIEnv* env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "J");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jlong res = env->GetLongField(obj, id);
	return res;
}

jfloat field::getFloat(JNIEnv*env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "F");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jfloat res = env->GetFloatField(obj, id);
	return res;
}

jdouble field::getDouble(JNIEnv* env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "D");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jdouble res = env->GetDoubleField(obj, id);
	return res;
}

jchar field::getChar(JNIEnv* env, jobject obj, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "C");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	jchar res = env->GetCharField(obj, id);
	return res;
}

void field::setObject(JNIEnv* env, jobject obj, jobject value, const char* nameField, const char* typeField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, typeField);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetObjectField(obj, id, value);
}

void field::setBoolean(JNIEnv* env, jobject obj, jboolean value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "Z");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetBooleanField(obj, id, value);
}

void field::setByte(JNIEnv* env, jobject obj, jbyte value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "B");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetByteField(obj, id, value);
}

void field::setShort(JNIEnv* env, jobject obj, jshort value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "S");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->GetShortField(obj, id);
}

void field::setInt(JNIEnv* env, jobject obj, jint value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "I");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetIntField(obj, id, value);
}

void field::setLong(JNIEnv* env, jobject obj, jlong value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "J");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetLongField(obj, id, value);
}

void field::setFloat(JNIEnv* env, jobject obj, jfloat value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "F");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetFloatField(obj, id, value);
}

void field::setDouble(JNIEnv* env, jobject obj, jdouble value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "D");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetDoubleField(obj, id, value);
}

void field::setChar(JNIEnv* env, jobject obj, jchar value, const char* nameField){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass cl = env->GetObjectClass(obj);
	jfieldID id = env->GetFieldID(cl, nameField, "C");
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchFieldException, "no field");
	}
	env->SetCharField(obj, id, value);
}

void method::callStaticVoidMethod(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature ...){
	va_list arg;
	va_start(arg, signature);
	callStaticVoidMethodV(env, classJ, nameMethod, signature, arg);
	va_end(arg);
}

void method::callStaticVoidMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	va_start(arg, signature);
	callStaticVoidMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
}

void method::callStaticVoidMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, " no class");
	}
	va_start(arg, signature);
	callStaticVoidMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
}

void method::callStaticVoidMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jobject res;
	va_start(arg, signature);
	res = callStaticObjectMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jobject method::callStaticObjectMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jobject res;
	va_start(arg, signature);
	res = callStaticObjectMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jobject method::callStaticObjectMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jboolean res;
	va_start(arg, signature);
	res = callStaticBooleanMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jboolean method::callStaticBooleanMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jboolean res;
	va_start(arg, signature);
	res = callStaticBooleanMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jboolean method::callStaticBooleanMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jbyte res;
	va_start(arg, signature);
	res = callStaticByteMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jbyte method::callStaticByteMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jbyte res;
	va_start(arg, signature);
	res = callStaticByteMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jbyte method::callStaticByteMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jshort res;
	va_start(arg, signature);
	res = callStaticShortMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jshort method::callStaticShortMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jshort res;
	va_start(arg, signature);
	res = callStaticShortMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jshort method::callStaticShortMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jint res;
	va_start(arg, signature);
	res = callStaticIntMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jint method::callStaticIntMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jint res;
	va_start(arg, signature);
	res = callStaticIntMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jint method::callStaticIntMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jlong res;
	va_start(arg, signature);
	res = callStaticLongMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jlong method::callStaticLongMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jlong res;
	va_start(arg, signature);
	res = callStaticLongMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jlong method::callStaticLongMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jfloat res;
	va_start(arg, signature);
	res = callStaticFloatMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jfloat method::callStaticFloatMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jfloat res;
	va_start(arg, signature);
	res = callStaticFloatMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jfloat method::callStaticFloatMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jdouble res;
	va_start(arg, signature);
	res = callStaticDoubleMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jdouble method::callStaticDoubleMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jdouble res;
	va_start(arg, signature);
	res = callStaticDoubleMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jdouble method::callStaticDoubleMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	va_list arg;
	jclass cl = env->GetObjectClass(obj);
	jchar res;
	va_start(arg, signature);
	res = callStaticCharMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jchar method::callStaticCharMethod(JNIEnv* env, const char* nameClass, const char* nameMethod, const char* signature, ...){
	va_list arg;
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jchar res;
	va_start(arg, signature);
	res = callStaticCharMethodV(env, cl, nameMethod, signature, arg);
	va_end(arg);
	return res;
}

jchar method::callStaticCharMethodV(JNIEnv* env, jclass classJ, const char* nameMethod, const char* signature, va_list arg){
	jmethodID id = env->GetStaticMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
	return env->CallStaticCharMethodV(classJ, id, arg);
}


void method::callVoidMethod(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, ...){
	va_list arg;
	va_start(arg, signature);
	callVoidMethodV(env, obj, nameMethod, signature, arg);
	va_end(arg);
}

void method::callVoidMethodV(JNIEnv* env, jobject obj, const char* nameMethod, const char* signature, va_list arg){
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
	jclass classJ = env->GetObjectClass(obj);
	jmethodID id = env->GetMethodID(classJ, nameMethod, signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no method");
	}
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
	if(obj == NULL){
		throw exception::JavaException(exception::NullPointerException, "object null");
	}
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
	jclass cl = env->FindClass(nameClass);
	if(cl == NULL){
		throw exception::JavaException(exception::ClassCastException, "no class");
	}
	jobject res;
	va_start(arg, signature);
	res = createJavaClassV(env, cl, signature, arg);
	va_end(arg);
	return res;
}

jobject createJavaClassV(JNIEnv* env, jclass classJ, const char* signature, va_list args){
	jmethodID id = env->GetMethodID(classJ, "<init>", signature);
	if(id == NULL){
		throw exception::JavaException(exception::NoSuchMethodException, "no constructor");
	}
	jobject res = env->NewObjectV(classJ, id, args);
	return res;
}
