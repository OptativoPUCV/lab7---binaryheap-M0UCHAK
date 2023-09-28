#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){

  if (pq == NULL || pq -> size == 0) return NULL;
  return pq -> heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
    if (pq == NULL) {
        fprintf(stderr, "Error: El montículo es nulo.\n");
        return;
    }

    if (pq->size >= pq->capac) {
        pq->capac *= 2; // Duplicar la capacidad
        pq->heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * pq->capac);

        if (pq->heapArray == NULL) {
            fprintf(stderr, "Error: No se pudo aumentar la capacidad del montículo.\n");
            exit(EXIT_FAILURE);
        }
    }

    int currentIndex = pq->size;
    pq->heapArray[currentIndex].data = data;
    pq->heapArray[currentIndex].priority = p;
    pq->size++;

    while (currentIndex > 0) {
        int parentIndex = (currentIndex - 1) / 2;
        if (pq->heapArray[currentIndex].priority > pq->heapArray[parentIndex].priority) {
          
            heapElem temp = pq->heapArray[currentIndex];
            pq->heapArray[currentIndex] = pq->heapArray[parentIndex];
            pq->heapArray[parentIndex] = temp;
            currentIndex = parentIndex;
        } else {
            break;
        }
    }
}

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){

Heap* newHeap = (Heap*)malloc(sizeof(Heap));

if (newHeap == NULL) exit(EXIT_FAILURE);
    
newHeap -> capac = 3;
newHeap -> size = 0;
newHeap -> heapArray = (heapElem*)malloc(sizeof(heapElem) * newHeap->capac);

  if (newHeap->heapArray == NULL) {
    free(newHeap);
    exit(EXIT_FAILURE);
  }
  return newHeap;
}