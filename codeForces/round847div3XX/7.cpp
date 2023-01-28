#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,p,b;
        cin>>n>>m>>p>>b;
        vector<int> bonus(n,false);
        vector<int> tokens(p);
        vector<vector<int>> al(n);
        int tmp;
        for(int i=0;i<p;i++)
        {
            cin>>tokens[i];
            --tokens[i];
        }
        for(int i=0;i<b;i++)
        {
            cin>>tmp;
            bonus[--tmp]=true;
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            --a,--b;
            al[a].push_back(b);
            al[b].push_back(a);
        }
        vector<int> path(n,1e9+7);
        path[0]=0;
        queue<array<int,2>> q;
        q.push({0,0});
        while(!q.empty())
        {
            int top = q.front()[0];
            int dist = q.front()[1];
            q.pop();
            for(int neigh:al[top])
            {
                if(bonus[neigh]&&path[neigh]==1e9+7)q.push({neigh,dist+1});
                path[neigh]=min(path[neigh],dist+1);
            }
        } 
        for(int i=0;i<n;i++)
        {
            if(bonus[i])
            {
                bool dbl=false;
                for(auto u:al[i])
                {
                    if(bonus[u])
                    {
                        dbl=true;
                        break;
                    }
                }
                if(dbl)bonus[i]=2;
            }
        }
        int optionCount=0;
        int bestToken=-1;
        int bestLength=1e9+7;
        for(int token:tokens)
        {
            if(path[token]<1e9+7)
            {
                optionCount++;
                if(bestLength>path[token])
                {
                    bestLength=path[token];
                    bestToken=token;    
                }
            }
        }
        bool yes=false;
        if(optionCount==1)
        {
            int balance = 0;
            for(auto token:tokens)
            {
                if(token==bestToken)continue;
                int found=0;
                for(auto u:al[token])
                {
                    if(bonus[u]==1)found=1;
                    else if(bonus[u]==2)
                    {
                        found=1e9+7;
                        break;
                    }
                }
                balance+=found;
                if(balance>=1e9+7)break;
            }
            if(balance>=bestLength-1)
            {
                yes=true;  
            }
        }
        else if(optionCount>1)
        {
            yes=true;
        }
        cout << (yes?"YES":"NO") << '\n';
    }

    return 0;
}