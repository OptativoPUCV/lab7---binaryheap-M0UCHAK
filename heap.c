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

void resizeHeap(Heap* pq) {
    if (pq -> size == pq -> capac) {
        pq -> capac *= 2; 

        pq -> heapArray = (heapElem*)realloc(pq->heapArray, sizeof(heapElem) * pq->capac);

        if (pq -> heapArray == NULL) {
            fprintf(stderr, "Error: No se pudo redimensionar el montículo.\n");
            exit(EXIT_FAILURE);
        }
    }
}

void heap_push(Heap* pq, void* data, int priority){

  resizeHeap(pq);

  heapElem newElem;
  newElem.data = data;
  newElem.priority = p;

  int index = pq->size;
  pq -> heapArray[index] = newElem;

  while (index > 0 && pq->heapArray[(index - 1) / 2].priority < pq -> heapArray[index].priority) {
    
    heapElem temp = pq->heapArray[index];
    pq -> heapArray[index] = pq -> heapArray[(index - 1) / 2];
    pq -> heapArray[(index - 1) / 2] = temp;

    index = (index - 1) / 2;
  }
  pq -> size++;
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