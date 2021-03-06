#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int height(node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}
bool heightBal(node *root)
{

    if (root == NULL)
        return true;

    if (heightBal(root->left) == false)
    {
        return false;
    }
    if (heightBal(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (std::abs(lh - rh) <= 1)
    {
        return true;
    }
    else
        return false;
}

/*
            1
        2      3
      4         5
    6
  6
*/
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(6);
    root->right->right->left = new node(5);
    root->right->right->left->left = new node(5);
    // root->right->right->left->left->left = new node(5);
    // root->right->right->left->left->left->left = new node(5);
    // root->right->right->left->right->left->left = new node(5);

    cout << heightBal(root);
    // cout << height(root);

    return 0;
}