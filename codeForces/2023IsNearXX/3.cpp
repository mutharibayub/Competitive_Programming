#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primes;
    for(int i=2;i<=50;i++)
    {
        bool isPrime = true;
        for(int j=i;j*j<=i;j++)
        {
            if(i%j==0)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime)primes.push_back(i);
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        bool no=false;
        for(int i=0;i<n&&!no;i++)
        {
            for(int j=i+1;j<n&&!no;j++)
            {
                if(arr[i]==arr[j])
                {
                    no=true;
                }
            }
        }
        if(!no)
        for(auto prime:primes)
        {
            vector<int> cnts(prime,0);
            for(int i=0;i<n;i++)
            {
                cnts[arr[i]%prime]++;
            }
            int mn=1e9+7;
            for(int i=0;i<prime;i++)mn=min(mn,cnts[i]);
            if(mn>=2)
            {
                no=true;
                break;
            }
        }
        cout << (no?"NO":"YES") << '\n';
    }
}