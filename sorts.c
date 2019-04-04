#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <inttypes.h>

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

int findLargestNum(int *mas1, int size) {
  int i;
  int largestNum = -1;

  for (i = 0; i < size; i++) {
    if (mas1[i] > largestNum)
      largestNum = mas1[i];
  }

  return largestNum;
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

void radixsort(int *mas1, int size) {
  printf("| |\n");

  printf("|Running Radix_sort on Unsorted array!|\n");

  int i;
  int semiSorted[size];
  int significantDigit = 1;
  int largestNum = findLargestNum(mas1, size);

  while (largestNum / significantDigit > 0) {
    int bucket[10] = {0};

    for (i = 0; i < size; i++)
      bucket[(mas1[i] / significantDigit) % 10]++;

    for (i = 1; i < 10; i++)
      bucket[i] += bucket[i - 1];

    for (i = size - 1; i >= 0; i--)
    semiSorted[--bucket[(mas1[i] / significantDigit) % 10]] = mas1[i];

    for (i = 0; i < size; i++)
      mas1[i] = semiSorted[i];

    significantDigit *= 10;
  }
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
  int mas1[size];
  int mas2[size];
  int mas3[size];
  int i;
  for (i = 0; i < size; i++) {
    mas1[i] = rand() % 100000 + 1;
  }
  for (i = 0; i < size; i++) {
    mas2[i] = mas1[i];
    mas3[i] = mas1[i];
  }
  double t1 = wtime();
  radixsort(mas1, size);
  double t2 = wtime();
  printf("| |\n");
  printf("|Radix_sort - %f sec|\n", t2 - t1);
  t1 = wtime();
  selectionSort(mas2, size);
  t2 = wtime();
  printf("| |\n");
  printf("Selection_sort - %f sec|\n", t2 - t1);
  printf("| |\n");
  t1 = wtime();
  heapSort(mas3, size);
  t2 = wtime();
  printf("| |\n");
  printf("|Heap_sort - %f sec|\n", t2 - t1);
  printf("___________________\n");
  return 0;
}
