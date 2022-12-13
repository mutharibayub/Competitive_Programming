#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <array>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

struct TreeNode
{
    int val=-1;
    vector<TreeNode> children;
    TreeNode(){}
    TreeNode(int v):val(v){}
};

void parse(const string &s, int &idx, TreeNode &root)
{
    for(int &i=idx;s[i];i++)
    {
        if(s[i]=='[')
        {
            root.children.push_back(TreeNode());
            i++;
            parse(s, i, root.children.back());
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            string tmp="";
            while(s[i]>='0'&&s[i]<='9')
            {
                tmp.push_back(s[i]);
                i++;    
            }
            i--;
            root.children.push_back(TreeNode(stoi(tmp)));
        }
        else if(s[i]==']')
        {
            i++;
            return;
        }
    }
}

int comp(TreeNode &t1, TreeNode &t2)
{
    if(t1.val!=-1 && t2.val!=-1)
    {   
        if(t1.val<t2.val)return -1;
        else if(t1.val==t2.val)return 0;
        else return 1;
    }
    else if(t1.val!=-1||t2.val!=-1)
    {
        if(t2.val!=-1)
        {
            t2.children.push_back(TreeNode(t2.val));
            t2.val=-1;
        }
        else
        {
            t1.children.push_back(TreeNode(t1.val));
            t1.val=-1;
        }
    }
    for(int i=0;i<t1.children.size()&&i<t2.children.size();i++)
    {
        int cmp = comp(t1.children[i], t2.children[i]);
        if(cmp==0)continue;
        return cmp;
    }
    if(t1.children.size()==t2.children.size())return 0;
    else if(t1.children.size()<t2.children.size())return -1;
    else return 1;
}

int main()
{
    string filename = "13input.txt";
    ifstream fin(filename);

    vector<TreeNode> tn;
    while(!fin.eof())
    {
        string tmp;
        fin>>tmp;
        if(tmp=="")
        {
            break;
        }
        tn.push_back(TreeNode());
        int idx=1;
        parse(tmp, idx, tn.back());
    }

    int ans=0;
    for(int i=0;i<tn.size();i+=2)
    {
        if(comp(tn[i], tn[i+1])<=0)
        {
            ans+=i/2+1;
        }
    }
    cout << ans << '\n';
 
    return 0;
}