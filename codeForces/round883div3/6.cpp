#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
const int MOD = 1e9+7;
 
ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}
 
ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

void getCnt(int n, vector<int> &arr, vector<int> &cnt)
{
    for(int i=0;i<cnt.size();i++)cnt[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        arr[i]--;
        cnt[arr[i]]++;
    }
}

int getMimicType(vector<int> &lastCnt, vector<int> &curCnt) 
{
    for(int i=0;i<9;i++)
    {
        if(lastCnt[i]<curCnt[i])return i;
    }return -1;
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        vector<int> lastCnt(9,0), curCnt(9,0);

        getCnt(n, arr, lastCnt);
        cout << "- 0" << endl;
        getCnt(n, arr, curCnt);
        int mimicType=getMimicType(lastCnt, curCnt);
        if(mimicType==-1)
        {
            lastCnt=curCnt;
            cout << "- 0" << endl;
            getCnt(n, arr, curCnt);
            mimicType=getMimicType(lastCnt, curCnt);
            assert(mimicType!=-1);
        }
        vector<int> toRemove;
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=mimicType)
                toRemove.push_back(i);
        }
        cout << "- ";
        cout << toRemove.size();
        for(int i=0;i<toRemove.size();i++)
            cout << ' ' << toRemove[i]+1;
        cout << endl;
        n-=toRemove.size();

        int found = (n==1?1:-1);
        for(int j=0;j<2;j++)
        {
            getCnt(n, arr, curCnt);
            for(int i=0;i<n&&found==-1;i++)
            {
                if(arr[i]!=mimicType)
                {
                    found=i+1;
                }
            }
            if(found!=-1)
            {
                break;
            }
            cout << "- 0" << endl;   
        }
        
        assert(found!=-1);
        cout << "! " << found << endl;
    }

 
    return 0;
}