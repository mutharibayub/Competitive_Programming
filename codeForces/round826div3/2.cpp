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
        if(n==3)
        {
            cout << -1 << '\n';
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(i)cout << ' ';
                if(i<n/2)cout << i+1+((n+1)/2);
                else cout << i+1-(n/2);
            }
            cout << '\n';
        }
    }

    return 0;
}
