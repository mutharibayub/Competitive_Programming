#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string tree2str(TreeNode* root) {
    if(!root)return "";
    string out = to_string(root->val);
    if(!root->left && !root->right)
    {
        return out;
    }
    else if(root->left && root->right)
    {
        out+="("+tree2str(root->left)+")";
        out+="("+tree2str(root->right)+")";
    }
    else if(root->right)
    {
        out+="()("+tree2str(root->right)+")";
    }
    else
    {
        out+="("+tree2str(root->left)+")";
    }
    return out;
}

int main()
{
    
    return 0;
}