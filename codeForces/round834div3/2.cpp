#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int m,s;
        cin>>m>>s;
        vector<int> arr(m);
        for(int i=0;i<m;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int curSum = 0;
        int curMax = 1;
        for(int i=0;i<m;i++)
        {
            while(curMax<arr[i])
            {
                curSum+=curMax;
                curMax++;
            }
            curMax++;
        }
        while(curSum<s)
        {
            curSum+=curMax;
            curMax++;
        }
        if(curSum==s)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }


    return 0;
}