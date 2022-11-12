#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
const int maxVal = 8192;
const int N = 5000+1;

int xors[maxVal];
vector<int> pos[N];

int main()
{
    for(int i=0;i<maxVal;i++)
    {
        xors[i]=1e9+7;
    }
    xors[0]=-1;

    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        pos[tmp].push_back(i);
    }

    for(int i=1;i<N;i++)
    {
        if(pos[i].empty())continue;
        for(int j=0;j<maxVal;j++)
        {
            if(xors[j]==1e9+7)continue;
            auto iter = lower_bound(pos[i].begin(), pos[i].end(), xors[j]);
            if(iter==pos[i].end())continue;
            xors[i^j] = min(xors[i^j], *iter);
        }
    }
    int count = 0;
    for(int i=0;i<maxVal;i++)count+=xors[i]!=1e9+7;
    cout << count << '\n';
    for(int i=0;i<maxVal;i++)
    {
        if(xors[i]!=1e9+7)
        {
            cout << i << ' ';
        }
    }cout << '\n';

    return 0;
}
