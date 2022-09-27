#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

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
        unordered_set<int> nums;
        bool found = false;
        for(int i=0;i<n;i++)cin>>arr[i];
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(nums.find(arr[i])!=nums.end())
            {
                cout << i+1 << '\n';
                found = true;
                break;
            }
            nums.insert(arr[i]);
        }
        if(!found)
        {
            cout << "0\n";
        }
    }

    return 0;
}