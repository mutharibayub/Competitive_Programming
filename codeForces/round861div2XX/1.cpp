#include <iostream>
#include <vector>

using namespace std;

int getLucky(int n)
{
    int mn = 10, mx = -1;
    while(n)
    {
        mn=min(mn, n%10);
        mx=max(mx, n%10);
        n/=10;
    }
    return mx-mn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int l, r;
        cin>>l>>r;
        int mx=-1;
        int num=-1;
        for(int i=l;i<=r;i++)
        {
            int tmp = getLucky(i);
            if(tmp>mx)
            {
                mx = tmp;
                num = i;
            }
            if(mx == 9)break;
        }
        cout << num << '\n';
    }
    return 0;
}