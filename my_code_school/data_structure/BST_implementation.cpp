#include <iostream>

struct BstNode
{
  int data;
  BstNode *left;
  BstNode *right;
};

BstNode *GetNewNode(int data)
{
  BstNode *newNode = new BstNode();
  newNode->data = data;
  newNode->left = newNode->right = NULL;

  return newNode;
}

void Insert(BstNode **root, int data)
{
  if (*root == NULL)
  {
    *root = GetNewNode(data);
  }
  else if (data <= (*root)->data)
  {
    Insert(&((*root)->left), data);
  }
  else
  {
    {
      Insert(&((*root)->right), data);
    }
  }
}

bool Search(BstNode **root, int data)
{
  if (*root == NULL)
    return false;
  else if (data == (*root)->data)
    return true;
  else if (data < (*root)->data)
    return Search(&(*root)->left, data);
  else
    return Search(&(*root)->right, data);
}

int FindHeight(BstNode *root)
{
  int leftHeight, rightHeight;
  if (root->left == NULL)
  {
    leftHeight = 0;
  }
  else
  {
    leftHeight = FindHeight(root->left) + 1;
  }

  if (root->right == NULL)
  {

    rightHeight = 0;
  }
  else
  {
    rightHeight = FindHeight(root->right) + 1;
  }

  if (leftHeight >= rightHeight)
  {
    return leftHeight;
  }
  else
  {
    return rightHeight;
  }
}

int main()
{
  BstNode *root = NULL;

  Insert(&root, 15);
  Insert(&root, 10);
  Insert(&root, 20);
  Insert(&root, 25);
  Insert(&root, 8);
  Insert(&root, 12);
  Insert(&root, 7);

  std::cout << FindHeight(root);
}
