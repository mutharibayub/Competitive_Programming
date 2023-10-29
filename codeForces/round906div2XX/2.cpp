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
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        string s, t;
        cin>>n>>m>>s>>t;
        vector<int> consecLocs;
        for(int i = 0; i+1 < n; i++)
        {
            if(s[i] == s[i+1])
            {
                consecLocs.push_back(i);
            }
        }
        if(consecLocs.size() == 0)
        {
            cout << "Yes" << '\n';
            continue;
        }
        bool ok = true;
        int req = -1;
        for(int i = 0; i < consecLocs.size() && ok; i++)
        {
            if(req == -1 || req == s[consecLocs[i]])
                req = s[consecLocs[i]];
            else 
                ok = false;
        }

        if (!ok)
        {
            cout << "No" << '\n';
            continue;
        }

        int cc = 0;
        for(int i = 0; i+1 < m; i++)
        {
            if (t[i] == t[i+1])
                cc++;
        }

        if (cc != 0 || t.front() == req || t.back() == req)
            ok = false;
        
        cout << (ok? "Yes": "No") << '\n';
    }
    return 0;
}