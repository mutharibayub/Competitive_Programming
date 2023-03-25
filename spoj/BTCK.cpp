#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

bool solve(vector<int> &arr, vector<int> &perm, int &done, ll sum, ll k)
{
    if(perm.size()==10)
    {
        if(sum<=k)return true;
        return false;
    }
    int nxt = arr[perm.size()];
    for(int i=0;i<10;i++)
    {
        if((done&(1<<i)) || sum+nxt*1ll*i>k)continue;
        perm.push_back(i);
        done^=(1<<i);
        sum+=nxt*1ll*i;
        if(solve(arr, perm, done, sum, k))return true;
        sum-=nxt*1ll*i;
        done^=(1<<i);
        perm.pop_back();
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin>>t;
    while(t--)
    {
        vector<int> arr(10);
        for(int i=0;i<10;i++)cin>>arr[i];
        int k;
        cin>>k;
        vector<int> perm;
        int done=0;
        if(solve(arr, perm, done, 0, k))
        {
            for(int i=0;i<10;i++)
            {
                if(!(done&(1<<i)))perm.push_back(i);
            }
            assert(perm.size()==10);
            for(int i=0;i<10;i++)
            {
                if(i)cout << ' ';
                cout << perm[i];
            }cout << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }

}