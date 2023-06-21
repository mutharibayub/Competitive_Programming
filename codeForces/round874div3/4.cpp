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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        if(arr.size()<3)
        {
            reverse(arr.begin(), arr.end());
        }
        else
        {
            int mxIdx=1;
            for(int i=2;i<n;i++)
            {
                if(arr[i]>arr[mxIdx])mxIdx=i;
            }
            if(mxIdx==n-1&&arr[n-2]<arr.front())
            {
                arr.insert(arr.begin(), arr.back());
                arr.pop_back();
            }
            else
            {
                int ptr=mxIdx-2;
                while(ptr>0&&arr[ptr]>arr.front())ptr--;
                ptr++;
                reverse(arr.begin()+ptr, arr.begin()+mxIdx);
                vector<int> newArr;
                newArr.insert(newArr.end(), arr.begin()+mxIdx, arr.end());
                newArr.insert(newArr.end(), arr.begin()+ptr, arr.begin()+mxIdx);
                newArr.insert(newArr.end(), arr.begin(), arr.begin()+ptr);
                arr=newArr;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << arr[i];
        }cout << '\n';
    }

    return 0;
}