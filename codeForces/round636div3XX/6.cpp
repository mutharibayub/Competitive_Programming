#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool check(int n, vector<vector<int>> &perms, vector<int> &perm, vector<pair<int,int>> &rng, vector<bool> &done)
{
    if(perm.size()==n-1)
    {
        for(int i=0;i<n;i++)
        {
            if(!done[i])
            {
                perm.push_back(i);
                return true;
            }
        }
        assert(false);
    }

    int remove = -1;
    vector<int> count(n, 0);
    vector<int> loc(n, -1);
    for(int i=0;i<perms.size();i++)
    {
        for(int j=0;j<perms[i].size();j++)
        {
            count[perms[i][j]]++;
            loc[perms[i][j]]=i;
        }
    }

    remove = -1;
    vector<int> options;
    for(int i=0;i<n;i++)
    {
        if(!done[i]&&count[i]==1&&rng[i].first<=perm.size())
        {
            remove = i;
            perm.push_back(remove);
            done[remove]=true;
            vector<pair<int,int>> tempRng = rng;
            vector<int> tempPerm = perms[loc[remove]];

            vector<bool> in(n, false);
            for(int j=0;j<perms[loc[remove]].size();j++)
            {
                in[perms[loc[remove]][j]]=true;
            }
            for(int j=0;j<n;j++)
            {
                if(done[j])continue;
                if(in[j])
                {
                    rng[j].first = max<int>(rng[j].first,perm.size());
                    rng[j].second = min<int>(rng[j].second, perm.size()+perms[loc[remove]].size()-2);
                }
                else
                {
                    rng[j].first = max<int>(rng[j].first, perm.size()+perms[loc[remove]].size()-1);
                    rng[j].second = min<int>(rng[j].second, n-1);
                }
            }
            perms.erase(perms.begin()+loc[remove]);

            if(check(n, perms, perm, rng, done))return true;

            perms.insert(perms.begin()+loc[remove], tempPerm);
            rng = tempRng;
            done[remove]=false;
            perm.pop_back();
        }
    }
    return false;

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
        cin>>n;
        vector<vector<int>> perms(n-1);
        for(int i=0;i<n-1;i++)
        {
            int m;
            cin>>m;
            perms[i].resize(m);
            for(int j=0;j<m;j++)cin>>perms[i][j], perms[i][j]--;
        }
        vector<pair<int,int>> rng(n);
        vector<int> cnt(n,0);
        for(int i=0;i<perms.size();i++)
        {
            for(int j=0;j<perms[i].size();j++)
            {
                cnt[perms[i][j]]++;
            }
        }

        vector<int> perm;
        vector<bool> done(n, false);

        assert(check(n, perms, perm, rng, done));

        for(int i=n-1;i>=0;i--)
        {  
            if(i<n-1)cout << ' ';
            cout << perm[i]+1;
        }cout << '\n';
    }
    return 0;
}