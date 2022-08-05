#include <iostream>
using namespace std;

int64_t pow(int64_t a, int64_t e)
{
    if(e<0)return -1;
    int64_t ans=1;
    while(e)
    {
        if(e&1)
        {
            ans *= a;
        }
        a = a*a;
        e = e>>1;
    }    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int a,count=0;
        cin>>a;
        for(int i=1;pow(5,i)<=a;i++)
        {
            count += a/pow(5,i);
        }
        cout<<count<<'\n';
    }

}