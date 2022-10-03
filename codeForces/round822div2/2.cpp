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
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j)cout << ' ';
                if(j==0 || j==i-1)
                {
                    cout << '1';
                }
                else
                {
                    cout << '0';
                }
            }
            cout << '\n';
        }
    }


    return 0;
}