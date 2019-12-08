#ifndef __IncludeGuard_AnyType
#define __IncludeGuard_AnyType
#include <stddef.h>
#include <stdbool.h>

typedef union GenericType {
    void* pointer;
    long longInteger;
    int integer;
    short int shortInteger;
    char character;
    double doubleDecimal;
    float floatDecimal;
    bool boolean;
} GenericType;



GenericType castPointerToGenericType(void* pointer) {
    return (GenericType) pointer;
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

#endif