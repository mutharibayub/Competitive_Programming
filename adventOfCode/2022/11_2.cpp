#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;

ll MOD = 1;

ll norm(ll num)
{
    return (num%MOD+MOD)%MOD;
}

struct Monkey
{
    vector<ll> items;
    string opSign;
    string opVal;
    int testDiv;
    int tt;
    int ft;
    ll doOp(ll v)
    {
        int v1=-1;
        if(opVal[0]=='o')
        {
            v1=v;
        }
        else
        {
            v1=stoi(opVal);
        }
        if(opSign=="*")
        {
            return norm(v1*v);
        }
        else
        {
            return norm(v1+v);
        }
    }
};

int main()
{
    string filename = "11input.txt";
    ifstream fin(filename);

    vector<Monkey> monkeys;
    while(!fin.eof())
    {
        string s;
        fin>>s;
        if(s=="")break;
        monkeys.push_back(Monkey());
        auto &m = monkeys.back();
        fin>>s>>s>>s;
        while(1)
        {
            fin>>s;
            if(s[0]=='O')break;
            if(s.back()==',')s.pop_back();
            m.items.push_back(stoi(s));
        }
        fin>>s>>s>>s>>s;
        m.opSign=s;
        fin>>s;
        m.opVal=s;
        fin>>s>>s>>s>>s;
        m.testDiv=stoi(s);
        MOD*=m.testDiv;
        for(int i=0;i<2;i++)
        {
            fin>>s>>s>>s>>s>>s>>s;
            if(i)m.ft=stoi(s);
            else m.tt=stoi(s);
        }
    }
    vector<int> inspected(monkeys.size(),0);
    for(int i=0;i<10000;i++)
    {
        for(int c=0;c<monkeys.size();c++)
        {
            auto &monkey=monkeys[c];
            for(auto item:monkey.items)
            {
                ll nw = monkey.doOp(item);
                if(nw%monkey.testDiv==0)
                {
                    monkeys[monkey.tt].items.push_back(nw);
                }
                else
                {
                    monkeys[monkey.ft].items.push_back(nw);
                }
            }
            inspected[c]+=monkey.items.size();
            monkey.items.clear();
        }
    }
    sort(inspected.rbegin(), inspected.rend());
    cout << 1ll*inspected[0]*inspected[1] << '\n';


    return 0;
}