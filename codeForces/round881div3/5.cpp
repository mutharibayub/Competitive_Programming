#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(vector<int> &chg, vector<pair<int,int>> &rngs, int m, int q) 
{
    vector<int> arr(m, 0);
    for(int i=0;i<q;i++) 
    {
        arr[chg[i]]=1;
    }
    for(int i=1;i<m;i++)arr[i]+=arr[i-1];
    for(auto rng: rngs)
    {
        int len = rng.second-rng.first+1;
        int ones = arr[rng.second] - (rng.first?arr[rng.first-1]:0);
        if(ones > len-ones)
        {
            return true;
        }
    }return false;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--) 
    {  
        int m, n;
        cin>>m>>n;
        vector<pair<int,int>> rngs(n);
        for(int i=0;i<n;i++) 
        {
            cin>>rngs[i].first>>rngs[i].second;
            rngs[i].first--, rngs[i].second--;
        }
        int q;
        cin>>q;
        vector<int> chg(q);
        for(int i=0;i<q;i++) 
        {
            cin>>chg[i];
            --chg[i];
        }
        int val = 0;
        for(int jump=q;jump;jump/=2) 
        {
            while(val+jump <= q && !check(chg, rngs, m, val+jump))val+=jump;
        }
        cout << (val==q?-1:val+1) << '\n';
    }
    return 0;
}