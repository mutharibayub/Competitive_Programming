#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

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
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i] *= -1;
        }
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            arr[i]+=tmp;
        }
        sort(arr.begin(), arr.end());
        int ptr1=0,ptr2=arr.size()-1;
        int count = 0;
        while(ptr1<ptr2)
        {
            if(arr[ptr1]+arr[ptr2] < 0)
            {
                ptr1++;
            }
            else
            {
                ptr1++;
                ptr2--;
                count++;
            }
        }
        cout << count << '\n';
    }


    return 0;
}