#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int CASH = 100;

void Play(int bet);

int main()
{
  int bet;

  std::cout << "Welcome to the Virtual Casino\n";
  std::cout << "Total cash = " << CASH << std::endl;

  while (CASH > 0)
  {
    std::cout << "What's your bet? $";
    std::cin >> bet;

    if (bet <= 0 || bet > CASH)
    {
      break;
    }

    Play(bet);

    std::cout << "**********************************\n";
  }
}

void Play(int bet)
{
  // std::string cards = "JQK";

  char *cards = (char *)malloc(1000000 * sizeof(char));
  cards[0] = 'J';
  cards[1] = 'Q';
  cards[2] = 'K';

  std::cout << "Shuffling...";

  srand(time(NULL));

  for (int i = 0; i < 5; i++)
  {
    int x = rand() % 3;
    int y = rand() % 3;
    int temp = cards[x];
    cards[x] = cards[y];
    cards[y] = temp;
  }

  int playerGuess;

  std::cout << "What's the position of queen - 1, 2, or 3?";
  std::cin >> playerGuess;

  if (cards[playerGuess - 1] == 'Q')
  {
    CASH += 3 * bet;
    std::cout << "You win ! Result = " << cards[0] << cards[1] << cards[2] << " Cash = " << CASH << std::endl;
  }
  else
  {
    CASH -= bet;
    std::cout << "You lose ! Result = " << cards[0] << cards[1] << cards[2] << " Cash = " << CASH << std::endl;
  }
}
