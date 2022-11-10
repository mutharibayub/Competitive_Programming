#include <iostream>
#include <vector>
#include <assert.h>
#include <utility>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n, oneCount=0;
        cin>>n;
        vector<int> arr(n);
        vector<bool> sign(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sign[i] = 0;
            oneCount += arr[i]!=0;
        }
        if(oneCount&1)
        {
            cout << -1 << '\n';
            continue;
        }
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i]*(sign[i]?-1:1);
        }
        if(sum)
        {
            for(int i=1;i<n;i++)
            {
                if(arr[i]==(sum>0?1:-1))
                {
                    sign[i] = 1;
                    i++;
                    sum += (sum>0?-2:2);
                    if(!sum)break;
                }
            }
        }
        assert(sum==0);
        vector<pair<int,int>> segments={make_pair(0,-1)};
        bool next = 0;
        for(int i=0;i<n;i++)
        {
            if(sign[i]==next)
            {
                next = !next;
            }
            else
            {
                segments.back().second = i-1;
                segments.push_back(make_pair(i,-1));
                next = 1;
            }
        }
        segments.back().second = n-1;
        cout << segments.size() << '\n';
        for(auto it:segments)
        {
            cout << it.first+1 << ' ' << it.second+1 << '\n'; 
        }
    }
    

    return 0;
}