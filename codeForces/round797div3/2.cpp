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
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        int mDiff = 0;
        for(int i=0;i<n;i++)mDiff=max(mDiff, a[i]-b[i]);
        bool possible=true;
        for(int i=0;i<n;i++)
        {
            if(a[i]-b[i]!=mDiff&&b[i]!=0)
            {
                possible=false;
                break;
            }
        }
        cout << (possible?"YES":"NO") << '\n';
    }

    return 0;
}