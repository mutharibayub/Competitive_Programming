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
        int a,b,c;
        cin>>a>>b>>c;
        b = abs(b-c) + abs(c-1);
        a = abs(a-1);
        if(a==b)
        {
            cout<<"3\n";
        }
        else if(a<b)
        {
            cout<<"1\n";
        }
        else
        {
            cout<<"2\n";
        }
    }

    return 0;
}