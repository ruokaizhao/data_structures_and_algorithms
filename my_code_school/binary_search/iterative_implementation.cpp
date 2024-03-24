#include <iostream>
#include <vector>

int BinarySearch(std::vector<int> A, int x)
{
  int start = 0;
  int end = A.size() - 1;

  while (start <= end)
  {
    int mid = (start + end) / 2;
    if (A[mid] == x)
    {
      return mid;
    }
    else if (A[mid] > x)
    {
      end = mid - 1;
    }
    else
    {
      start = mid + 1;
    }
  }

  return -1;
}

int main()
{
  std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  int x;

  std::cout << "Enter a number: ";
  std::cin >> x;
  std::cout << BinarySearch(A, x);
  std::cout << std::endl;
}
