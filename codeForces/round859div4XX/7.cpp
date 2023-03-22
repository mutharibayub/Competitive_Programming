#include <iostream>
#include <vector>
#include <algorithm>

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
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        sort(arr.begin(), arr.end());
        vector<ll> sm(n);
        sm[0]=arr[0];
        for(int i=1;i<n;i++)sm[i]=sm[i-1]+arr[i];
        bool ok = arr.front()==1;
        for(int i=1;i<n&&ok;i++)
        {
            ok&=sm[i-1]>=arr[i];
        }
        cout << (ok?"YES":"NO") << '\n';
    }
    return 0;
}