#include <iostream>
using namespace std;

void traversal(TreeNode* root, int &count, int &sum, int &nodeCount)
{
    if(!root)return;
    int count1 = 0, count2 = 0;
    int sum1 = 0, sum2 = 0;
    traversal(root->left, count1, sum1, nodeCount);
    traversal(root->right, count2, sum2, nodeCount);
    if((sum1+sum2+root->val)/(count1+count2+1) == root->val)nodeCount++;
    count += count1+count2+1;
    sum += sum1+sum2+root->val;
}

int averageOfSubtree(TreeNode* root) {
    int count=0,sum=0,nodeCount=0;
    traversal(root, count, sum, nodeCount);
    return nodeCount;
}

int main()
{

    return 0;
}