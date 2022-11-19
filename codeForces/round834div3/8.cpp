#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n/2), loc(n+1,-1);
        for(int i=0;i<n/2;i++)
        {
            cin>>arr[i];
        }
        bool possible=true;
        for(int i=0;i<n/2;i++)
        {
            if(loc[arr[i]]!=-1)
            {
                possible=false;
                break;
            }
            loc[arr[i]]=i;
        }
        if(!possible){cout<<-1<<'\n';continue;}
        priority_queue<int> pq;
        vector<int> assignments(n/2,-1);
        for(int i=n;i>=1;i--)
        {
            if(loc[i]<0)
            {
                if(pq.empty())
                {
                    possible=false;
                    break;
                }
                assignments[pq.top()]=i;
                pq.pop();
            }
            else
            {
                pq.push(loc[i]);
            }
        } 
        if(!possible){cout<<-1<<'\n';continue;}
        for(int i=0;i<n/2;i++)
        {
            if(i)cout << ' ';
            cout << assignments[i] << ' ' << arr[i];
        }cout << '\n';
    }


    return 0;
}