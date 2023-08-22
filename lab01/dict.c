#include <error.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
typedef int *Dict;
Dict ConsDict(int size) {
  int *p = (int *)malloc((size + 2) * sizeof(int));
  p[0] = 0;
  p[1] = size;
  return p;
}

void BubbleSort(int *ptr, int n, int (*fx)()) {
  // Not sure if this is bubble sort, just randomly stole off the internet 
  int i, j, t;

  // Sort the numbers using pointers
  for (i = 0; i < n; i++) {

    for (j = i + 1; j < n; j++) {

      if (fx(*(ptr + j)) < fx(*(ptr + i))) {

        t = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = t;
      }
    }
  }
}
int x(int k){
return k;
}

int square(int k){
return k*k;
}
void SortDict(Dict d) {
  BubbleSort(d + 2, d[0], square);
  // Sort d[0]=actual count elements in it
}
void InsertDict(Dict d, int i) {
    // printf("Inserting %d", i);
  if (d[0] == d[1])
    error(-1, 0,"Dict full");
  d[d[0] + 2] = i;
  d[0] += 1;
}
void DisplayDict(Dict d) {
  int i;
  printf("Displaying dictionary with %d elements, size %d: ", d[0], d[1]);
  for (i = 2; i < d[0] + 2; i++) {
    printf("Element%02d=%d ", i - 1, d[i]);
  }
  printf("\n");
}
