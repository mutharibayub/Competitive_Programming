#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9+7;

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
        vector<int> arr(n), stk, L(n,-1), R(n, -1);
        vector<vector<int>> dependent(n);
        int maxInd=-1;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            if(maxInd==-1 || arr[maxInd]<arr[i])maxInd = i;
            while(!stk.empty() && arr[stk.back()]<arr[i])stk.pop_back();
            if(!stk.empty())L[i]=stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for(int i=n-1;i>=0;i--)
        {
            while(!stk.empty() && arr[stk.back()]<=arr[i])stk.pop_back();
            if(!stk.empty())R[i]=stk.back();
            stk.push_back(i);
        }

        for(int i=0;i<n;i++)
        {
            if(L[i]==-1)
            {
                if(R[i]!=-1)
                {
                    dependent[R[i]].push_back(i);
                }
            }
            else
            {
                if(R[i]==-1 || arr[R[i]]>arr[L[i]])
                {
                    dependent[L[i]].push_back(i);
                }
                else
                {
                    dependent[R[i]].push_back(i);
                }
            }
        }

        vector<vector<ll>> dp(n,vector<ll>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[i][j]=1+(j?dp[i][j-1]:0);
            }
        }
        stk.clear();
        stk.push_back(maxInd);
        while(!stk.empty())
        {
            int top = stk.back();
            if(dependent[top].empty())
            {
                stk.pop_back();
                if(stk.empty())continue;
                int parent = stk.back();
                vector<ll> tmp(m);
                for(int j=0;j<m;j++)
                {
                    ll maxVal, lessVal;
                    maxVal = dp[parent][j]-(j?dp[parent][j-1]:0); 
                    if(top<parent)lessVal = j?dp[top][j-1]:0;
                    else lessVal = dp[top][j];
                    lessVal=(lessVal%MOD+MOD)%MOD;
                    maxVal=(maxVal%MOD+MOD)%MOD;
                    tmp[j] = (maxVal*lessVal)%MOD;
                    if(j)tmp[j] = (tmp[j]+tmp[j-1])%MOD;   
                }
                dp[parent]=tmp;
            }
            else
            {
                stk.push_back(dependent[top].back());
                dependent[top].pop_back();
            }
        }
        cout << dp[maxInd].back() << '\n';
    }

    return 0;
}