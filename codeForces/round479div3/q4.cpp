#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <unordered_map>

using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;
    unordered_map<ll,int> counts;
    for(int i=0;i<n;i++)
    {
        ll tmp;
        cin>>tmp;
        counts[tmp]++;
    }

    vector<pair<ll, int>> stk;
    unordered_map<ll, int> tmp = counts;
    for(auto keyVal:tmp)
    {
        stk.emplace_back(keyVal.first, 0);
        counts[keyVal.first]--;
        while(!stk.empty() && stk.size()!=n)
        {
            ll top = stk.back().first;
            int choice = stk.back().second;
            if(choice==0)
            {
                if(counts[top*2])
                {
                    counts[top*2]--;
                    stk.back().second=1;
                    stk.emplace_back(top*2, 0);
                }
                else
                {
                    choice++;
                }
            }
            if(choice==1)
            {
                if(top%3==0 && counts[top/3])
                {
                    counts[top/3]--;
                    stk.back().second=2;
                    stk.emplace_back(top/3, 0);
                }
                else
                {
                    choice++;
                }
            }
            if(choice==2)
            {
                counts[stk.back().first]++;
                stk.pop_back();
            }
        }
        if(stk.size()==n)break;
    }

    for(int i=0;i<n;i++)
    {
        if(i)cout << ' ';
        cout << stk[i].first;
    }cout << '\n';

    return 0;
}