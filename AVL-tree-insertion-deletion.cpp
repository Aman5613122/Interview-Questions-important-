#include<bits/stdc++.h>
#define ll long long

using namespace std;

class Node{
public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
};


int height(Node *temp)
{
    if(!temp)
    {
        return 0;
    }
    return temp->height;
}

int getbalance(Node *temp)
{
    if(!temp)
    {
        return 0;
    }
    return height(temp->left) - height(temp->right);
}

Node* rightrotation(Node *root)
{
    Node *x = root->left;
    Node *t = x->right;

    x->right = root;
    root->left = t;

    root->height = 1 + max(height(root->left),height(root->right));
    x->height = 1 + max(height(root->left),height(root->right));

    return x;
}

Node * leftrotation(Node *root)
{
    Node *x = root->right;
    Node *t = x->left;

    x->left = root;
    root->right = t;

    root->height = 1 + max(height(root->left),height(root->right));
    x->height = 1 + max(height(root->left),height(root->right));

    return x;
}

Node* avl(Node *root,int val)
{
    if(!root)
    {
        return (new Node(val));
    }

    if(root->data < val)
    {
        root->right = avl(root->right,val);
    }
    else if(root->data > val)
    {
        root->left = avl(root->left,val);
    }
    else{
        return root;
    }

    //find the height of the tree

    root->height = 1 + max(height(root->left),height(root->right));

    //find if the tree is balanced or not

    int balanced = getbalance(root);

    //Now check which case is apply on it

    //left-left case
    if(balanced > 1 && root->left->data > val)
    {
        return rightrotation(root);
    }

    //right-right case
    if(balanced < -1 && root->right->data < val)
    {
        return leftrotation(root);
    }

    //left-right case
    if(balanced > 1 && root->left->data < val)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    //right->left case
    if(balanced < -1 && root->right->data > val)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

void inorder(Node *root)
{
    if(!root)
        return;
    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}

Node *minvalue(Node *curr)
{
    while(curr->left != NULL)
    {
        curr= curr->left;
    }
    return curr;
}

Node *del(Node *root,int key)
{
    if(!root)
    {
        return root;
    }

    if(root->data < key)
    {
        root->right = del(root->right,key);
    }
    else if(root->data > key)
    {
        root->left = del(root->left,key);
    }
    else{
        //if key has only two child

        if(root->left == NULL || root->right == NULL)
        {
            Node *temp = NULL;
            temp = root->left?root->left:root->right;

            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else{
                root->data = temp->data;
                root->left = NULL;
                root->right = NULL;
            }
            delete(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minvalue(root->right);

            // Copy the inorder successor's
            // data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = del(root->right,
                                     temp->data);
        }
    }

    if(!root)
    {
        return root;
    }

        //find the height of the tree

    root->height = 1 + max(height(root->left),height(root->right));

    //find if the tree is balanced or not

    int balanced = getbalance(root);

    //Now check which case is apply on it

    //left-left case
    if (balanced > 1 &&
        getbalance(root->left) >= 0)
        return rightrotation(root);

    // Left Right Case
    if (balanced > 1 &&
        getbalance(root->left) < 0)
    {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // Right Right Case
    if (balanced < -1 &&
        getbalance(root->right) <= 0)
        return leftrotation(root);

    // Right Left Case
    if (balanced < -1 &&
        getbalance(root->right) > 0)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    root = avl(root,10);
    root = avl(root,20);
    root = avl(root,30);
    root = avl(root,40);
    root = avl(root,50);
    root = avl(root,25);

    inorder(root);

    del(root,40);
    cout << endl;
    inorder(root);
    return 0;
}
