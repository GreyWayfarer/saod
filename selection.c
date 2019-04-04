#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

void printarr(int *mas, int size) {
  int i;
  printf("\n");
  for (i = 0; i < size; i++) {
    printf("%d", mas[i]);
  }
}

void swap(int *a, int *b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
}

void selectionSort(int *mas2, int size) {

  printf("| |\n");
  int i, j, min_id;
  for (i = 0; i < (size - 1); i++) {
    min_id = i;
    for (j = i + 1; j < size; j++)
      if (mas2[j] > mas2[min_id])
        min_id = j;
    swap(&mas2[min_id], &mas2[i]);
  }
}
int main() {
  srand(time(NULL));
  printf("Enter the number of elements in the arrays");
  int size;
  printf("\n------------\n");
  scanf("%d", &size);
  printf("------------\n");
  printf("______________\n");
  printf("| |\n");
  int mas2[size];
  int i;
  for (i = 0; i < size; i++) {
    mas2[i] = rand() % 100000 + 1;
  }
  double t1 = wtime();
  double t2 = wtime();
  t1 = wtime();
  selectionSort(mas2, size);
  t2 = wtime();
  printf("| |\n");
  printf("Selection_sort - %f sec|\n", t2 - t1);
  return 0;
}
