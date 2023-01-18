#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

typedef long long ll;

bool isPossible(vector<array<int,2>> &srt, vector<int> &arr, int m, int above)
{
    int n = arr.size();
    int last = n-above-1;
    int needed = last+1;
    int cnt=0;
    int tmp = m;
    for(int i=0;i<n&&cnt<needed;i++)
    {
        if(tmp-srt[i][0]<0)break;
        tmp-=srt[i][0];
        cnt++;
    }
    if(cnt>=needed)return true;
    needed-=2;
    cnt=0;
    tmp=m;
    if(tmp<arr[last])return false;
    tmp-=arr[last];
    for(int i=0;i<n;i++)
    {
        if(srt[i][1]==last)continue;
        if(tmp-srt[i][0]<0)break;
        tmp-=srt[i][0];
        cnt++;
    }
    if(cnt>=needed)return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {

        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        vector<array<int,2>> srt(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            srt[i]={a[i],i};
        }
        sort(srt.begin(),srt.end());
        int above = n;
        for(int jump=n;jump;jump/=2)
        {
            while(above-jump>=0&&isPossible(srt,a,m,above-jump))above-=jump;
        }
        cout << above+1 << '\n';
    }

    return 0;
}