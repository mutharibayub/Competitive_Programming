#include <iostream>
#include <vector>

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
        vector<int> s(n),f(n),d(n);
        for(int i=0;i<n;i++)cin>>s[i];
        for(int i=0;i<n;i++)cin>>f[i];
        
        d[0]=f[0]-s[0];
        for(int i=1;i<n;i++)
        {
            d[i]=f[i]-max(s[i], f[i-1]);
        }
        for(int i=0;i<n;i++)
        {
            if(i)cout << ' ';
            cout << d[i];
        }
        cout << '\n';
    }

    return 0;
}