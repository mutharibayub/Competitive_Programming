#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define ll long long
#define pll pair<long long, long long>

int parent(vector<int> &parents, int i)
{
    vector<int> stk;
    stk.reserve(1000000+1);
    while(parents[i]!=i)
    {
        stk.push_back(i);
        i = parents[i];
    }
    while(!stk.empty())
    {
        parents[stk.back()] = parents[i];
        stk.pop_back();
    }
    return i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(1)
    {
        cin>>n;
        if(!n)break;
        vector<ll> arr(n);
        vector<pll> sorted(n);
        vector<ll> size(n);
        vector<int> parents(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sorted[i].first = arr[i];
            sorted[i].second = i;
            parents[i] = i;
            size[i] = 1;
        }

        if(n==1)
        {
            cout << arr[0] << '\n';
            continue;
        }

        sort(sorted.rbegin(), sorted.rend());
        ll maxSize = -1;
        ll maxScore = -1;
        for(int i=0;i<n;i++)
        {
            int ind = sorted[i].second;
            ll val = sorted[i].first;
            for(int j=-1;j<1;j++)
            {
                if(ind+j<0 || ind+j+1>=n)continue;
                int parent1 = parent(parents, ind+j), parent2 = parent(parents, ind+j+1);
                if(parent1==parent2 || min(arr[parent1], arr[parent2])<val)continue;
                if(arr[parent1]>arr[parent2])
                {
                    parents[parent1] = parent2;
                    size[parent2] += size[parent1];
                }
                else
                {
                    parents[parent2] = parent1;
                    size[parent1] += size[parent2];
                }
            }
            maxSize = max(maxSize, size[ind]);
            maxScore = max(maxScore, maxSize*val);
        }
        cout << maxScore << '\n';
    }


    return 0;   
}