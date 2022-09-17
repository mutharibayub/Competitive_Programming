#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1000000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> initPrimes;
    vector<bool> marked(1e5+1,1);
    //find and save primes upto square root of max possible upper limit
    for(int i=2;i*i<=maxn;i++)
    {
        if(marked[i])
        {
            for(int j=i+i;j<=1e5;j+=i)
            {
                marked[j]=0;
            }
        }
    }
    for(int i=2;i<marked.size();i++)
    {
        if(marked[i])initPrimes.push_back(i);
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        marked.clear();
        marked.assign(m-n+1,1);
        for(int64_t it:initPrimes)
        {
            if(it*it>m)break;
            int s = it*(n%it==0?n/it:(n/it)+1);
            s = s==it?s+s:s;
            for(;s<=m;s+=it)
            {
                marked[s-n]=0;
            }
        }
        //mark composites using previously saved primes
        for(int i=0;i<marked.size();i++)
        {
            if(n+i <= 1)continue; 
            if(marked[i])
            {
                for(int j=2*(i+n);j<=m;j+=(n+i))
                {
                    marked[j-n]=0;
                }
            }
        }
        //mark composites using unmarked numbers in the given range
        for(int i=0;i<marked.size();i++)
        {
            if(i+n <= 1 || !marked[i])continue;
            cout<<(i+n)<<'\n';
        }
        cout<<'\n';
    }

    return 0;
}
