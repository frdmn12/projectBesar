#include <stdio.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort(int arr[], int size)
{
  int step, i;
  for (step = 0; step < size - 1; step++)
  {
    int min_idx = step;
    for (i = step + 1; i < size; i++)
    {
      if (arr[i] < arr[min_idx])
        min_idx = i;
    }
    swap(&arr[min_idx], &arr[step]);
  }
}
void printArr(int arr[], int size)
{
  int i;
  for (i = 0; i < size; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main()
{
  int data[] = {80, 40, 20, 76, 11, 35};
  int size = sizeof(data) / sizeof(data[0]);
  printf("Data senbelum diuruitkan :\n");
  printArr(data, size);
  sort(data, size);
  // printf("ini data = %d\nini size %d\n", data, size);
  printf("Data yang diurutkan dalam urutan menaik :\n");
  printArr(data, size);
}
