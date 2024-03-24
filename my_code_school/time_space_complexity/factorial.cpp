#include <iostream>

int Factorial(int n)
{
  if (n == 0)
  {
    return 1;
  }

  return n * Factorial(n - 1);
}

int main()
{
  int n;
  std::cout << "Input a number: ";
  std::cin >> n;

  int result = Factorial(n);
  std::cout << result << "\n";
}
