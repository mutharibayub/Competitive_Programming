#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int getParent(vector<int> &parents, int v)
{
    if(v!=parents[v])
    {
        parents[v] = getParent(parents, parents[v]);
    }
    return parents[v];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> al(n);
        vector<int> parents(n,-1);
        vector<int> size(n,1);
        for(int i=0;i<n;i++)parents[i]=i;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<n;j++)
            {
                if(s[j]=='1')
                {
                    int p1=getParent(parents, i),p2=getParent(parents, j);
                    if(parents[max(p1,p2)]!=min(p1,p2))
                    {
                        parents[max(p1,p2)]=min(p1,p2);
                        size[min(p1,p2)]+=size[max(p1,p2)];
                    }
                    al[i].push_back(j);
                }
            }
        }
        if(size[getParent(parents, 0)]==n)
        {
            cout << 0 << '\n';
        }
        else
        {
            int nodeNum = -1;
            int nn = -1;
            set<int> sets;
            for(int i=0;i<n;i++)
            {
                sets.insert(getParent(parents, i));
                if(nodeNum==-1||al[i].size()<al[nodeNum].size())
                {
                    nodeNum=i;
                }
                if(al[i].size()<size[getParent(parents,i)]-1)
                {
                    if(nn==-1 || al[i].size()<al[nn].size())
                    {
                        nn=i;
                    }
                }
            }
            if(nn!=-1)
            {
                cout << "1\n" << nn+1 << '\n';
            }
            else if(al[nodeNum].size()==0)
            {
                cout << "1\n" << nodeNum+1 << '\n';
            }
            else if(sets.size()>2)
            {
                cout << "2\n";
                int i=0;
                for(auto it:sets)
                {
                    cout << it+1 << ' ';
                    i++;
                    if(i==2)break;
                }cout << '\n';
            }
            else
            {
                cout << al[nodeNum].size()+1 << '\n';
                for(int i=0;i<al[nodeNum].size();i++)
                {
                    cout << al[nodeNum][i]+1 << ' ';
                }cout << nodeNum+1 << '\n';
            }
        }
    }

    return 0;
}