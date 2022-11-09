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
        int m;
        cin>>m;
        int minus=1;
        while(1)
        {
            if(minus==int(1e9) || minus*10>m)break;
            minus*=10;
        }
        cout << m-minus << '\n';
    }

    return 0;
}