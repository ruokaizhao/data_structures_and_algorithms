#include <iostream>

int A[100];

int Fibonacci(int n)
{
  if (n <= 1)
  {
    return n;
  }

  if (A[n] != -1)
  {
    return A[n];
  }

  A[n] = Fibonacci(n - 1) + Fibonacci(n - 2);

  return A[n];
}

int main()
{
  for (int i = 0; i < 100; i++)
  {
    A[i] = -1;
  }
  int n;
  std::cout << "Enter a number: ";
  std::cin >> n;

  int result = Fibonacci(n);
  std::cout << result << std::endl;
}
