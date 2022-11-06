#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> xr(n);
    vector<int> zeroCount(n);
    unordered_map<int, array<vector<int>, 2>> vals; 
    xr[0]=0,zeroCount[0]=0;
    for(int j=0;j<n;j++)
    {
        xr[j]=xr[j?j-1:j]^arr[j];
        zeroCount[j]=zeroCount[j?j-1:j]+(arr[j]==0);
        vals[xr[j]][j&1].push_back(j);
    }
    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;

        if((a?zeroCount[b]-zeroCount[a-1]:zeroCount[b]) == b-a+1)
        {
            cout << 0 << '\n';
        }
        else if(a?xr[b]^xr[a-1]:xr[b])
        {
            cout << -1 << '\n';
        }
        else if((a?xr[b]^xr[a-1]:xr[b])==0)
        {
            if(((b-a+1)&1))
            {
                cout << 1 << '\n';
            }
            else
            {
                int toFind = a?xr[a-1]:0;
                int odd = (a&1);
                auto &tArr = vals[toFind][odd];
                auto iter = lower_bound(tArr.begin(), tArr.end(), a);
                if(iter == tArr.end() || *iter>b)
                {
                    cout << -1 << '\n';
                }
                else
                {
                    if(arr[b]==0 || arr[a]==0)
                    {
                        cout << 1 << '\n';
                    }
                    else
                    {
                        cout << 2 << '\n';
                    }
                }
            }
        }

    }

    return 0;
}