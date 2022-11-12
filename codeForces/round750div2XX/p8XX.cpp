#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

const int N = 1e6+1;

map<int,int> ps[N];
int prime[N];

void multiply(map<int,int> &obj1, ll obj2)
{
    while(obj2>1)
    {
        obj1[prime[obj2]]++;
        obj2/=prime[obj2];
    }
}

void multiply(map<int,int> &obj1, map<int,int> &obj2)
{
    for(auto &it:obj2)
    {
        obj1[it.first]+=it.second;
    }
}

bool isDivisible(map<int,int> &obj1, map<int,int> &obj2)
{
    for(auto &it:obj2)
    {
        if(obj1[it.first]<it.second)return false;
    }
    return true;
}

void divide(map<int,int> &obj1, map<int,int> &obj2)
{
    for(auto &it:obj2)
    {
        obj1[it.first]-=it.second;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2;i<=N;i++)
    {
        if(prime[i]==0)
        {
            prime[i]=i;
            if(i>1000)continue;
            for(int j=i+i;j<=N;j+=i)
            {
                if(!prime[j])prime[j]=i;
            }
        }
    }


    int n;
    cin>>n;
    vector<ll> arr(n), mul(n), count(n,0);
    vector<bool> conv(n,false);
    vector<int> prev(n);
    for(int i=0;i<n;i++)prev[i]=i-1;
    string s;
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>s;

    int l = -1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='*')
        {
            if(i==0 || mul[prev[i]]==-1)
            {
                count[i]=1;
                mul[i]=arr[i];
                prev[i]=-1;
            }
            else
            {
                count[i]=count[i-1]+1;
                mul[i]=arr[i];
            }
        }
        else
        {
            if(i==0 || mul[prev[i]]==-1)
            {
                mul[i]=-1;
                prev[i]=-1;
                if(arr[i]==1)
                {
                    mul[i]=1;
                    count[i]=1;
                }
            }
            else
            {
                int l = prev[i];
                map<int,int> tmp;
                multiply(tmp, arr[i]);
                while(prev[l]!=-1 && ( (!conv[l] && mul[l]%arr[i]!=0) || (conv[l] && !isDivisible(ps[l], tmp))))
                {
                    if(!conv[l])multiply(ps[l], mul[l]);
                    if(!conv[prev[l]])multiply(ps[prev[l]], mul[prev[l]]);
                    conv[l]=conv[prev[l]]=true;
                    multiply(ps[prev[l]], ps[l]);
                    ps[l].clear();
                    conv[l]=false;
                    l = prev[l];
                }
                if( ( (!conv[l] && mul[l]%arr[i]==0) || (conv[l] && isDivisible(ps[l], tmp))) )
                {
                    if(arr[i]==1)
                    {
                        mul[i]=1;
                        count[i]=count[l]+1;
                        prev[i]=l;
                        if(!conv[l])mul[l]=mul[l]/arr[i];
                        else divide(ps[l], tmp);
                    }
                    else
                    {
                        if(!conv[l])mul[i]=mul[l]/arr[i];
                        else
                        {
                            divide(ps[l], tmp);
                            ps[i]=ps[l];
                            ps[l].clear();
                            conv[l]=false;
                            conv[i]=true;
                        }
                        count[i]=count[l];
                        prev[i]=prev[l];
                    }
                }
                else
                {
                    mul[i]=-1;
                    prev[i]=-1;
                }
            }
        }
    }

    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ans += count[i];
    }
    cout << ans << '\n';

    return 0;
}