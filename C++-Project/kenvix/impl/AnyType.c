#ifndef __IncludeGuard_AnyType
#define __IncludeGuard_AnyType
#include <stddef.h>

typedef unsigned int size;

typedef union GenericType {
    void* pointer;
    long longInteger;
    int integer;
    short int shortInteger;
    char character;
    double doubleDecimal;
    float floatDecimal;
    bool boolean;
    unsigned int unsignedInteger;
    unsigned short int unsignedShortInteger;
    unsigned long unsignedLongInteger;
    unsigned char unsignedCharacter;
    size size;
} GenericType;

typedef struct GenericArray {
    GenericType* data;
    size count;
} GenericArray;

GenericArray* GenericArray_New(size count) {
    return (GenericArray*) calloc(count, sizeof(GenericType));
}

void GenericArray_Destroy(GenericArray* array) {
    free(array->data);
    free(array);
}

GenericType castPointerToGenericType(void* pointer) {
    return (GenericType) pointer;
}

GenericType getNull() {
    return (GenericType) NULL;
}

GenericType castCharToGenericType(char value) {
    return (GenericType) value;
}

GenericType castIntToGenericType(int value) {
    return (GenericType) value;
}

GenericType castLongToGenericType(long value) {
    return (GenericType) value;
}

GenericType castBoolToGenericType(bool value) {
    return (GenericType) value;
}

GenericType castFloatToGenericType(float value) {
    return (GenericType) value;
}

GenericType castDoubleToGenericType(double value) {
    return (GenericType) value;
}

GenericType dataAt(void* pointer, int unitSize, int position) {
    return (GenericType) (pointer + unitSize * position);
}

GenericType castSizeToGenericType(size value) {
    return (GenericType) value;
}

#endif