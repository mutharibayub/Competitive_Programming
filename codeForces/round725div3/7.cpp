#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int inf = 1e9+7;

bool check(int x, int y, int a, int b, int n)
{
    double l = 0, r = n;
    r = min(r, (x-1.0*n*b)/(a-b));
    if(l>r)return false;
    l = max(l, (y-1.0*n*a)/(b-a));
    int rr = int(r);
    int ll = int(int(l)==l?l:l+1);
    if(ll>rr)return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        if(a<b)swap(a,b); 
        int cur = 0;
        if(a==b)
        {
            cout << min(x/a, y/a) << '\n';
        }
        else
        {
            for(int jmp=inf;jmp;jmp/=2)
            {
                while(cur+jmp<=inf&&check(x, y, a, b, cur+jmp))cur+=jmp;
            }
            cout << cur << '\n';
        }
    }

    return 0;
}