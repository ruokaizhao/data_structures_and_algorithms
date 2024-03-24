#include <iostream>
#include <vector>

int CircularlySearch(std::vector<int> A, int x)
{
  int low = 0, high = A.size() - 1;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;

    if (x == A[mid])
    {
      return mid;
    }

    if (A[low] <= A[mid])
    {
      if (x >= A[low] && x < A[mid])
      {
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }
    else if (A[mid] <= A[high])
    {
      if (x <= A[high] && x > A[mid])
      {
        low = mid + 1;
      }
      else
      {
        high = mid - 1;
      }
    }
  }

  return -1;
}

int main()
{
  std::vector<int> A{5, 6, 7, 8, 9, 10, 1, 2, 3, 4};

  int x;
  std::cout << "Enter a number: ";
  std::cin >> x;

  int result = CircularlySearch(A, x);
  std::cout << result << std::endl;
}
