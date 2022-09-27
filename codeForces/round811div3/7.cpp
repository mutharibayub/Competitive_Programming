#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

// vector<int>::iterator binarySearch(vector<int>::iterator begin, const vector<int>::iterator &end, const int &val)
// {
//     for(int jump=end-begin-1;jump>0;jump/=2)
//     {
//         while(begin+jump < end && *(begin+jump) <= val)begin+=jump;
//     }
//     return begin;
// }

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
        vector<list<array<int,3>>> adjList(n);
        for(int i=1;i<n;i++)
        {
            int p, a, b;
            cin >> p >> a >> b;
            adjList[p-1].push_back({i,a,b});
        }
        int64_t asum = 0;
        vector<int> ans(n);
        vector<int64_t> bSum={0};
        vector<array<int,3>> stk={{0,0,0}};
        while(!stk.empty())
        {
            array<int,3> top = stk.back();
            if(!adjList[top[0]].empty())
            {
                auto it=adjList[top[0]].front();
                stk.push_back(it);
                bSum.push_back(bSum.back()+it[2]);
                asum += it[1];
                ans[it[0]] = lower_bound(bSum.begin(),bSum.end(),asum+1)-bSum.begin()-1;
                adjList[top[0]].pop_front();
                // cout << it[0]+1 << ": ";
                // for(auto var:bSum)
                // {
                //     cout << var << ' ';
                // }cout << "| ans = " << ans[it[0]] << "| asum = " << asum << '\n';
            }
            else
            {
                asum-=stk.back()[1];
                stk.pop_back();
                bSum.pop_back();
            }
        }
        for(int i=1;i<n;i++)
        {
            if(i>1)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }


    return 0;
}