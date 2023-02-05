#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

using namespace std;

typedef long long ll;

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.assign(n+1,0);
    }
    int get(int i)
    {
        i++;
        int out=0;
        while(i)
        {
            out+=arr[i];
            i-=i&-i;
        }
        return out;
    }
    void update(int i, int up)
    {
        i++;
        while(i<arr.size())
        {
            arr[i]+=up;
            i+=i&-i;
        }
    }
};

int digitSum(int n)
{
    int sum=0;
    while(n)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        vector<int> arr(n);
        vector<vector<int>> nxt(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            nxt[i].push_back(arr[i]);
            while(nxt[i].back()>=10)
            {
                nxt[i].push_back(digitSum(nxt[i].back()));
            }
        }
        FenwickTree fwt(n);
        for(int i=0;i<q;i++)
        {
            int typ;
            cin>>typ;
            if(typ==1)
            {
                int s,e;
                cin>>s>>e;
                --s;
                fwt.update(s,+1);
                if(e<n)fwt.update(e,-1);
            }
            else
            {
                int ind;
                cin>>ind;
                --ind;
                int nxtVal = min(fwt.get(ind),(int)nxt[ind].size()-1);
                cout << (nxt[ind][nxtVal]) << '\n';
            }
        }
    }

    return 0;

}