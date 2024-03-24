#include <iostream>
#include <string>
#include <thread>

int main()
{
  std::string word;
  std::cout << "Enter a word: ";
  std::cin >> word;

  auto lambdaFunc = [](std::string s) { std::cout << s << std::endl; };
  std::thread threadOne(lambdaFunc, word);

  threadOne.join();

  std::cout << "main executing.\n";
}
