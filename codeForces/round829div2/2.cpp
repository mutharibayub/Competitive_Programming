#include <iostream>

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
        int num = (n+1)/2;
        while(num!=1)
        {
            cout << num << ' ' << num+(n/2) << ' ';
            num--; 
        }
        if((n+1)/2 < 1+(n/2))
        {
            cout << 1 << ' ' << 1+(n/2) << '\n';
        }
        else
        {
            cout << 1 << '\n';
        }
    }


    return 0;
}