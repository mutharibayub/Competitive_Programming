#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool includesChar(const string& s, char a)
{
    for(int i=0;s[i];i++)
    {
        if(s[i]==a)return true;
    }
    return false;
}

int64_t fact(int64_t n)
{
    if(n==0 || n==1)return 1;
    int64_t a=n;
    for(int64_t i=2;i<n;i++)
    {
        a*=i;
    }
    return a;
}

long long C(int n, int r) {
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

void testCase()
{
    string s,t;
    cin>>s>>t;
    if(t.size()>1 && includesChar(t,'a'))
    {
        cout<<"-1\n";
    }
    else if(t.size()==1 && t[0]=='a')
    {
        cout<<"1\n";
    }
    else
    {
        int64_t ans=1;
        ans = ans<<(s.size());
        cout<<ans<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }

    return 0;
}