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

void heapify(int *mas3, int size, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if ((l < size) && (mas3[l] > mas3[largest]))
    largest = l;
  if ((r < size) && (mas3[r] > mas3[largest]))
    largest = r;
  if (largest != i) {
    swap(&mas3[i], &mas3[largest]);
    heapify(mas3, size, largest);
  }
}

void heapSort(int *mas3, int size) {
  int i;
for (i = size/2-1; i>=0; i--)
{
    heapify(mas3, size, i);
}
for (int i = size - 1; i >= 0; i--)
{
    swap(&mas3[0], &mas3[i]);
    heapify(mas3, i, 0);
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
  int mas3[size];
  int i;
  for (i = 0; i < size; i++) {
    mas3[i] = rand() % 100000 + 1;
  }
  double t1 = wtime();
  double t2 = wtime();
  t1 = wtime();
  heapSort(mas3, size);
  t2 = wtime();
  printf("| |\n");
  printf("|Heap_sort - %f sec|\n", t2 - t1);
  return 0;
}
