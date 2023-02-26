#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool MULTI = false;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        cout << 3 << '\n';
        cout << "L " << 2 << '\n';
        n += 1;
        cout << "R " << 2 << '\n';
        n += n-2;
        cout << "R " << n-1 << '\n';
        n += 1;
    }

    return 0;
}