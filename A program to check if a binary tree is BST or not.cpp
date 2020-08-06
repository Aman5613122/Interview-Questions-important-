// there is two method to solve this question.
// I coded for both of them.

//1.By using min and max node which check the root->left and root->right conditions, if this satisfy all the conditions then it return 1 otherwise 0.

//2.By using Inorder traversal, If the tree is Binary Search tree then at the time of inorder traversal we push the data to the vector is that vector is in increasing order then it is BST.


1.

#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include<queue>
#include<unordered_map>
#define ll long long

using namespace std;

class Node{
public:
    int data;
    Node *left,*right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

int solve(Node *root,Node *mini, Node *maxi)
{
   if(!root)
   {
       return 1;
   }

   if(mini != NULL && mini->data >= root->data)
   {
       return 0;
   }

   if(maxi != NULL && maxi->data <= root->data)
   {
       return 0;
   }

   return solve(root->left,mini,root) && solve(root->right,root,maxi);

}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << solve(root,NULL,NULL) <<endl;
    return 0;
}



2.


#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include<queue>
#include<unordered_map>
#define ll long long

using namespace std;

class Node{
public:
    int data;
    Node *left,*right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

vector<int>v;

void solve(Node *root)
{
   if(!root)
   {
       return;
   }
   solve(root->left);
   v.push_back(root->data);
   solve(root->right);
}

int main()
{

    Node *root = new Node(4);
    root->left = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    solve(root);

    if(is_sorted(v.begin(),v.end()))
    {
        cout << "1";
    }
    else{
        cout << "0";
    }
    return 0;
}
