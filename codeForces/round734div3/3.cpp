#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

const int MOD = 1e9+7;

ll pwr(ll n, ll e)
{
    ll o=1;
    while(e)
    {
        if(e%2)o=o*n%MOD;
        e/=2;
        n=n*n%MOD;
    }return o;
}

ll gcd(ll a, ll b)
{
    if(a<b)swap(a, b);
    return b?gcd(b, a%b):a;
}

int getRatio(const array<int,5> &word, int prim)
{
    double sum = 0;
    for(int i=0;i<5;i++)sum+=word[i];
    sum-=word[prim];
    return word[prim]-sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n;
        cin>>n;
        vector<array<int,5>> words(n, {0,0,0,0,0});
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j<s.size();j++)
            {
                words[i][s[j]-'a']++;
            }
        }
        int ans = 0;
        for(int i=0;i<5;i++)
        {
            int cnt = 0;
            sort(words.begin(), words.end(), [&i](const auto &obj1, const auto &obj2){
                return getRatio(obj1, i) > getRatio(obj2, i);});
            array<int, 2> curWord = {0,0};
            for(int j=0;j<words.size();j++)
            {
                for(int k=0;k<5;k++)
                {
                    if(k==i)curWord[0]+=words[j][k];
                    else curWord[1]+=words[j][k];
                }
                if(curWord[0]<curWord[1])break;
                cnt++;
                if(curWord[0]>curWord[1])ans = max(ans, cnt);
            }
        }
        cout << ans << '\n';
    }    

    return 0;
}