#include <iostream>

struct Node
{
  int data;
  Node *next;
};

Node *top = NULL;

void Push(int x)
{
  Node *newNode = new Node();
  newNode->data = x;
  newNode->next = top;
  top = newNode;
}

void Pop()
{
  if (top == NULL)
  {
    return;
  }

  Node *temp = top;
  top = temp->next;
  delete temp;
}

int main()
{
}
