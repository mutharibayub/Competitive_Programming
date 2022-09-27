#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void strip(string& str)
{
    for(int i=0;i<2;i++)
    {
        while(str.size() && str.back()==' ')
        {
            str.pop_back();
        }
        reverse(str.begin(), str.end());
    }
}

bool isNum(const string& str)
{
    for(int i=0;str[i];i++)
    {
        if(str[i]<'0' || str[i]>'9')
        {
            return false;
        }
    }
    return true;
}

void testCase()
{
    string line = "";
    cin.get();
    getline(cin, line);
    // cout<<"Line: "<<line<<'\n';
    string tmp = ""; 
    int64_t num1=-1,num2=-1,num3=-1;
    for(int i=0;line[i];i++)
    {
        if(line[i]=='+' || line[i]=='=')
        {
            strip(tmp);
            if(isNum(tmp))
            {
                (line[i]=='+'?num1:num2) = stoi(tmp);
            }
            tmp = "";
        }
        else
        {
            tmp.push_back(line[i]);
        }
    }
    strip(tmp);
    if(isNum(tmp))
    {
        num3 = stoi(tmp);
    }
    if(num1==-1)
    {
        num1 = num3-num2;
    }
    else if(num2==-1)
    {
        num2 = num3-num1;
    }
    else
    {
        num3=num1+num2;
    }
    cout<<num1<<" + "<<num2<<" = "<<num3<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        testCase();
    }
    return 0;
}