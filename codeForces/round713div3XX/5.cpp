#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, l, r, s;
        cin>>n>>l>>r>>s;
        int len = r-l+1;
        int minSum = len*(len+1)/2;
        int maxSum = (n*(n+1)/2)-((n-len)*(n-len+1)/2);
        if(s<minSum||s>maxSum)
        {
            cout << -1 << '\n';
        }
        else
        {
            vector<bool> assigned(n+1, false);
            vector<int> as(len);
            int sm = 0;
            for(int i=0;i<len;i++)as[i]=i+1;
            sm = len*(len+1)/2;
            for(int i=len-1;i>=0&&sm<s;i--)
            {
                int mx = n-(len-1-i);
                int toAdd = min(s-sm, mx-as[i]);
                sm+=toAdd;
                as[i]+=toAdd;
            }
            for(int i=0;i<len;i++)
            {
                assigned[as[i]]=true;
            }
            vector<int> perm(n+1, -1);
            for(int i=0;i<len;i++)
            {
                perm[l+i]=as[i];
            }
            int ptr = 1;
            for(int i=1;i<=n;i++)
            {
                if(i>=l&&i<=r)continue;
                while(assigned[ptr])ptr++;
                perm[i]=ptr;
                assigned[ptr]=true;
            }
            for(int i=1;i<=n;i++)
            {
                if(i>1)cout << ' ';
                cout << perm[i];
            }
            cout << '\n';
        }
    }

    return 0;
}