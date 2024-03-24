#include <iostream>
#include <vector>

int FindFirst(std::vector<int> A, int x)
{
  int start = 0;
  int end = A.size() - 1;
  int result = -1;

  while (start <= end)
  {
    int middle = end + (start - end) / 2;

    if (A[middle] == x)
    {
      result = middle;
      end = middle - 1;
    }
    else if (A[middle] > x)
    {
      end = middle - 1;
    }
    else
    {
      start = middle + 1;
    }
  }
  return result;
}

int FindLast(std::vector<int> A, int x)
{
  int start = 0;
  int end = A.size() - 1;
  int result = -1;

  while (start <= end)
  {
    int middle = end + (start - end) / 2;

    if (A[middle] == x)
    {
      result = middle;
      start = middle + 1;
    }
    else if (A[middle] > x)
    {
      end = middle - 1;
    }
    else
    {
      start = middle + 1;
    }
  }
  return result;
}
int main()
{
  std::vector<int> A{1, 2, 3, 4, 5, 5, 5, 5, 5, 6, 7, 8, 9, 10};

  int x;
  std::cout << "Enter a number: ";
  std::cin >> x;

  int first = FindFirst(A, x);
  int last = FindLast(A, x);

  std::cout << last - first + 1 << std::endl;
}
