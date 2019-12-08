#ifndef __IncludeGuard_AnyType
#include "impl/AnyType.c"
#endif

GenericType castPointerToGenericType(void* pointer);
GenericType castCharToGenericType(char value);
GenericType castIntToGenericType(int value);
GenericType castLongToGenericType(long value);
GenericType castBoolToGenericType(bool value);
GenericType castFloatToGenericType(float value);
GenericType castDoubleToGenericType(double value);
GenericType dataAt(void* pointer, int unitSize, int position);