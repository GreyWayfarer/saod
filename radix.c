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
  int i;
  for (i = 0; i < size; i++) {
    mas1[i] = rand() % 100000 + 1;
  }
  double t1 = wtime();
  radixsort(mas1, size);
  double t2 = wtime();
  printf("| |\n");
  printf("|Radix_sort - %f sec|\n", t2 - t1);
  return 0;
}
