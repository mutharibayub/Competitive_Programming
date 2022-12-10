#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int> tmp(n);
        tmp=a;
        for(int i=1;i<n;i++)
        {
            tmp[i]=min(tmp[i], tmp[i-1]);
        }
        map<int, int> ranges;
        map<int, int> valRange;
        ranges[0]=a[0];
        valRange[a[0]]=0;
        reverse(a.begin(), a.end());
        reverse(tmp.begin(), tmp.end());
        for(int i=0;i+1<n;i++)
        {
            if(tmp[i]!=tmp[i+1])
            {
                ranges[i+1]=tmp[i+1];
                valRange[tmp[i+1]]=i+1;
            }
        }
        for(int i=0;i<m;i++)
        {
            int idx, d;
            cin>>idx>>d;
            idx=n-idx;
            a[idx]-=d;
            auto iter = ranges.lower_bound(idx);
            if(a[idx] < iter->second)
            {
                vector<int> toRemove1, toRemove2;
                int lastVal = iter->second, newVal = a[idx];
                auto tmpIter = valRange.lower_bound(newVal);
                while(tmpIter!=valRange.end()&&tmpIter->first<lastVal)
                {
                    toRemove1.push_back(tmpIter->first);
                    toRemove2.push_back(tmpIter->second);
                    tmpIter++;
                }
                for(int i=0;i<toRemove1.size();i++)
                {
                    ranges.erase(toRemove2[i]);
                    valRange.erase(toRemove1[i]);
                }
                tmpIter = iter;
                tmpIter++;
                if(tmpIter!=ranges.end()&&tmpIter->first>=idx+1)
                {
                    valRange.erase(iter->second);
                    valRange[a[idx]]=idx;
                }
                else
                {
                    int tmp = ranges[idx];
                    ranges[idx+1]=tmp;
                    valRange[a[idx]]=idx;
                }
            }
            cout << ranges.size() << ' ';
        }cout << '\n';
    }

    return 0;
}