#include <iostream>
#include <limits>

struct Node
{
  int data;
  Node *left;
  Node *right;
};

void Insert(Node **root, double i)
{
  if (*root == NULL)
  {
    *root = new Node();
    (*root)->data = i;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else if (i <= (*root)->data)
  {
    Insert(&((*root)->left), i);
  }
  else
  {
    Insert(&((*root)->right), i);
  }
}

bool IsSubtreeLesser(Node *root, int prevNodeData)
{
  if (root == NULL)
  {
    return true;
  }

  if (root->data <= prevNodeData && IsSubtreeLesser(root->left, prevNodeData) &&
      IsSubtreeLesser(root->right, prevNodeData))
  {
    return true;
  }

  return false;
}

bool IsSubtreeGreater(Node *root, int prevNodeData)
{
  if (root == NULL)
  {
    return true;
  }

  if (root->data > prevNodeData && IsSubtreeGreater(root->left, prevNodeData) &&
      IsSubtreeGreater(root->right, prevNodeData))
  {
    return true;
  }

  return false;
}

bool IsBinarySearchTree(Node *root)
{
  if (root == NULL)
  {
    return true;
  }

  if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data))
  {
    return IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right);
  }

  return false;
}

bool IsBinarySearchTreeRangeMethod(Node *root, double min, double max)
{
  if (root == NULL)
  {
    return true;
  }

  if (root->data > min && root->data <= max)
  {
    return IsBinarySearchTreeRangeMethod(root->left, min, root->data) &&
           IsBinarySearchTreeRangeMethod(root->right, root->data, max);
  }

  return false;
}

bool IsBinarySearchTreeInOrderMethod(Node *root, double &initialValue, int &count)
{
  if (root->left != NULL)
  {
    if (!IsBinarySearchTreeInOrderMethod(root->left, initialValue, count))
    {
      return false;
    }
  }

  if (count == 0)
  {
    initialValue = root->data;
    count++;
  }
  else
  {
    if (root->data < initialValue)
    {
      return false;
    }
  }

  if (root->right != NULL)
  {
    if (!IsBinarySearchTreeInOrderMethod(root->right, initialValue, count))
    {
      return false;
    }
  }
  return true;
}

int main()
{
  double infinity = std::numeric_limits<double>::infinity();
  Node *root = NULL;

  double initialValue;
  int count;

  Insert(&root, 6);
  Insert(&root, 4);
  Insert(&root, 2);
  Insert(&root, 1);
  Insert(&root, 5);
  Insert(&root, 3);
  Insert(&root, 10);
  Insert(&root, 7);
  Insert(&root, 11);
  Insert(&root, 9);

  bool isBST;

  if (root == NULL)
  {
    isBST = false;
  }
  else
  {
    isBST = IsBinarySearchTreeInOrderMethod(root, initialValue, count);
  }

  std::cout << isBST << std::endl;
}
