#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
       i++;
       swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high)
{
  if (low < high)
  {
    int piv = partition(array, low, high);
    quickSort(array, low, piv - 1);
    quickSort(array, piv + 1, high);
  }
}

int main()
{
  int size;
  printf("Enter the size of the array: ");
  scanf("%d",&size);
  int arr[size];
  printf("Enter the numbers:\n");
  for (int i = 0; i < size; ++i)
  {
    scanf("%d",&arr[i]);
  }
  printf("Unsorted Array\n");
  for (int i = 0; i < size; ++i)
    printf("%d  ", arr[i]);
  quickSort(arr, 0, size - 1);
  printf("\nSorted array in ascending order: \n");
  for (int i = 0; i < size; ++i)
    printf("%d  ", arr[i]);
}
