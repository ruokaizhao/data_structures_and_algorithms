#include <iostream>

struct Node
{
  int data;
  Node *left;
  Node *right;
};

void Insert(Node *&root, int data)
{
  if (root == NULL)
  {
    root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
  }
  else if (root->data >= data)
  {
    Insert(root->left, data);
  }
  else
  {
    Insert(root->right, data);
  }
}

void InOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  InOrder(root->left);
  std::cout << root->data << std::endl;
  InOrder(root->right);
}

Node *Find(Node *root, int data)
{
  if (root == NULL)
  {
    return NULL;
  }

  if (root->data > data)
  {
    return Find(root->left, data);
  }

  if (root->data < data)
  {
    return Find(root->right, data);
  }

  return root;
}

Node *FindMin(Node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }

  return root;
}

Node *FindMax(Node *root)
{
  while (root->right != NULL)
  {
    root = root->right;
  }

  return root;
}

Node *FindPredecessor(Node *root, int data)
{
  Node *current = Find(root, data);

  if (current == NULL)
  {
    return NULL;
  }

  if (current->left != NULL)
  {
    return FindMax(root->left);
  }
  else
  {
    Node *predecessor = NULL;
    Node *ancestor = root;

    while (ancestor != current)
    {
      if (current->data < ancestor->data)
      {
        ancestor = ancestor->left;
      }
      else
      {
        predecessor = ancestor;
        ancestor = ancestor->right;
      }
    }

    return predecessor;
  }
}

Node *FindSuccessor(Node *root, int data)
{
  Node *current = Find(root, data);

  if (current == NULL)
  {
    return NULL;
  }

  if (current->right != NULL)
  {
    return FindMin(current->right);
  }
  else
  {
    Node *successor = NULL;
    Node *ancestor = root;
    while (ancestor != current)
    {
      if (current->data < ancestor->data)
      {
        successor = ancestor;
        ancestor = ancestor->left;
      }
      else
      {
        ancestor = ancestor->right;
      }
    }

    return successor;
  }
}

int main()
{
  Node *root = NULL;
  Insert(root, 6);
  Insert(root, 4);
  Insert(root, 2);
  Insert(root, 1);
  Insert(root, 5);
  Insert(root, 3);
  Insert(root, 10);
  Insert(root, 7);
  Insert(root, 11);
  Insert(root, 9);

  Node *predecessor = FindPredecessor(root, 5);

  if (predecessor == NULL)
  {
    std::cout << "There is no ancestor.\n";
  }
  else
  {
    std::cout << predecessor->data << std::endl;
  }

  Node *successor = FindSuccessor(root, 5);

  if (successor == NULL)
  {
    std::cout << "There is no successor.\n";
  }
  else
  {
    std::cout << successor->data << std::endl;
  }
}
