#include <bits/stdc++.h>

using namespace std;

template <typename T>

struct BST
{
    T data;
    BST *left, *right;

    BST(T data)
    {
        this->data = data;
        left = right = NULL;
    }
};

template <typename T>
BST<T> *insert(BST<T> *root, T key)
{
    if (!root)
        return new BST<T>(key);
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

template <typename T>
bool search(BST<T> *root, T key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

template <typename T>
BST<T> *remove(BST<T> *root, T key)
{
    if (!root)
        return root;
    else if (key < root->data)
    {
        root->left = remove(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = remove(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            BST<T> *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            BST<T> *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            BST<T> *inOrderNode = root->right;
            while (inOrderNode->left != NULL)
            {
                inOrderNode = inOrderNode->left;
            }
            root->data = inOrderNode->data;
            root->right = remove(root->right, inOrderNode->data);
        }
        return root;
    }
    return root;
}
template <typename T>
void preorder(BST<T> *root)
{
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
template <typename T>
void inorder(BST<T> *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
template <typename T>
void postorder(BST<T> *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}
template <typename T>
void levelorder(BST<T> *root)
{
    if (!root)
        return;
    queue<BST<T>
              *>
        nodesQueue;
    nodesQueue.push(root);
    while (nodesQueue.empty() == false)
    {
        BST<T> *temp = nodesQueue.front();
        nodesQueue.pop();
        cout << temp->data << " ";
        if (temp->left)
            nodesQueue.push(temp->left);

        if (temp->right)
            nodesQueue.push(temp->right);
    }
}

template <typename T>
int height(BST<T> *root)
{

    if (!root)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

template <typename T>
int size(BST<T> *root)
{
    if (!root)
        return 0;

    return 1 + size(root->left) + size(root->right);
}
int32_t main()
{
    BST<double> *tree1 = NULL;
    tree1 = new BST<double>(10);

    tree1 = insert(tree1, 5.0);
    tree1 = insert(tree1, 15.0);
    tree1 = insert(tree1, 8.0);
    tree1 = insert(tree1, 12.0);

    levelorder(tree1);

    cout << endl
         << height(tree1) << endl;
    cout << size(tree1) << endl;

    return 0;
}