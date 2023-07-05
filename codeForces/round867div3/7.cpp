#include <iostream>
#include <vector>
#include <map>

using namespace std;

int isPrime(int n)
{
    for(int i=2;1ll*i*i<=n;i++)
    {
        if(n%i==0)return false;
    }return true;
}

bool getNext(vector<int> &state, vector<int> &lim)
{
    int i=state.size()-1;
    for(;i>=0;i--)
    {
        state[i]=(state[i]+1)%lim[i];
        if(state[i]!=0)
        {
            return true;
        }
    }return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> primes;

    const int N = 4e4;
    for(int i=2;i<=N;i++)
    {
        if(isPrime(i))primes.push_back(i);
    }

    int t;
    cin>>t;
    while(t--)
    {
        long long ans = 0;

        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];

        map<int,int> cnts;
        for(int i=0;i<n;i++)cnts[arr[i]]++;

        map<int, vector<pair<int,int>>> pfs;
        for(int i=0;i<n;i++)
        {
            if(pfs.find(arr[i])!=pfs.end())continue;
            auto &tarr = pfs[arr[i]];
            for(int j=0;j<primes.size()&&1ll*primes[j]*primes[j]<=arr[i];j++)
            {
                if(arr[i]%primes[j]==0)
                {
                    tarr.push_back({primes[j], 0});
                    while(arr[i]%primes[j]==0)
                    {
                        tarr.back().second++;
                        arr[i]/=primes[j];
                    }
                }
            }
            if(arr[i]>1)tarr.push_back({arr[i], 1});
        }

        for(auto pr: cnts)
        {
            if(pr.second > 2)
            {
                ans += 1ll*pr.second*(pr.second-1)*(pr.second-2);
            }

            int ele = pr.first;
            vector<int> state;
            vector<int> num;
            vector<int> lim;
            auto &tarr = pfs[ele];
            for(int j=0;j<tarr.size();j++)
            {
                if(tarr[j].second>=2)
                {
                    lim.push_back(tarr[j].second/2+1);
                    num.push_back(tarr[j].first);
                }
            }
            if(!lim.empty())
            {
                state.assign(lim.size(), 0);
                state.back()+=1;
                do
                {
                    int num1 = 1;
                    for(int j=0;j<state.size();j++)
                    {
                        for(int k=1;k<=state[j];k++)num1*=num[j];
                    }
                    if(cnts.find(ele/num1)!=cnts.end() && cnts.find(ele/num1/num1)!=cnts.end())
                    {
                        ans += 1ll * cnts[ele] * cnts[ele/num1] * cnts[ele/num1/num1];
                    }
                } while (getNext(state, lim));   
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}