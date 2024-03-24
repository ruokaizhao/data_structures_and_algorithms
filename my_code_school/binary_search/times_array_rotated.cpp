#include <iostream>
#include <vector>

int FindRotateCount(std::vector<int> A)
{
  int low = 0, high = A.size() - 1;

  while (low <= high)
  {
    if (A[low] <= A[high])
    {
      return low;
    }

    int mid = low + (high - low) / 2;
    int prev = (mid + A.size() - 1) % A.size();
    int next = (mid + 1) % A.size();

    if (A[mid] <= A[prev] && A[mid] <= A[next])
    {
      return mid;
    }

    if (A[mid] <= A[high])
    {
      high = mid - 1;
    }
    else if (A[mid] >= A[low])
    {
      low = mid + 1;
    }
  }

  return -1;
}

int main()
{
  std::vector<int> A{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int count = FindRotateCount(A);

  std::cout << count << std::endl;
}
