#include <stdio.h>

/********************************************************************************
 * Author: Kidus Wegayehu
 * Description: Solution to Advent of Code problems - Day 2
 *
 * This program reads pairs of integers from a file, stores them in two arrays,
 * and calculates the total sum of elements in the second array that have a
 * corresponding match in the first array.
 *
 * Functions:
 * - int search_add(int arr_left[], int arr_right[], int size): Searches for matching
 *   elements between two arrays and calculates the sum of the matching elements.
 *
 * Usage:
 * - Ensure the input file "AOC_day_1_input.txt" is in the same directory as the executable.
 * - The input file should contain pairs of integers separated by spaces or newlines.
 *
 * Note:
 * - The size of the arrays is set to 1000. Adjust if necessary.
 ********************************************************************************/

int search_add(array_left, size);
int main(void)
{

  int size = 1000;
  int array_left[size], array_right[size];
  FILE *file;
  file = fopen("AOC_day_2_input.txt", "r");
  if (file == NULL)
  {

    printf("can't open a file, try again");
  }
  else
  {

    for (int i = 0; i < size;)
    {

      if (fscanf(file, "%i%i", &array_left[i], &array_right[i]) == 2)
      {
        i++;
      }
    }

    printf("%i", search_add(array_left, array_right, size));
  }
  fclose(file);
  return 0;
}

int search_add(int arr_left[], int arr_right[], int size)
{
  int sum = 0;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {

      if (arr_left[i] == arr_right[j])
      {

        sum += arr_right[j];
      }
    }
  }

  return sum;
}
