#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <cassert>

using namespace std;

typedef long long ll;

#define tst int tttt;cin>>tttt;while(tttt--)

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int,int> sqrt;
    for(int i=3;i*i<=2e5;i++)
    {
        sqrt[i*i]=i;
    }

    tst
    {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> al(n);
        for(int i=0;i<m;i++)
        {
            int u, v;
            cin>>u>>v;
            --u,--v;
            al[u].push_back(v);
            al[v].push_back(u);
        }

        vector<set<int>> components;
        {
            vector<bool> done(n, false);
            for(int i=0;i<n;i++)
            {
                if(done[i])continue;
                components.push_back(set<int>());
                vector<int> stk;
                stk.push_back(i);
                done[i]=true;
                components.back().insert(i);
                while(!stk.empty())
                {
                    int u=stk.back();
                    stk.pop_back();
                    for(auto v:al[u])
                    {
                        if(done[v])continue;
                        done[v]=true;
                        components.back().insert(v);
                        stk.push_back(v);
                    }
                }
            }
        }

        if(components.size()>1)
        {
            cout << "NO" << '\n';
            continue;
        }

        bool found=components.size()!=1;
        for(int ii=0;ii<components.size()&&!found;ii++)
        {
            if(sqrt.find(components[ii].size())==sqrt.end())continue;
            bool ok=true;

            int k=sqrt[components[ii].size()];
            vector<int> cnts(5, 0);
            for(auto u:components[ii])
            {
                if(al[u].size()!=4&&al[u].size()!=2)
                {
                    ok=false;
                    break;
                }
                cnts[al[u].size()]++;
            }
            if(!ok||cnts[4]!=k||cnts[2]!=k*k-k)continue;
            
            int ptr=-1;
            for(auto u:components[ii])
            {
                if(al[u].size()==4)
                {
                    ptr=u;
                    break;
                }
            }assert(ptr!=-1);

            set<int> centerRing;
            for(int i=0;i<k&&ok;i++)
            {
                ok=false;
                for(auto v:al[ptr])
                {
                    if(al[v].size()==4&&centerRing.find(v)==centerRing.end())
                    {
                        ok=true;
                        ptr=v;
                        centerRing.insert(ptr);
                        break;
                    }
                }
            }ok&=(centerRing.size()==k);
            if(!ok)continue;

            set<int> done;
            for(auto u:centerRing)
            {
                ptr=u;
                for(int i=0;i<k&&ok;i++)
                {
                    ok=false;
                    int targetArms = (i==k-1)?4:2;
                    for(auto v:al[ptr])
                    {
                        if(al[v].size()==targetArms&&done.find(v)==done.end())
                        {
                            ok=true;
                            ptr=v;
                            done.insert(ptr);
                            break;
                        }
                    }
                }
                if(ptr!=u)ok=false;
                if(!ok)break;
            }
            if(!ok)continue;
            found=true;
        }
        cout << (found?"YES":"NO") << '\n';
    }

    return 0;
}