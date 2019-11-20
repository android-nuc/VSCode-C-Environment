#ifndef __IncludeGuard_IntGraph
#define __IncludeGuard_IntGraph

#include <stdlib.h>
#include <stddef.h>
#include "../AnyType.h"
#include "../LinkedList.h"

typedef struct IntGraphConnectionTable {
    LinkedList* in;
    LinkedList* out;
    GenericType data;
} IntGraphConnectionTable;

typedef struct IntGraphLink {
    int weight;
    size to;
    size from;
} IntGraphLink;

typedef struct IntGraph {
    IntGraphConnectionTable* connections;
    size count;
    bool isAdjacencyMatrixUpToDate;
    size* adjacencyMatrixCache;
} IntGraph;

IntGraph* IntGraph_New(size count) {
    IntGraph* graph = (IntGraph*) malloc(sizeof(IntGraph));
    graph->count = count;
    graph->isAdjacencyMatrixUpToDate = false;
    graph->connections = (IntGraphConnectionTable*) malloc(sizeof(IntGraphConnectionTable) * count);

    for (size i = 0; i < count; i++) {
        IntGraphConnectionTable* conn = graph->connections + i;
        conn->in = LinkedList_New();
        conn->out = LinkedList_New();
        conn->data = getNull();
    }

    return graph;
}

void IntGraph_FillData(IntGraph* graph, size offset, GenericType data) {
    (graph->connections + offset)->data = data;
}

void IntGraph_AddLink(IntGraph* graph, size weight, size fromOffset, size toOffset) {
    graph->isAdjacencyMatrixUpToDate = false;
    IntGraphLink* link = (IntGraphLink*) malloc(sizeof(IntGraphLink));
    link->weight = weight;
    link->from = fromOffset;
    link->to = toOffset;

    LinkedList_Add((graph->connections + fromOffset)->out, castPointerToGenericType(link));
    LinkedList_Add((graph->connections + toOffset)->in, castPointerToGenericType(link));
}

void IntGraph_AddBidirectionalLink(IntGraph* graph, size weight, size fromOffset, size toOffset) {
    IntGraph_AddLink(graph, weight, toOffset, fromOffset);
    IntGraph_AddLink(graph, weight, fromOffset, toOffset);
}

void _intGraphAdjacencyMatrixCallback(GenericType value, size order, GenericType env) {
    size* matrix = (size*) env.pointer;
    IntGraphLink* link = (IntGraphLink*) value.pointer;

    matrix[link->to] = link->weight;
}

size* IntGraph_GetAdjacencyMatrix(IntGraph* graph) {
    if (graph->isAdjacencyMatrixUpToDate) 
        return graph->adjacencyMatrixCache;

    free(graph->adjacencyMatrixCache);
    size* matrix = (size*) malloc(sizeof(size) * graph->count * graph->count);

    for (size i = 0; i < graph->count; i++) {
        LinkedList_Traversal((graph->connections + i)->out, _intGraphAdjacencyMatrixCallback, castPointerToGenericType(matrix + i * graph->count));
        //LinkedList_Traversal((graph->connections + i)->in, _intGraphAdjacencyMatrixCallback,  castPointerToGenericType(matrix + i * graph->count));
    }

    graph->adjacencyMatrixCache = matrix;
    graph->isAdjacencyMatrixUpToDate = true;
    return matrix;    
} 

GenericArray* IntGraph_GetDijkstraMinPath(IntGraph* graph, size fromOffset, size toOffset) {
    
}

#endif