#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
#define maxVal 5000
 
int main()
{
    int lim=0;
    while(1<<lim<maxVal)
    {
        lim++;
    }
    lim = 1<<lim;
    unordered_map<int,int> xors;
    vector<int> ans;
    xors[0]=1e9+7;
    ans.push_back(0);
 
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int count=1;
    for(int i=n-1;i>=0;i--)
    {
        for(auto it:xors)
        {
            if(it.second>arr[i])
            {
                if(xors.find(it.first^arr[i])==xors.end())
                {
                    count++;
                    ans.push_back(it.first^arr[i]);
                }
                xors[it.first^arr[i]]=max(xors[it.first^arr[i]],arr[i]);
            }
        }
        if(xors.size()==lim)
        {
            break;
        }
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        if(i)
        {
            cout<<' ';
        }
        cout<<ans[i];
    }cout<<'\n';
 
    return 0;
}
