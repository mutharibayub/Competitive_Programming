#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include <map>
#include <algorithm>

using namespace std;

#define DEBUG(X) cout << #X": " << X << endl;

typedef long long ll;

struct Operation
{
    string m1;
    string m2;
    string opr;
    Operation(const string &m1,const string &m2,const string &opr):m1(m1),m2(m2),opr(opr){}
    Operation(){}
};

map<string, Operation> ops;

ll getVal(const string &monk)
{
    auto it = ops.find(monk);
    if(it->second.opr=="")
    {
        return stoll(it->second.m1);
    }
    else
    {
        ll num1 = getVal(it->second.m1), num2 = getVal(it->second.m2);
        string opr = it->second.opr;
        if(opr=="*")return num1*num2;
        else if(opr=="/")return num1/num2;
        else if(opr=="-")return num1-num2;
        else return num1+num2;
    }
}

bool hasHuman(const string &monk)
{
    if(monk=="humn")return true;
    auto it = ops.find(monk);
    if(it->second.opr=="")return false;
    bool ans = hasHuman(it->second.m1)||hasHuman(it->second.m2); 
    return ans;
}

int main()
{
    string filename = "21input.txt";
    ifstream fin(filename);

    string t1;
    while(!fin.eof())
    {
        fin>>t1;
        if(t1=="")break;
        string monk=t1;
        monk.pop_back();
        fin>>t1;
        if(t1[0]>='0'&&t1[0]<='9')
        {
            ops[monk]=Operation(t1, "", "");
        }
        else
        {
            string t2,t3;
            fin>>t2>>t3;
            ops[monk]=Operation(t1,t3,t2);
        }
    }

    auto it = ops.find("root");
    string c1 = it->second.m1;
    string c2 = it->second.m2;
    if(hasHuman(c2))swap(c1,c2);
    ll target = getVal(c2);
    ll curr = getVal(c1);
    for(ll jump=1e16;jump;jump/=2)
    {
        auto &pr = ops["humn"];
        while(1)
        {
            ll val = stoll(pr.m1);
            if(val+jump<1e16)
            {
                pr.m1=to_string(val+jump);
                ll next = getVal(c1);
                if(abs(next-target)>=abs(curr-target))
                {
                    pr.m1=to_string(val);
                    break;
                }
                curr=next;
            }
            else break;
        }
        while(1)
        {
            ll val = stoll(pr.m1);
            if(val-jump>0)
            {
                pr.m1=to_string(val-jump);
                ll next = getVal(c1);
                if(abs(next-target)>=abs(curr-target))
                {
                    pr.m1=to_string(val);
                    break;
                }
                curr = next;
            }
            else break;
        }
    }

    cout << ops["humn"].m1 << '\n';

    return 0;
}