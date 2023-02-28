// better implementation of q7
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e7+1;
int C[N];
int ans[N];
int sieve[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> p;
    for(int i=2;i<N;i++)
    {
        if(!sieve[i])
        {
            p.push_back(i);
            sieve[i]=i;
        }
        for(int j=0;j<(int)p.size();j++)
        {
            if(p[j]>sieve[i]||p[j]*i>=N)break;
            sieve[i*p[j]]=p[j];
        }
    }

    C[1]=ans[1]=1;
    for(int i=2;i<N;i++)
    {
        int tmp=i, cur=1, sum=1;
        while(tmp%sieve[i]==0)
        {
            tmp/=sieve[i];
            cur*=sieve[i];
            sum+=cur;
        }
        C[i]=C[tmp]*sum;
        if(C[i]<N&&!ans[C[i]])ans[C[i]]=i;
    }

    const bool MULTI = true;

    int t=1;
    if(MULTI)cin>>t;
    while(t--)
    {
        int c;
        cin>>c;
        cout << (ans[c]?ans[c]:-1) << '\n';

    }

    return 0;
}