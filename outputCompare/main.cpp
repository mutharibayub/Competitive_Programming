#include <iostream>
#include <fstream>
#include <sstream>
#include <assert.h>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

stringstream output;
stringstream input;

//------------------------------------------------------------------------------------------------//
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
    input>>inp;
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
    output<<inp<<'\n';
}
//------------------------------------------------------------------------------------------------//

bool isPalindrome(const string& inp)
{
    for(int i=0;i<inp.size()/2;i++)
    {
        if(inp[i]!=inp[inp.size()-i-1])
        {
            return false;
        }
    }
    return true;
}

void testCase1()
{
    string inp;
    input>>inp;
    reverse(inp.begin(),inp.end());
    add1(inp, 0);
    while(!isPalindrome(inp))
    {
        add1(inp, 0);
    }
    output<<inp<<'\n';
}

string code1(string inp)
{
    input.clear();
    input.str(inp);
    output.clear();
    output.str(string());
    //----------------------------------------------------------------------//
    int n;
    input >> n;
    while(n--)
    {
        testCase();
    }
    //----------------------------------------------------------------------//
    
    return output.str();
}

string code2(string inp)
{
    input.clear();
    input.str(inp);
    output.clear();
    output.str(string());
    //----------------------------------------------------------------------//
    int n;
    input>>n;
    while(n--)
    {
        testCase1();
    }
    //----------------------------------------------------------------------//

    return output.str();
}

int main()
{
    ifstream fin("input.txt");
    stringstream buf;
    string input; 
    buf << fin.rdbuf();
    input = buf.str();
    fin.close();

    // output << code1(input);
    // output << code2(input);
    assert(code1(input) == code2 (input));

}