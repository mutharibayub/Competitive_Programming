#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#define ll long long

ll getInv(ll num, ll mod)
{
    ll Q,R=1,T,T1=0,T2=1,tmp=mod;
    while(R)
    {
        R=mod%num;
        Q=mod/num;
        T=T1-T2*Q;
        // cout << Q << ' ' << mod << ' ' << num << ' ' << R << ' ' << T1 << ' ' << T2 << ' ' << T << '\n';
        T1=T2;
        T2=T;
        mod=num;
        num=R;
    }
    return T1<0?tmp+T1:T1;
}

struct CMT
{
    ll a;
    ll m;
    ll M;
    ll M_;
    CMT(ll a, ll m, ll M, ll M_):a(a),m(m),M(M),M_(M_){}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin("13input.txt");
    int startVal, index=0;
    ll M = 1;
    string inp;
    vector<CMT> data;

    fin >> startVal;

    while(!fin.eof())
    {
        inp.clear();
        fin >> inp;
        if(inp[0]!='x' && inp.size())
        {
            int id = stoi(inp);
            data.emplace_back(index?id-index%id:0, id, -1, -1);   
            M*=id;     
        }
        index++;
    }

    ll ans = 0;

    for(auto &it:data)
    {
        it.M = M/it.m;
        it.M_ = getInv(it.M, it.m);
        // cout << it.a << ' ' << it.m << ' ' << it.M << ' ' << it.M_ << '\n'; 
        ans = (ans+it.a*it.M*it.M_)%M;
    }
    cout << ans << '\n';
    return 0;
}
