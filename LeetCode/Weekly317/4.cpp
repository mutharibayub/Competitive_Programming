#include <iostream>
#include <vector>
#include <array>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int n = 1e5+1;
    vector<int> height = vector<int>(n, -1);
    vector<int> pathLength = vector<int>(n, -1);
    void calcHeight(TreeNode* root)
    {
        vector<TreeNode*> stk;
        stk.push_back(root);
        while(!stk.empty())
        {
            TreeNode *top = stk.back();
            auto &h=height[top->val];
            int done = 0;
            if(top->left)
            {
                if(height[top->left->val]==-1)
                {
                    stk.push_back(top->left);
                }
                else
                {
                    h = max(h, height[top->left->val]+1);
                    done++;
                }
            }
            else
            {
                h=max(h, 0);
                done++;
            }
            if(top->right)
            {
                if(height[top->right->val]==-1)
                {
                    stk.push_back(top->right);
                }
                else
                {
                    h = max(h, height[top->right->val]+1);
                    done++;
                }
            }
            else
            {
                h=max(h,0);
                done++;
            }
            if(done==2)stk.pop_back();
        }
    }
    void solve(TreeNode *root, int maxp)
    {
        vector<pair<TreeNode*, array<int, 2>>> stk;
        stk.emplace_back(root, array<int, 2>({0, maxp}));
        stk.reserve(n);
        while(!stk.empty())
        {
            int depth = stk.back().second[0];
            int maxp = stk.back().second[1];
            TreeNode *top = stk.back().first;
            stk.pop_back();
            pathLength[top->val] = maxp;
            if(top->left)
                stk.emplace_back(top->left, array<int, 2>({depth+1, max(maxp, (top->right?height[top->right->val]+1:0)+depth)}));
            if(top->right)
                stk.emplace_back(top->right, array<int, 2>({depth+1, max(maxp, (top->left?height[top->left->val]+1:0)+depth)}));
        }
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        calcHeight(root);
        solve(root, 0);
        vector<int> ans;
        for(auto q:queries)
        {
            ans.push_back(pathLength[q]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    // cout << s.makeIntegerBeautiful(16,6) << '\n';

    return 0;
}
