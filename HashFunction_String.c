//#include "hashFunction.h"

unsigned DJBHash(char* str, int len, int hashLen){
	unsigned  hash = 5381;

	for(int i = 0; i < len; ++i){
		hash = (((hash<<5) + hash) + (unsigned)str[i]);
		//tmpU = (tmpU * 33) + (unsigned)str[i];
	}

	return hash % hashLen;
}

unsigned SDBMHash(char* str, int len, int hashLen){ 
    unsigned hash = 0;  
	
	for(int i = 0; i < len; ++i){
		hash = 65599 * hash + (unsigned)str[i];
		//hash = (hash << 6) + (hash << 16) - hash + (unsigned)str[i];  
	}
 
    return hash % hashLen;  
}

unsigned APHash(char* str, int len, int hashLen){  
    unsigned hash = 0;  
    unsigned ch;  
    for(int i = 0; i < len; ++i){
		ch = (unsigned)str[i];
        if ((i & 1) == 0){  
            hash ^= ((hash << 7) ^ ch ^ (hash >> 3));  
        }  
        else{  
            hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));  
        }  
    }  
    return hash%hashLen;  
}  

unsigned FNVHash(char* str, int len, int hashLen){  
    unsigned hash = 2166136261;  
    for(int i = 0; i < len; ++i){
		hash *= 16777619;  
        hash ^= (unsigned)str[i];
    }  
    return hash%hashLen;  
} 
 
unsigned RSHash(char* str, int len, int hashLen){  
    unsigned hash = 0;  
    unsigned magic = 63689; 
    for(int i = 0; i < len; ++i){
        hash = hash * magic + (unsigned)str[i];
        magic *= 378551;  
    }  
    return hash%hashLen;  
}  

unsigned JSHash(char* str, int len, int hashLen){      
    unsigned hash = 1315423911;  
    for(int i = 0; i < len; ++i){
        hash ^= ((hash << 5) + (unsigned)str[i] + (hash >> 2)); 
    }  
    return hash%hashLen;  
}  

unsigned BKDRHash(char* str, int len, int hashLen){ 
    unsigned hash = 0;  
	for(int i = 0; i < len; ++i){
        hash = (hash << 7) + (hash << 1) + hash + (unsigned)str[i]; 
    } 
    return hash%hashLen; 
}  

//===========without space========================================
unsigned DJBHash_ExceptSpace(char* str, int len, int hashLen){
	unsigned iniValue = 5381;
	unsigned M = 33;

	unsigned  tmpU = iniValue;
	for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			break;
		}
		tmpU = (((tmpU<<5) + tmpU) + (unsigned)str[i]);
		//tmpU = (tmpU * 33) + (unsigned)str[i];
	}

	return tmpU % hashLen;
}

unsigned SDBMHash_ExceptSpace(char* str, int len, int hashLen){ 
    unsigned hash = 0;  
	
	for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			break;
		}
		hash = 65599 * hash + (unsigned)str[i];
		//hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
	}
 
    return hash % hashLen;  
}  

unsigned APHash_ExceptSpace(char* str, int len, int hashLen){  
    unsigned hash = 0;  
    unsigned ch;  
    for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			break;
		}
		ch = (unsigned)str[i];
        if ((i & 1) == 0){  
            hash ^= ((hash << 7) ^ ch ^ (hash >> 3));  
        }  
        else{  
            hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));  
        }  
    }  
    return hash%hashLen;  
}  

unsigned FNVHash_ExceptSpace(char* str, int len, int hashLen){  
    unsigned hash = 2166136261;  
    for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			break;
		}
		hash *= 16777619;  
        hash ^= (unsigned)str[i];
    }  
    return hash%hashLen;  
} 
 
unsigned RSHash_ExceptSpace(char* str, int len, int hashLen){  
    unsigned hash = 0;  
    unsigned magic = 63689; 
    for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			break;
		}
        hash = hash * magic + (unsigned)str[i];
        magic *= 378551;  
    }  
    return hash%hashLen;  
}  

unsigned JSHash_ExceptSpace(char* str, int len, int hashLen){      
    unsigned hash = 1315423911;  
    for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			break;
		}
        hash ^= ((hash << 5) + (unsigned)str[i] + (hash >> 2)); 
    }  
    return hash%hashLen;  
}  

unsigned BKDRHash_ExceptSpace(char* str, int len, int hashLen){ 
    unsigned hash = 0;  
	for(int i = 0; i < len; ++i){
		if(str[i] == ' '){
			break;
		}
        hash = (hash << 7) + (hash << 1) + hash + (unsigned)str[i]; 
    } 
    return hash%hashLen; 
}  
