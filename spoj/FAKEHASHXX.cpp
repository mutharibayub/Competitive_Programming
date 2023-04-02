#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;

const int PRIME_COUNT = 9;

const int primes[PRIME_COUNT] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

struct Number
{
    int cnt[PRIME_COUNT] = {0,0,0,0,0,0,0,0,0};
    Number(){}
    Number(int n)
    {
        for(int i=0;i<PRIME_COUNT;i++)
        {
            while(n%primes[i]==0)
            {
                n/=primes[i];
                cnt[i]++;
            }
        }
        assert(n==1); 
    }
    Number(const Number &num){*this = num;}
    Number &operator=(const Number &num)
    {
        for(int i=0;i<PRIME_COUNT;i++)
        {
            cnt[i]=num.cnt[i];
        }return *this;
    }
    bool isEmpty()
    {
        for(int i=0;i<PRIME_COUNT;i++)
        {
            if(cnt[i])return false;
        }return true;
    }
    bool canDivide(const Number &num)
    {
        for(int i=0;i<PRIME_COUNT;i++)
        {
            if(cnt[i]<num.cnt[i])return false;
        }return true;
    }
    void mult(const Number &num)
    {
        for(int i=0;i<PRIME_COUNT;i++)
        {
            cnt[i]+=num.cnt[i];
        }
    }
    void divide(const Number &num)
    {
        for(int i=0;i<PRIME_COUNT;i++)
        {
            cnt[i]-=num.cnt[i];
        }
    }
    void print()
    {
        for(int i=0;i<PRIME_COUNT;i++)
        {
            if(i)cout << ' ';
            cout << cnt[i];
        }cout << '\n';
    }
};

Number fact[28];
vector<int> facts = {0,1,3,5,7,8,9,11,12,13,15,16,17,18,19,20,21,23,24,25};

bool isValid(Number num)
{
    for(int i=0;i<PRIME_COUNT;i++)
    {
        if(num.cnt[i]<0)return false;
        else if(num.cnt[i]>0)
        {
            for(int j=0;j<i;j++)
            {
                if(num.cnt[j]<num.cnt[i]*(fact[primes[i]].cnt[j]))return false;
            }
        }
    }return true;
}

int cnt = 0;

bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)return false;
    }return true;
}

string ans = "";

void solve(const string &s, vector<int> &enc, Number &num, int start = facts.size()-1)
{
    cnt++;
    if(num.isEmpty())
    {
        string tmp = "";
        for(int i=0;i<26;i++)
            if(enc[i])tmp += string(enc[i], i+'a');
        if(tmp!=s && (ans=="" || tmp<ans))ans=tmp;
        return;
    }
    for(int ii=start;ii>=0;ii--)
    {
        int i = facts[ii];
        int mx = 0, jmp=1e9+7;
        if(isPrime(i+2))
        {
            for(int j=PRIME_COUNT-1;j>=0;j--)
            {
                if(num.cnt[j])
                {
                    mx=num.cnt[j];
                    break;
                }
            }
            enc[i]+=mx;
            for(int k=0;k<PRIME_COUNT;k++)num.cnt[k]-=mx*fact[i+2].cnt[k];
            if(isValid(num))
                solve(s, enc, num, ii-1);
            for(int k=0;k<PRIME_COUNT;k++)num.cnt[k]+=mx*fact[i+2].cnt[k];
            enc[i]-=mx;
            continue;
        }
        for(int j=0;j<PRIME_COUNT;j++)
        {
            if(fact[i+2].cnt[j])jmp = min(jmp, num.cnt[j]/fact[i+2].cnt[j]);
        }
        for(;jmp;jmp/=2)
        {
            while(1)
            {
                Number tmp = fact[i+2], nt=num;
                for(int j=0;j<PRIME_COUNT;j++)
                {
                    nt.cnt[j]-=(mx+jmp)*tmp.cnt[j];
                }
                if(isValid(nt))mx+=jmp;
                else break;
            }
        }
        for(int j=mx;j>0;j--)
        {
            enc[i]+=j;
            for(int k=0;k<PRIME_COUNT;k++)num.cnt[k]-=j*fact[i+2].cnt[k];
            solve(s, enc, num, ii-1);
            for(int k=0;k<PRIME_COUNT;k++)num.cnt[k]+=j*fact[i+2].cnt[k];
            enc[i]-=j;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=2;i<=27;i++)
    {
        fact[i]=fact[i-1];
        fact[i].mult(Number(i));
    }

    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        ans = "";

        cout << "Case " << t+1 << ": ";

        string s;
        cin>>s;
        Number num;
        for(int i=0;s[i];i++)
        {
            num.mult(fact[s[i]-'a'+2]);
        }
        vector<int> enc(26, 0);
        solve(s, enc, num);
        if(ans.size())
        {
            cout << ans;
        }
        else
        {
            cout << "Impossible";
        }
        cout << '\n';
    }

    cout << cnt << endl;

    return 0;
}