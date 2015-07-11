#include <iostream>
#include <jni.h>
#include <string>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include "StringUtils.h"


/*
 * Class:     StringUtils
 * Method:    reverse
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_StringUtils_reverse
        (JNIEnv * env, jclass clazz, jstring js){
    jboolean wasCopy;
    const char* jchars = env->GetStringUTFChars(js,&wasCopy);
    std::string nativeString = jchars;
    std::string reverse;
    for(std::string::reverse_iterator ri = nativeString.rbegin(); ri != nativeString.rend();++ri)
        reverse += *ri;
    env->ReleaseStringUTFChars(js,jchars);
    return env->NewStringUTF(reverse.c_str());
}

/*
 * Class:     StringUtils
 * Method:    firstNotOf
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_firstNotOf__Ljava_lang_String_2Ljava_lang_String_2
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2){
    jboolean wasCopy,wasCopy2;
    const char* jchars = env->GetStringUTFChars(js1,&wasCopy);
    const char* jchars2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string nativeString = jchars;
    std::string notOf = jchars2;
    jint ret = nativeString.find_first_not_of(notOf);
    env->ReleaseStringUTFChars(js1,jchars);
    env->ReleaseStringUTFChars(js2,jchars2);
    return ret;
}

/*
 * Class:     StringUtils
 * Method:    firstNotOf
 * Signature: (Ljava/lang/String;Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_firstNotOf__Ljava_lang_String_2Ljava_lang_String_2I
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2, jint ji){
    jboolean wasCopy,wasCopy2;
    const char* jchars = env->GetStringUTFChars(js1,&wasCopy);
    const char* jchars2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string nativeString = jchars;
    std::string notOf = jchars2;
    jint ret = nativeString.find_first_not_of(notOf,ji);
    env->ReleaseStringUTFChars(js1,jchars);
    env->ReleaseStringUTFChars(js2,jchars2);
    return ret;
}

/*
 * Class:     StringUtils
 * Method:    lastNotOf
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_lastNotOf__Ljava_lang_String_2Ljava_lang_String_2
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2){
    jboolean wasCopy,wasCopy2;
    const char* jchars = env->GetStringUTFChars(js1,&wasCopy);
    const char* jchars2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string nativeString = jchars;
    std::string notOf = jchars2;
    jint ret = nativeString.find_last_not_of(notOf);
    env->ReleaseStringUTFChars(js1,jchars);
    env->ReleaseStringUTFChars(js2,jchars2);
    return ret;
}

/*
 * Class:     StringUtils
 * Method:    lastNotOf
 * Signature: (Ljava/lang/String;Ljava/lang/String;I)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_lastNotOf__Ljava_lang_String_2Ljava_lang_String_2I
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2, jint ji){
    jboolean wasCopy,wasCopy2;
    const char* jchars = env->GetStringUTFChars(js1,&wasCopy);
    const char* jchars2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string nativeString = jchars;
    std::string notOf = jchars2;
    jint ret = nativeString.find_last_not_of(notOf,ji);
    env->ReleaseStringUTFChars(js1,jchars);
    env->ReleaseStringUTFChars(js2,jchars2);
    return ret;
}

/*
 * Class:     StringUtils
 * Method:    generateSubsets
 * Signature: (Ljava/lang/String;)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_StringUtils_generatePermuations__Ljava_lang_String_2
        (JNIEnv * env, jclass clazz, jstring js){
	 return  Java_StringUtils_generatePermuations__Ljava_lang_String_2I(env,clazz,js,1000000);
}


/*
 * Class:     StringUtils
 * Method:    generatePermuations
 * Signature: (Ljava/lang/String;I)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_StringUtils_generatePermuations__Ljava_lang_String_2I
        (JNIEnv * env, jclass clazz, jstring js, jint lim) {
    jboolean wasCopy;
    const char* jchars = env->GetStringUTFChars(js,&wasCopy);
    std::string native = jchars;
    jclass arList = env->FindClass("java/util/ArrayList");
    jobject instance = env->NewObject(arList,env->GetMethodID(arList,"<init>","()V"));
    jmethodID arListAdd = env->GetMethodID(arList,"add","(Ljava/lang/Object;)Z");
    int size = 0;
    while(std::next_permutation(native.begin(),native.end())){
        jvalue args[1];
        args[0].l = env->NewStringUTF(native.c_str());
        jboolean addSuccess = env->CallBooleanMethodA(instance,arListAdd,args);
        if(!addSuccess)
            std::cout<<"There was a problem adding permutation "<<size+1<<std::endl;
        if(size++ >= lim)
            break;
    }
	env->ReleaseStringUTFChars(js,jchars);
    return  instance;
}

/*
 * Class:     StringUtils
 * Method:    levenshteinDistance
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_levenshteinDistance
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2){
    jboolean wasCopy,wasCopy2;
    const char* cstring1 = env->GetStringUTFChars(js1,&wasCopy);
    const char* cstring2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string s1 = cstring1;
    std::string s2 = cstring2;
    jint distance = 0;
    bool returnEarly = false;
    if(s1 == s2 || s1.empty() && s2.empty()) {
        returnEarly = true;
    }else if(s1.length() == 0) {
        distance = (jint) s2.length();
        returnEarly = true;
    }else if(s2.length() == 0) {
        distance = (jint) s1.length();
        returnEarly = true;
    }
    if(!returnEarly){
        int s1Len = s1.length();
        int s2Len = s2.length();
        int prefixDistMatrix[s1Len][s2Len];
        for(int i = 0; i < s1Len; ++i)
            prefixDistMatrix[i][0] = i;
        for(int i = 0; i < s2Len; ++i)
            prefixDistMatrix[0][i] = i;
        for(int i = 1; i < s1Len; ++i){
            for(int j = 1; j < s2Len; ++j){
                int cost =  s1[i-1] == s2[j-1] ? 0 : 1;
                int deleteOrInsertion = std::min(prefixDistMatrix[i - 1][j] + 1,//deletion
                                                  prefixDistMatrix[i][j - 1] + 1);//insertion
                prefixDistMatrix[i][j] =
                        std::min(deleteOrInsertion,
                                 prefixDistMatrix[i - 1][j - 1] + cost//substitution
                        );
            }
        }
        distance = prefixDistMatrix[s1Len - 1][s2Len - 1];
    }
    env->ReleaseStringUTFChars(js1,cstring1);
    env->ReleaseStringUTFChars(js2,cstring2);
    return distance;
}

/*
 * Class:     StringUtils
 * Method:    optimalStringAlignmentDistance
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_optimalStringAlignmentDistance
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2){
    jboolean wasCopy,wasCopy2;
    const char* cstring1 = env->GetStringUTFChars(js1,&wasCopy);
    const char* cstring2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string s1 = cstring1;
    std::string s2 = cstring2;
    jint distance = 0;
    bool returnEarly = false;
    if(s1 == s2 || s1.empty() && s2.empty()) {
        returnEarly = true;
    }else if(s1.length() == 0) {
        distance = (jint) s2.length();
        returnEarly = true;
    }else if(s2.length() == 0) {
        distance = (jint) s1.length();
        returnEarly = true;
    }
    if(!returnEarly){
        int s1Len = s1.length();
        int s2Len = s2.length();
        int prefixDistMatrix[s1Len][s2Len];
        for(int i = 0; i < s1Len; ++i)
            prefixDistMatrix[i][0] = i;
        for(int i = 0; i < s2Len; ++i)
            prefixDistMatrix[0][i] = i;
        for(int i = 1; i < s1Len; ++i){
            for(int j = 1; j < s2Len; ++j){
                int cost =  s1[i-1] == s2[j-1] ? 0 : 1;
                if((i > 1 && j > 1) && (s1[i] == s2[j-1]) &&(s1[i-1] == s2[j])){
                    prefixDistMatrix[i][j] =
                            std::min(prefixDistMatrix[i][j],prefixDistMatrix[i - 2][j - 2] + cost);// transposition
                } else {
                    int deleteOrInsert = std::min(prefixDistMatrix[i - 1][j] + 1,//deletion
                                                  prefixDistMatrix[i][j - 1] + 1);//insertion
                    prefixDistMatrix[i][j] = std::min(deleteOrInsert,prefixDistMatrix[i - 1][j - 1] + cost);//substitution
                }
            }
        }
        distance = prefixDistMatrix[s1Len - 1][s2Len - 1];
    }
    env->ReleaseStringUTFChars(js1,cstring1);
    env->ReleaseStringUTFChars(js2,cstring2);
    return distance;
}

/*
 * Class:     StringUtils
 * Method:    damerauLevenshteinDistance
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_damerauLevenshteinDistance
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2){
    jboolean wasCopy,wasCopy2;
    const char* cstring1 = env->GetStringUTFChars(js1,&wasCopy);
    const char* cstring2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string s1 = cstring1;
    std::string s2 = cstring2;
    bool returnEarly = false;
    jint distance = 0;
    if(s1 == s2 || s1.empty() && s2.empty()) {
        returnEarly = true;
    }else if(s1.length() == 0) {
        distance = (jint) s2.length();
        returnEarly = true;
    }else if(s2.length() == 0) {
        distance = (jint) s1.length();
        returnEarly = true;
    }
    if(!returnEarly){
        int s1Len = s1.length();
        int s2Len = s2.length();
        int table[s1Len][s2Len];
        std::unordered_map<char,int> s1IndexByChar;
        if(s1[0] != s2[0])
            table[0][0] = 1;
        s1IndexByChar[s1[0]] = 0;
        for(int i = 1; i < s1Len; ++i){
            int deleteDistance = table[i-1][0] + 1;
            int insertDistance = (i+1)*2;
            int matchDistance = i + (s1[i] == s2[0] ? 0 : 1);
            table[i][0] = std::min(deleteDistance,std::min(insertDistance,matchDistance));
        }

        for(int i = 0; i < s2Len; ++i){
            int deleteDistance = (i+1)*2;
            int insertDistance = table[0][i-1] +1;
            int matchDistance = i + (s1[0] == s2[i] ? 0 : 1);
            table[0][i] = std::min(deleteDistance,std::min(insertDistance,matchDistance));
        }

        for(int i = 1; i < s1Len; ++i){
            int maxSourceLetterMatchIndex = s1[i] == s2[0] ? 0 : -1;
            for(int j = 1; j < s2Len; ++j){
                int candidateSwapIndex = s1IndexByChar[s2[j]];
                int jSwap = maxSourceLetterMatchIndex;
                int deleteDistance = table[i - 1][j] + 1;
                int insertDistance = table[i][j - 1] + 1;
                int matchDistance = table[i - 1][j - 1];
                if(s1[i] != s2[j])
                    matchDistance += 1;
                else
                    maxSourceLetterMatchIndex = j;
                int swapDistance;
                if(jSwap != -1) {
                    int iSwap = candidateSwapIndex;
                    int preSwapCost;
                    if(iSwap == 0 && jSwap == 0)
                        preSwapCost = 0;
                    else
                        preSwapCost = table[std::max(0,iSwap-1)][std::max(0,jSwap-1)];
                    swapDistance = preSwapCost + (i-iSwap-1) + (j-jSwap-1) * 2;
                }else
                    swapDistance = INT_MAX;

                table[i][j] = std::min(deleteDistance,std::min(insertDistance,std::min(matchDistance,swapDistance)));
            }
            s1IndexByChar[s1[i]] = i;
        }
        distance = table[s1Len-1][s2Len -1];
    }
    env->ReleaseStringUTFChars(js1,cstring1);
    env->ReleaseStringUTFChars(js2,cstring2);
    return distance;
}

/*
 * Class:     StringUtils
 * Method:    boyerMooreBadChar
 * Signature: (Ljava/lang/String;Ljava/lang/String;)I
 */
