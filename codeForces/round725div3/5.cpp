#include <iostream>
#include <vector>
#include <array>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair<array<string, 2>, ll> var;

int count(const string& s)
{
    string f = "haha";
    int cnt = 0;
    for(int i=0;s[i];i++)
    {
        bool no = true;
        for(int j=0;s[i+j]&&f[j];j++)
        {
            if(s[i+j]!=f[j])break;
            if(!f[j+1])no=false;
        }
        if(!no)cnt+=1;
    }
    return cnt;
}

var concat(var& v1, var &v2)
{
    string mid = v1.first[1]+v2.first[0];
    int addCount = count(mid);
    string nl = v1.first[0];
    string nr = v2.first[1];
    if(nl.size()<3)
    {
        for(int i=0;nl.size()<3&&v2.first[0][i];i++)
        {
            nl.push_back(v2.first[0][i]);
        }
    }
    if(nr.size()<3)
    {
        reverse(nr.begin(), nr.end());
        for(int i=v1.first[1].size()-1;nr.size()<3&&i>=0;i--)
        {
            nr.push_back(v1.first[1][i]);
        }
        reverse(nr.begin(), nr.end());
    }
    var n; 
    n.first[0]=nl;
    n.first[1]=nr;
    n.second=v1.second+v2.second+addCount;
    return n;
}

var construct(const string& s)
{
    var n;
    n.first[0]=n.first[1]=s;
    while(n.first[0].size()>3)n.first[0].pop_back();
    reverse(n.first[1].begin(), n.first[1].end());
    while(n.first[1].size()>3)n.first[1].pop_back();
    reverse(n.first[1].begin(), n.first[1].end());
    n.second=count(s);
    return n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int st;
        cin>>st;
        map<string, var> vars;
        string last = "";
        for(int i=0;i<st;i++)
        {
            string vr, t;
            cin>>vr>>t;
            if(t==":=")
            {
                string s;
                cin>>s;
                vars[vr]=construct(s);
            }
            else
            {
                string a, b, tmp;
                cin>>a>>tmp>>b;
                vars[vr]=concat(vars[a], vars[b]);
            }
            last = vr;
        }
        cout << vars[last].second << '\n';
    }

    return 0;
}