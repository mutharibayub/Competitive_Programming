#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,t1=0,t2=0,ov=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int v;
            cin>>v;
            t1+=(i+1!=v);
            t2+=(n-i!=v);
            ov+=(i+1!=v)&&(n-i!=v);
        }
        if(t2<t1-ov)
        {
            cout << "Second";
        }
        else if(t1<=t2-ov)
        {
            cout << "First";
        }
        else
        {
            cout << "Tie";
        }
        cout << '\n';
    }

    return 0;
}