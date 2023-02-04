#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
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
        string s;
        cin>>s;
        int ptr1=0,ptr2=n-1;
        while(ptr2>ptr1&&s[ptr1]!=s[ptr2])ptr1++,ptr2--;
        cout << (ptr2-ptr1+1) << '\n';
        
    }

    return 0;

}