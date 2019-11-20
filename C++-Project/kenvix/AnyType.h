#ifndef __IncludeGuard_AnyType
#include "impl/AnyType.c"
#endif

GenericArray* GenericArray_New(size count);
void GenericArray_Destroy(GenericArray* array);
GenericType getNull();
GenericType castPointerToGenericType(void* pointer);
GenericType castCharToGenericType(char value);
GenericType castIntToGenericType(int value);
GenericType castLongToGenericType(long value);
GenericType castBoolToGenericType(bool value);
GenericType castFloatToGenericType(float value);
GenericType castDoubleToGenericType(double value);
GenericType castSizeToGenericType(size value);
GenericType dataAt(void* pointer, int unitSize, int position);