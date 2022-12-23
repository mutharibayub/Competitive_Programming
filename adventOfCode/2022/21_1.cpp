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

    cout << getVal("root") << '\n';

    return 0;
}