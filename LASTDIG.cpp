#include <iostream>

using namespace std;

template<class T>
T power(T num, T exp, T mod)
{
    T ans = 1;
    while(exp>0)
    {
        if(exp&1)
        {
            ans*=num;
            ans%=mod;
        }
        exp = exp>>1;
        num*=num;
        num%=mod;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int64_t n,e;
        cin>>n>>e;
        cout<<power(n,e,int64_t(10))<<'\n';
    }
}