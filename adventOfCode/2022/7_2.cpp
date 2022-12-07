#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

map<string,map<string,int>> children;
ll val=1e9+7;
ll unused=0;

void fn(ifstream &fin, vector<string> &nesting)
{
    string cwd="";
    for(int i=0;i<nesting.size();i++)cwd+="|"+nesting[i];
    while(!fin.eof())
    {
        string a,b,c;
        fin>>a>>b;
        if(b=="ls")
        {
            bool add=true;
            while(1)
            {
                if(fin.eof())return;
                fin>>a>>b;
                if(a=="dir")
                {
                    children[cwd][cwd+"|"+b]=-1;
                }
                else if(b=="cd")
                {
                    break;
                }
                else
                {
                    children[cwd][cwd+"|"+b] = stoll(a);
                }
            }
        }
        fin>>c;
        if(c==".."){return;}
        nesting.push_back(c);
        fn(fin, nesting);
        nesting.pop_back();
    }
}

int getSize(string cwd, bool f=false)
{
    ll s=0;
    for(auto child:children[cwd])
    {
        if(child.second==-1)s+=getSize(child.first, f);
        else s+=child.second;
    }
    if(f&&(unused+s)>=30000000)
    {
        val=min(val, s);
    }
    return s;
}

int main()
{
    string filename = "7input.txt";
    ifstream fin(filename);

    vector<string> nesting;
    fn(fin, nesting);
    unused=70000000-getSize("|/");
    getSize("|/",true);
    cout << val << '\n';

    return 0;
}