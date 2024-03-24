#include <iostream>

struct Node
{
  int data;
  Node *next;
};

Node *head;

void Print()
{
  Node *temp = head;

  while (temp != NULL)
  {
    std::cout << temp->data;
    temp = temp->next;
  }

  std::cout << std::endl;
}

void Insert(int data, int n)
{
  Node *temp1 = new Node();
  temp1->data = data;
  temp1->next = NULL;

  if (n == 1)
  {
    temp1->next = head;
    head = temp1;
    return;
  }

  Node *temp2 = head;
  for (int i = 1; i < n - 1; i++)
  {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Delete(int n)
{

  Node *temp1 = head;
  if (n == 1)
  {
    head = head->next;
    delete temp1;
    return;
  }

  for (int i = 0; i < n - 2; i++)
  {
    temp1 = temp1->next;
  }
  Node *temp2 = temp1->next;
  temp1->next = temp1->next->next;
  delete temp2;
}

int main()
{
  head = NULL;
  Insert(2, 1);
  Insert(5, 2);
  Insert(4, 1);
  Insert(3, 2); // 4325
  Insert(6, 4);
  Print();

  while (head != NULL)
  {
    std::cout << "Enter a position: \n";
    int n;
    std::cin >> n;
    Delete(n);
    Print();
  }
}
