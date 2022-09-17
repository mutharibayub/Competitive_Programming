#include <iostream>
#include <algorithm>

using namespace std;

void add1(string& inp, int digitNum)
{
    while(true)
    {
        inp[digitNum]++;
        if(inp[digitNum]=='9'+1)
        {
            inp[digitNum]='0';
            if(digitNum==inp.size()-1)
            {
                inp.push_back('1');
                return;
            }
            digitNum++;
        }
        else
        {
            return;
        }
    }
}

void testCase()
{
    string inp;
    cin>>inp;
    reverse(inp.begin(), inp.end());
    add1(inp, 0);
    for(int i=0;i<inp.size();i++)
    {
        if(inp[i] > '9' || (i<inp.size()/2 && inp[i] > inp[inp.size()-i-1]))
        {
            if(i == inp.size()-1)
            {
                inp.push_back('1');
                break;
            }
            else
            {
                inp[i+1]++;
            }
        }
    }
    bool start = false;
    for(int i=inp.size()-1;i>=inp.size()/2;i--)
    {
        if(!start && inp[i]<='9')
        {
            inp[inp.size()-1-i] = inp[i];
        }
        else
        {
            inp[i]='0';
            inp[inp.size()-1-i] = inp[i];
        }
    }
    cout<<inp<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }
    return 0;
}