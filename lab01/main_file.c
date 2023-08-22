#include "dict.h"
#include <stdio.h>
#include <stdlib.h>
// ... anything needed ...
// ...
int main(int argc, char *argv[]) {
  Dict d1;

  FILE *fp = fopen("input.txt", "r");
  char text[60];
  int n = atoi(fgets(text, 60, fp));
  d1 = ConsDict(n);
  while (fgets(text, 60, fp) != NULL) {
    InsertDict(d1, atoi(text));
  }
  DisplayDict(d1);
  SortDict(d1);
  DisplayDict(d1);
}
