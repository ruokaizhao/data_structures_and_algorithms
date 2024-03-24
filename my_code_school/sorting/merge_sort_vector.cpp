#include <iostream>
#include <vector>

void Print(std::vector<int> A)
{
  for (int i : A)
  {
    std::cout << i << "\t";
  }
  std::cout << std::endl;
}

void Merge(std::vector<int> &left, std::vector<int> &right, std::vector<int> &A)
{
  int i = 0;
  int j = 0;
  int k = 0;

  while (i < left.size() && j < right.size())
  {
    if (left.at(i) <= right.at(j))
    {
      A.at(k) = left.at(i);
      i++;
    }
    else
    {
      A.at(k) = right.at(j);
      j++;
    }
    k++;
  }

  while (i < left.size())
  {
    A.at(k) = left.at(i);
    i++;
    k++;
  }

  while (j < right.size())
  {
    A.at(k) = right.at(j);
    j++;
    k++;
  }
}

void MergeSort(std::vector<int> &A)
{
  int n = A.size();
  if (n < 2)
  {
    return;
  }

  int middle = n / 2;

  std::vector<int> left;
  std::vector<int> right;

  for (int i = 0; i < middle; i++)
  {
    left.push_back(A[i]);
  }
  for (int i = middle; i < n; i++)
  {
    right.push_back(A[i]);
  }

  MergeSort(left);
  MergeSort(right);

  Merge(left, right, A);
}

int main()
{
  std::vector<int> A{2, 5, 51, 100, 8, 6, 78, 56, 45, 33, 1, 11, 12, 15, 19, 21, 14, 13, 3};

  Print(A);

  MergeSort(A);

  Print(A);
}
