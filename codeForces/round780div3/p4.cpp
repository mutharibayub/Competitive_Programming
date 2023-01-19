#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,pair<int,int>> getBest(vector<int> &arr, int s, int e, int tc)
{
    pair<int,pair<int,int>> out = {-1,{-1,-1}};
    int tmpS,tmpE=e,tmpTc=tc;
    for(tmpS=s;tmpS<=tmpE;tmpS++)
    {
        if(abs(arr[tmpS])==2)tmpTc--;
        if(arr[tmpS]<0)break;
    }
    tmpS++;
    if(tmpTc>out.first)
    {
        out = {tmpTc,{tmpS,tmpE}};
    }
    tmpS=s,tmpTc=tc;
    for(tmpE=e;tmpE>=tmpS;tmpE--)
    {
        if(abs(arr[tmpE])==2)tmpTc--;
        if(arr[tmpE]<0)break;
    }
    tmpE--;
    if(tmpTc>out.first)
    {
        out = {tmpTc,{tmpS,tmpE}};
    }
    return out;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        pair<int,pair<int,int>> ans={-1,{-1,-1}};
        int s=0;
        int tc=0;
        bool ng=0;
        for(int i=0;i<=n;i++)
        {
            if(i<n&&arr[i])
            {
                if(s==-1)s=i;
                ng^=arr[i]<0;
                tc+=abs(arr[i])==2;
            }
            else if(s!=-1)
            {
                if(ng)
                {
                    pair<int,pair<int,int>> p = getBest(arr, s, i-1, tc);
                    if(ans.first<p.first)ans=p;
                }
                else
                {
                    if(tc>ans.first)
                    {
                        ans = {tc,{s,i-1}};
                    }
                }
                s=-1;
                tc=0;
                ng=false;
            }
        }
        if(ans.second.first>ans.second.second)
        {
            cout << 0 << ' ' << n << '\n';
        }
        else
        {
            cout << ans.second.first << ' ' << n-ans.second.second-1 << '\n';
        }
    }

    return 0;
}