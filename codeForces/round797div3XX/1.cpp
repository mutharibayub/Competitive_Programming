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
        int base = (n-3)/3;
        int c=base+1;
        if((n-3)%3>1)c++;
        cout << c << ' ';
        c=base+2;
        if((n-3)%3>0)c++;
        cout << c << ' ';
        cout << base << '\n';
    }

    return 0;
}