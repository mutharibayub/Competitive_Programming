#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
 
using namespace std;
 
typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

struct Node
{
    array<pair<int, int>, 2> dd;
    Node()
    {
        dd[0]={0, 0};
        dd[1]={0, 0};
    }
    void add(int val, int idx)
    {
        if(dd[0].second==idx&&dd[0].first<val)
        {
            dd[0]={val, idx};
        }
        else if(dd[1].second==idx&&dd[1].first<val)
        {
            dd[1]={val, idx};
        }
        else if(dd[1]<(pair<int, int>){val, idx})
        {
            dd[1]={val, idx};
        }
        if(dd[1]>dd[0])
        {
            swap(dd[0], dd[1]);
        }
    }
    Node operator+(const Node& other)
    {
        Node out = *this;
        out.add(other.dd[0].first, other.dd[0].second);
        out.add(other.dd[1].first, other.dd[1].second);
        return out;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;

        vector<int> health(n), armour(n);
        for(int i=0;i<n;i++)
            cin>>health[i];
        for(int i=0;i<n;i++)
            cin>>armour[i];
 
        int mxVal = 0;
        if(n==1)
        {
            cout << 1ll*armour[0]*health[0] << '\n';
            continue;
        }
 
        for(int i=0;i<n;i++)
            mxVal = max(mxVal, armour[i]);
        vector<Node> suffixMax(mxVal+1);
        for(int i=0;i<n;i++)
        {
            suffixMax[armour[i]].add(health[i], i);
        }
        for(int i=mxVal-1;i>=0;i--)
        {
            suffixMax[i]=suffixMax[i]+suffixMax[i+1];
        }
        
        vector<ll> ans(n, 0);
        for(int i=1;i<=mxVal;i++)
        {
            array<pair<ll, int>, 2> mx;
            for(int start=1;;start+=i)
            {
                if(start > mxVal)
                    break;
                Node best = suffixMax[start];
                array<pair<ll, int>, 2> bestArr;
                for(int j=0;j<2;j++)
                {
                    bestArr[j] = {1ll*best.dd[j].first*((start+i-1)/i), best.dd[j].second};
                    if(mx[1].second == bestArr[j].second && mx[1].first < bestArr[j].first)
                    {
                        mx[1] = bestArr[j];
                    }
                    else if(mx[0].second == bestArr[j].second && mx[0].first < bestArr[j].first)
                    {
                        mx[0] = bestArr[j];
                    }
                    else if(mx[1] < bestArr[j])
                    {
                        mx[1] = bestArr[j];
                    }
                    if(mx[1]>mx[0])
                        swap(mx[1], mx[0]);
                }
            }
            if(mx[0].first != mx[1].first)
            {
                ans[mx[0].second] = max(1ll*ans[mx[0].second], mx[0].first-mx[1].first);
            }
        }
        for(int i=0;i<n;i++)
            cout << ans[i] << " \n"[i==n-1];
    }
    return 0;
}