JNIEXPORT jint JNICALL Java_StringUtils_boyerMooreBadChar
        (JNIEnv * env, jclass clazz, jstring js1, jstring js2){
    jboolean wasCopy,wasCopy2;
    jint subStringStart = -1;
    const char* cstring1 = env->GetStringUTFChars(js1,&wasCopy);
    const char* cstring2 = env->GetStringUTFChars(js2,&wasCopy2);
    std::string pattern = cstring1;
    std::string text = cstring2;
    int alphabetSize = 256;
    int badChar[alphabetSize];
    int patLen = pattern.length();
    int textLen = text.length();
    int skip = 0;

    for(int i = 0; i < alphabetSize; ++i)
        badChar[i] = -1;

    for(int i = 0; i < patLen; ++i)
        badChar[pattern[i]] = i;

    int searchLen = textLen - patLen;

    for(int i = 0; i <= searchLen; i += skip){
        skip = 0;
        for(int j = patLen - 1; j >= 0; --j){
            if(pattern[j] != text[i+j]){
                skip += std::max(1,j-badChar[text[i+j]]);
                break;
            }
        }
        if(skip == 0){
            subStringStart = i;
            break;
        }
    }

    env->ReleaseStringUTFChars(js1,cstring1);
    env->ReleaseStringUTFChars(js2,cstring2);

    return subStringStart;
}
