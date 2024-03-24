#include <iostream>

// The n in a for loop can be changed in the loop body.

void Print(int n)
{
  for (int i = 0; i < n; i++)
  {
    std::cout << i << std::endl;
    n = n / 2;
  }
}

int main()
{
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  Print(n);
}
