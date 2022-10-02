#include <iostream>
#include <vector>
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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<arr.size();i++)
        {
            cin>>arr[i];
        }
        vector<pair<int,int>> ans;
        if(arr.size()==1)
        {
            cout << "0\n";
            continue;
        }
        if(arr.front()!=arr.back())
        {
            ans.emplace_back(1, arr.size());
            if((arr.front()+arr.back())&1)
            {
                arr.back()=arr.front();
            }
            else
            {
                arr.front()=arr.back();
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if((arr[i]&1) ^ (arr.front()&1))
            {
                ans.emplace_back(1, i+1);
                arr[i]=arr.front();
            }
            else
            {
                ans.emplace_back(i+1,arr.size());
                arr[i]=arr.front();
            }
        }
        // for(int i=0;i<n;i++)cout << arr[i] << ' ';
        // cout << '\n';
        cout << ans.size() << '\n';
        for(int i=0;i<ans.size();i++)
        {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    }

    return 0;
}