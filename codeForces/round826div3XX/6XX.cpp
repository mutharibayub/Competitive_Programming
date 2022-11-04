#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

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
        vector<array<int,4>> arr(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)cin>>arr[i][j];
            arr[i][3]=i;
        }
        vector<int> ans(n,1e9+7);

        {
            sort(arr.begin(), arr.end());
            array<int,2> last = {-1,-1};
            for(int i=0;i<n;i++)
            {  
                if(last[0]!=-1 && arr[last[0]][2]!=arr[i][2])
                {
                    if(arr[last[0]][1] >= arr[i][0])
                    {
                        ans[arr[i][3]]=0;
                        ans[arr[last[0]][3]]=0;
                    }
                    else 
                    {
                        ans[arr[i][3]]=min(ans[arr[i][3]], arr[i][0] - arr[last[0]][1]);
                        ans[arr[last[0]][3]]=min(ans[arr[last[0]][3]], arr[i][0] - arr[last[0]][1]);
                    }
                }
                else if(last[1]!=-1 && arr[last[1]][2]!=arr[i][2])
                {
                    if(arr[last[1]][1] >= arr[i][0])
                    {
                        ans[arr[i][3]]=0;
                    }
                    else 
                    {
                        ans[arr[i][3]]=min(ans[arr[i][3]], arr[i][0] - arr[last[1]][1]);
                    }
                }
                if(last[0]==-1)
                {
                    last[0]=i;
                }
                else if(last[1]==-1 && arr[last[0]][2]!=arr[i][2])
                {
                    last[1]=i;
                }
                else if(arr[i][2]==arr[last[0]][2] || arr[i][2]==arr[last[1]][2])
                {
                    if(arr[i][2]==arr[last[0]][2] && arr[i][1]>arr[last[0]][1])
                    {
                        last[0]=i;
                    }
                    else if(arr[i][2]==arr[last[1]][2] && arr[i][1]>arr[last[1]][1])
                    {
                        last[1]=i;
                    }
                }
                else if(arr[i][1] > arr[last[1]][1])
                {
                    last[1]=i;
                }
                if(last[0]!=-1 && last[1]!=-1 && arr[last[0]][1] < arr[last[1]][1])
                {
                    swap(last[0], last[1]);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            swap(arr[i][0], arr[i][1]);
        }

        {
            sort(arr.rbegin(), arr.rend());
            array<int,2> last = {-1,-1};
            for(int i=0;i<n;i++)
            {  
                if(last[0]!=-1 && arr[last[0]][2]!=arr[i][2])
                {
                    if(arr[last[0]][1] <= arr[i][0])
                    {
                        ans[arr[i][3]]=0;
                        ans[arr[last[0]][3]]=0;
                    }
                    else 
                    {
                        ans[arr[i][3]]=min(ans[arr[i][3]], arr[last[0]][1] - arr[i][0]);
                        ans[arr[last[0]][3]]=min(ans[arr[last[0]][3]], arr[last[0]][1] - arr[i][0]);
                    }
                }
                else if(last[1]!=-1 && arr[last[1]][2]!=arr[i][2])
                {
                    if(arr[last[1]][1] <= arr[i][0])
                    {
                        ans[arr[i][3]]=0;
                    }
                    else 
                    {
                        ans[arr[i][3]]=min(ans[arr[i][3]], arr[last[1]][1] - arr[i][0]);
                    }
                }
                if(last[0]==-1)
                {
                    last[0]=i;
                }
                else if(last[1]==-1 && arr[last[0]][2]!=arr[i][2])
                {
                    last[1]=i;
                }
                else if(arr[i][2]==arr[last[0]][2] || arr[i][2]==arr[last[1]][2])
                {
                    if(arr[i][2]==arr[last[0]][2] && arr[i][1]<arr[last[0]][1])
                    {
                        last[0]=i;
                    }
                    else if(arr[i][2]==arr[last[1]][2] && arr[i][1]<arr[last[1]][1])
                    {
                        last[1]=i;
                    }
                }
                else if(arr[i][1] < arr[last[1]][1])
                {
                    last[1]=i;
                }
                if(last[0]!=-1 && last[1]!=-1 && arr[last[0]][1] > arr[last[1]][1])
                {
                    swap(last[0], last[1]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==1e9+7)ans[i]=0;
            if(i)cout << ' ';
            cout << ans[i];
        }cout << '\n';
    }

    return 0;
}
