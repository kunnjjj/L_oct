#include <iostream>
#include <cassert>
using namespace std;
int sum = 0;
class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
void find_in_subtree(node *root, int d, int k)
{
    if (root == NULL)
        return;
    if (d == k)
    {
        // ans.push_back(root->val);
        sum += root->data;
        return;
    }

    if (d > k)
        return; // we can ignore this case , because ultimatly above BC is gonna hit
    find_in_subtree(root->left, d + 1, k);
    find_in_subtree(root->right, d + 1, k);
}

node *buildTree()
{
    int d, n; // data, no. of children
    cin >> d >> n;
    node *root = new node(d);
    if (n == 0) // left
    {
    }
    if (n == 1)
    {
        root->left = buildTree();
    }
    if (n == 2)
    {
        root->left = buildTree();
        root->right = buildTree();
    }
    return root;
}
int main()
{
    // assert(condition); //if condition is false then error is thrown
    node *root = NULL;
    root = buildTree();
    int k;
    cin >> k;
    find_in_subtree(root, 0, k);
    cout << sum << endl;

    return 0;
}