#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int getLoopVal(const string& s)
{
    for(int i=1;i<=s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(s[j]!=s[(j+i)%s.size()])break;
            if(j+1==s.size())return i;
        }
    }
    return -1;
}

ll GCD(ll x,ll y)
{
    if(x<y)swap(x,y);
    if(!y)return x;
    return GCD(y, x%y);
}

ll LCM(ll x, ll y)
{
    return (x*y)/GCD(x,y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        set<int> done;
        cin>>n>>s;
        vector<int> arr(n);
        vector<int> vals;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            arr[i]--;
        }
        for(int i=0;i<n;i++)
        {
            if(done.find(i)==done.end())
            {
                string tmp="";
                while(done.find(i)==done.end())
                {
                    tmp.push_back(s[i]);
                    done.insert(i);
                    i=arr[i];
                }
                vals.push_back(getLoopVal(tmp));
            }
        }
        ll ans=1;
        for(int i=0;i<vals.size();i++)
        {
            ans=LCM(ans, vals[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}