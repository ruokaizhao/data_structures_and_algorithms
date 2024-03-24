#include <iostream>

void Merge(int left[], int right[], int A[], int leftLength, int rightLength)
{
  int i = 0, j = 0, k = 0;

  while (i < leftLength && j < rightLength)
  {
    if (left[i] <= right[j])
    {
      A[k] = left[i];
      i++;
    }
    else
    {
      A[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < leftLength)
  {
    A[k] = left[i];
    i++;
    k++;
  }

  while (j < rightLength)
  {
    A[k] = right[j];
    j++;
    k++;
  }
}

void MergeSort(int A[], int n)
{
  if (n < 2)
  {
    return;
  }

  int middle = n / 2;

  int *left = new int[middle];
  int *right = new int[n - middle];

  for (int i = 0; i < middle; i++)
  {
    left[i] = A[i];
  }
  for (int i = middle; i < n; i++)
  {
    right[i - middle] = A[i];
  }

  MergeSort(left, middle);
  MergeSort(right, n - middle);

  Merge(left, right, A, middle, n - middle);
}

void Print(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << A[i] << "\t";
  }
  std::cout << std::endl;
}

int main()
{
  int A[] = {2, 5, 51, 100, 8, 6, 78, 56, 45, 33, 1, 11, 12, 15, 19, 21, 14, 13, 3};

  int n = sizeof(A) / sizeof(int);

  Print(A, n);

  MergeSort(A, n);

  Print(A, n);
}
