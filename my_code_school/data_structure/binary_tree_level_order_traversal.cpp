#include <iostream>
#include <queue>

struct Node
{
  char data;
  Node *left;
  Node *right;
};

void Insert(Node **root, char c)
{
  if (*root == NULL)
  {
    *root = new Node();
    (*root)->data = c;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  else if (c <= (*root)->data)
  {
    Insert(&((*root)->left), c);
  }
  else
  {
    Insert(&((*root)->right), c);
  }
}

void LevelOrder(Node *root)
{
  if (root == NULL)
    return;

  std::queue<Node *> q;

  q.push(root);

  while (!q.empty())
  {
    std::cout << q.front()->data;

    if (q.front()->left != NULL)
    {
      q.push(q.front()->left);
    }
    if (q.front()->right != NULL)
    {
      q.push(q.front()->right);
    }

    q.pop();
  }
}

void PreOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  std::cout << root->data;

  PreOrder(root->left);

  PreOrder(root->right);
}

void InOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  InOrder(root->left);

  std::cout << root->data;

  InOrder(root->right);
}

void PostOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  PostOrder(root->left);

  PostOrder(root->right);

  std::cout << root->data;
}

int main()
{
  Node *root = NULL;

  Insert(&root, 'F');
  Insert(&root, 'D');
  Insert(&root, 'B');
  Insert(&root, 'A');
  Insert(&root, 'E');
  Insert(&root, 'C');
  Insert(&root, 'J');
  Insert(&root, 'G');
  Insert(&root, 'K');
  Insert(&root, 'I');

  LevelOrder(root);
  std::cout << std::endl;
  PreOrder(root);
  std::cout << '\n';
  InOrder(root);
  std::cout << '\n';
  PostOrder(root);
  std::cout << '\n';
}
