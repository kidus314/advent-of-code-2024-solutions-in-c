#include <stdio.h>


/********************************************************************************
 * Author: Kidus Wegayehu
 * Description: Solution to Advent of Code problems - Day 1
 * 
 * This program reads pairs of integers from a file, sorts them using quicksort,
 * and calculates the total sum of the absolute differences between corresponding
 * elements in the two arrays.
 * 
 * Functions:
 * - int partition(int arr[], int start, int end): Partitions the array for quicksort.
 * - void swap(int *a, int *b): Swaps two integers.
 * - void quick_sort(int input[], int start, int end): Sorts an array using quicksort.
 * 
 * Usage:
 * - Ensure the input file "AOC_day_1_input.txt" is in the same directory as the executable.
 * - The input file should contain pairs of integers separated by spaces or newlines.
 * 
 * Note:
 * - The size of the arrays is set to 1000. Adjust if necessary.
 ********************************************************************************/


int partition(int arr[], int start, int end);
void swap(int *a, int *b);
void quick_sort(int input[], int start, int end);

int main(void)
{
  int sum = 0, size = 1000;
int count = 0;
  int array_left[size], array_right[size];

  FILE *f_loc = fopen("AOC_day_1_input.txt", "r");

  if (f_loc == NULL)
  {

    printf("failed to open a file");
  }
  else
  {
    
    while (fscanf(f_loc, "%i%i", &array_left[count], &array_right[count]) == 2)
    {
      count++;
    }
  }
  printf("size of each array :%i\n",count);

  quick_sort(array_left, 0, count- 1);
  quick_sort(array_right, 0, count - 1);

  for (int i = 0; i < count; i++)
  {
int t=(array_left[i] - array_right[i]);
if(t<0){
  
  t=t*-1;
}
    sum += t;
  }

  printf("total sum of the distances is %i", sum);

  fclose(f_loc);

  return 0;
}

void quick_sort(int input[], int start, int end)
{
 if (start >= end){ // Base case
        return;}
  int pIndex = partition(input, start, end);

  quick_sort(input, start, pIndex - 1);
  quick_sort(input, pIndex + 1, end);
}

int partition(int arr[], int start, int end)
{

  int pivot = arr[end];

  int low = start - 1;

  for (int i = start; i < end ; i++)
  {

    if (arr[i] < pivot)
    {

      low++;

      swap(&arr[low], &arr[i]);
    }
  }

  swap(&arr[low + 1], &arr[end]);

  return low + 1; // partition index
}

void swap(int *a, int *b)
{

  int temp = *a;

  *a = *b;
  *b = temp;
}