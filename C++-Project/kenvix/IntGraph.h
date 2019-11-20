#ifndef __IncludeGuard_IntGraph
#include "impl/IntGraph.c"
#endif

IntGraph* IntGraph_New(unsigned int count);
void IntGraph_FillData(IntGraph* graph, size offset, GenericType data);
void IntGraph_AddLink(IntGraph* graph, size weight, size fromOffset, size toOffset);
void IntGraph_AddBidirectionalLink(IntGraph* graph, size weight, size fromOffset, size toOffset);