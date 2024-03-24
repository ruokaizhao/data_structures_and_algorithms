#include <cstring>
#include <iostream>
#include <stack>

template <typename T>
class Stack
{
  T C[51];
  int topIndex = -1;

  public:
  void push(T c)
  {
    C[++topIndex] = c;
  }

  void pop()
  {
    topIndex--;
  }

  T top()
  {
    return C[topIndex];
  }

  bool isEmpty()
  {
    if (topIndex == -1)
      return true;
    return false;
  }
};

// void Reverse(char C[], int n)
// {
//   std::stack<char> S;
//
//   for (int i = 0; i < n; i++)
//   {
//     S.push(C[i]);
//   }
//
//   for (int i = 0; i < n; i++)
//   {
//     C[i] = S.top();
//     S.pop();
//   }
// }

void Reverse(char C[], int n)
{
  Stack<char> S;

  for (int i = 0; i < n; i++)
  {
    S.push(C[i]);
  }

  for (int i = 0; i < n; i++)
  {
    C[i] = S.top();
    S.pop();
  }
}

int main()
{
  char C[51];
  std::cout << "Enter a string: ";
  std::cin >> C;

  Reverse(C, strlen(C));

  std::cout << C << std::endl;
}
