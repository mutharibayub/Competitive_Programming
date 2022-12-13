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

bool cmpFunc(const TreeNode &t1, const TreeNode &t2)
{
    TreeNode tt1=t1,tt2=t2;
    return comp(tt1,tt2)<0;
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

    int idx=1;

    array<TreeNode, 2> li;
    parse("[[2]]",(idx=1),li[0]);
    parse("[[6]]",(idx=1),li[1]);

    for(int i=0;i<2;i++)tn.push_back(li[i]);

    sort(tn.begin(), tn.end(), cmpFunc);

    int ans=1;

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<tn.size();j++)
        {
            if(comp(tn[j],li[i])==0)
            {
                ans *= j+1;
                break;
            }
        }
    }

    cout << ans << '\n';
 
    return 0;
}