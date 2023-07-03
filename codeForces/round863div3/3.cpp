#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

#define tst int tttt;cin>>tttt;while(tttt--)

inline int comp(int a, int b) 
{
    return a<b?-1:a>b?1:0;
}

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    tst
    {
        int n;
        cin>>n;
        vector<int> arr(n-1);
        for(int i=0;i<n-1;i++)cin>>arr[i];
        vector<int> ans = {arr.front(), arr.front()};
        int last = -2;
        for(int i=0;i<n-2;i++)
        {
            int relation = comp(arr[i], arr[i+1]);
            int ptr=i+1;
            while(ptr<n-2&&comp(arr[ptr], arr[ptr+1])==relation)ptr++;
            if(relation==1)
            {
                ans.pop_back();
                for(int j=i+1;j<=ptr;j++)ans.push_back(arr[j]);
                ans.push_back(ans.back());
            }
            else if(relation==-1)
            {
                if(last==-2)
                {
                    ans.clear();
                    ans.insert(ans.begin(), 0);
                    for(int j=i;j<=ptr;j++)ans.push_back(arr[j]);
                }
                else if(last==0)
                {
                    for(int j=i+1;j<=ptr;j++)ans.push_back(arr[j]);
                }
                else if(last==1)
                {
                    for(int j=i+1;j<=ptr;j++)ans.push_back(arr[j]);
                }
            }
            else if(relation==0)
            {
                for(int j=i+1;j<=ptr;j++)ans.push_back(arr[j]);
            }
            i=ptr-1;
            last=relation;
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }

    return 0;
}