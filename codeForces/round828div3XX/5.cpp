#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long

bool inRange(ll num, ll l, ll r)
{
    num = ((l+num)/num)*num;
    return num > l && num <=r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d;
        cin >> a >> c >> b >> d;
        vector<ll> factors;
        factors.reserve(100);
        ll nums[2] = {a,c};
        for(int i=0;i<2;i++)
        {
            for(ll j=2;j*j<=nums[i];j++)
            {
                while(nums[i]%j==0)
                {
                    factors.push_back(j);
                    nums[i]/=j;
                }
            }
            factors.push_back(nums[i]);
        }
        // for(auto factor: factors)
        // {
        //     cout << factor << ' ';
        // }cout << '\n';
        // return 0;
        ll mult = a*c;
        ll found = -1;
        unordered_set<ll> possibs;
        possibs.insert(1);
        for(auto factor:factors)
        {
            unordered_set<ll> tmp = possibs;
            for(auto it:tmp)
            {
                ll num = factor*it;
                if(num!=1 && possibs.find(num)!=possibs.end())continue;
                ll other = mult/num;
                if ( (inRange(num, a , b) && inRange(other, c, d))
                        || (inRange(other, a , b) && inRange(num, c, d)))
                {
                    found = num;
                    break;
                }
                if(inRange(num, a, b) || inRange(num, c, d))
                {
                    possibs.insert(num);
                }
            }
            if(found!=-1)break;
        }
        if(found==-1)
        {
            cout << "-1 -1\n";
        }
        else
        {
            ll num1, num2, other =mult/found;
            if(inRange(found, a, b) && inRange(other, c, d))
            {
                num1 = ((a+found)/found)*found;
                num2 = ((c+other)/other)*other;
            }
            else
            {
                num2 = ((c+found)/found)*found;
                num1 = ((a+other)/other)*other;
            }
            cout << num1 << ' ' << num2 << '\n';
        }
    }

    return 0;
}