#include <iostream>
#include <vector>
#include <set>

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
        set<int> s;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            if(s.size()<=2)s.insert(tmp);
        }
        if(s.size()==2)
        {
            cout << (n/2)+1 << '\n';
        }
        else
        {
            cout << n << '\n';
        }
    }

    return 0;
}