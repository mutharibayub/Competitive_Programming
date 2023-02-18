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
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int val = a.front();
        int second = -1;
        bool ok=false;
        for(int i=1;i<a.size()&&!ok;i++)
        {
            if(a[i]!=val)ok=true,second=i;
        }
        if(!ok)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
            for(int i=1;i<n;i++)
            {
                if(a[i]==val)
                {
                    cout << second+1 << ' ' << i+1 << '\n';
                }
                else
                {
                    cout << 1 << ' ' << i+1 << '\n';
                } 
            }
        }
    }


    return 0;
}