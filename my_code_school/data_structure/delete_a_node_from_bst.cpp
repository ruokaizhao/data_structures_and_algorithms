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
  else if (data <= root->data)
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

Node *FindMin(Node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }

  return root;
}

Node *Delete(Node *root, int data)
{
  if (root == NULL)
  {
    return root;
  }

  if (data < root->data)
  {
    root->left = Delete(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = Delete(root->right, data);
  }
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      root = NULL;
    }
    else if (root->left == NULL)
    {
      Node *temp = root;
      root = root->right;
      delete temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root;
      root = root->left;
      delete temp;
    }
    else
    {
      Node *minInRightSubTree = FindMin(root->right);
      root->data = minInRightSubTree->data;
      root->right = Delete(root->right, minInRightSubTree->data);
    }
  }
  return root;
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

  root = Delete(root, 6);
  root = Delete(root, 2);
  root = Delete(root, 1);
  root = Delete(root, 7);
  root = Delete(root, 9);
  root = Delete(root, 4);
  root = Delete(root, 10);
  // root = Delete(root, 3);
  // root = Delete(root, 11);
  // root = Delete(root, 5);

  InOrder(root);
}
