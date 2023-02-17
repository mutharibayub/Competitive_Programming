#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class FenwickTree
{
    vector<int> arr;
public:
    FenwickTree(int n)
    {
        arr.resize(n+1, 0);
    }
    void update(int i, int add)
    {
        i++;
        while(i<arr.size())
        {
            arr[i]+=add;
            i+=i&-i;
        }
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
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> arr(n), aft(m), tools(k), loc(n);
        vector<bool> missing(n, false);
        bool yes=true;
        for(int i=0;i<n;i++)cin>>arr[i],--arr[i];
        for(int i=0;i<m;i++)cin>>aft[i],--aft[i];
        for(int i=0;i<k;i++)cin>>tools[i];
        for(int i=0;i<n;i++)loc[arr[i]]=i;
        if(n-m>k)
        {
            cout << "NO" << '\n';
            continue;
        }
        int ptr=0;
        for(int i=0;i<m&&yes;i++)
        {
            while(ptr<n&&arr[ptr]!=aft[i])missing[arr[ptr++]]=true;
            if(ptr==n)
            {
                yes=false;
                break;
            }
            ptr++;
        }
        if(!yes)
        {
            cout << "NO" << '\n';
            continue;
        }
        while(ptr<n)missing[arr[ptr++]]=true;
        set<int> st;
        FenwickTree fwt(n);
        vector<int> rq;
        for(int i=n-1;i>=0;i--)
        {
            if(missing[i])
            {
                auto it = st.lower_bound(loc[i]);
                int e = it==st.end()?n:*it;
                int s = it==st.begin()?-1:*prev(it);
                int dropped = fwt.get(e-1)-(s==-1?0:fwt.get(s));
                int sz = e-s-1-dropped;
                rq.push_back(sz);
                fwt.update(loc[i], +1);
            }
            else
            {
                st.insert(loc[i]);
            }
        }

        sort(rq.begin(), rq.end());
        sort(tools.begin(), tools.end());

        for(int i=0;i<rq.size()&&yes;i++)
        {
            if(tools[i]>rq[i])
            {
                yes=false;
            }
        }

        cout << (yes?"YES":"NO") << '\n';

    }


    return 0;
}