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
    int t;
    input>>t;
    while(t--)
    {
        int n, m, k;
        input>>n>>m>>k;
        vector<int> arr(n), aft(m), tools(k);
        for(int i=0;i<n;i++)input>>arr[i];
        for(int i=0;i<m;i++)input>>aft[i];
        for(int i=0;i<k;i++)input>>tools[i];
        vector<int> toRemove;
        int ptr=0;
        bool yes=true;
        if(n-m>k)
        {
            output << "NO" << '\n';
            continue;
        }
        for(int i=0;i<m;i++)
        {
            while(ptr<n&&aft[i]!=arr[ptr])toRemove.push_back(ptr++);
            if(ptr==n)
            {
                yes=false;
                break;
            }
            ptr++;
        }
        if(!yes)
        {
            output << "NO" << '\n';
        }
        vector<int> rq;
        vector<bool> gone(n, false);
        sort(toRemove.begin(), toRemove.end(), [&](int a, int b){return arr[a]>arr[b];});
        for(int i=0;i<toRemove.size();i++)
        {
            int idx=toRemove[i];
            int l=idx, r=idx;
            int goneCount=0;
            while(l>=0&&(arr[l]<=arr[idx]||gone[l]))goneCount+=gone[l],l--;
            while(r<=n-1&&(arr[r]<=arr[idx]||gone[r]))goneCount+=gone[r],r++;
            rq.push_back(r-l-1-goneCount);
            gone[idx]=true;
        }
        sort(rq.begin(), rq.end());
        sort(tools.begin(), tools.end());
        for(int i=0;i<rq.size();i++)
        {
            if(rq[i]<tools[i])
            {
                yes=false;
                break;
            }
        }
        output << (yes?"YES":"NO") << '\n';
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
    int t;
    input>>t;
    while(t--)
    {
        int n,m,k;
        input>>n>>m>>k;
        vector<int> arr(n), aft(m, true), tools(k);
        vector<bool> missing(n, false);
        bool yes=true;
        for(int i=0;i<n;i++)input>>arr[i];
        for(int i=0;i<m;i++)input>>aft[i];
        for(int i=0;i<k;i++)input>>tools[i];
        if(n-m>k)
        {
            output << "NO" << '\n';
            continue;
        }
        int ptr=0;
        for(int i=0;i<m&&yes;i++)
        {
            while(ptr<n&&arr[ptr]!=aft[i])missing[ptr++]=true;
            if(ptr==n)
            {
                yes=false;
                break;
            }
            ptr++;
        }
        if(!yes)
        {
            output << "NO" << '\n';
            continue;
        }
        while(ptr<n)missing[ptr++]=true;
        vector<int> stk1, stk2, stk3, lmx(n), rmx(n);
        for(int i=0;i<n;i++)
        {   
            while(stk1.size()&&arr[stk1.back()]<arr[i])stk1.pop_back();
            if(!missing[i])while(stk2.size()&&arr[stk2.back()]<arr[i])stk2.pop_back(),stk3.pop_back();

            auto it = lower_bound(stk3.rbegin(), stk3.rend(), arr[i]);

            lmx[i]=(it==stk3.rend()?-1:*(it-stk3.rbegin()+stk2.rbegin()));
            int above=0;
            if(!stk2.size())
            {
                above=stk1.size();
            }
            else if(stk2.back()!=stk1.back())
            {
                above=stk1.size()-(lower_bound(stk1.begin(), stk1.end(), stk2.back())-stk1.begin())-1;
            }
            lmx[i]+=above;

            stk1.push_back(i);
            if(!missing[i])stk2.push_back(i), stk3.push_back(arr[i]);
        }
        stk1.clear(), stk2.clear(), stk3.clear();
        for(int i=n-1;i>=0;i--)
        {   
            while(stk1.size()&&arr[stk1.back()]<arr[i])stk1.pop_back();
            if(!missing[i])while(stk2.size()&&arr[stk2.back()]<arr[i])stk2.pop_back(),stk3.pop_back();

            auto it = lower_bound(stk3.rbegin(), stk3.rend(), arr[i]);

            rmx[i]=(it==stk3.rend()?n:*(it-stk3.rbegin()+stk2.rbegin()));
            int above=0;
            if(!stk2.size())
            {
                above=stk1.size();
            }
            else if(stk2.back()!=stk1.back())
            {
                above=lower_bound(stk1.rbegin(), stk1.rend(), stk2.back())-stk1.rbegin();
            }
            rmx[i]-=above;

            stk1.push_back(i);
            if(!missing[i])stk2.push_back(i),stk3.push_back(arr[i]);
        }

        vector<int> rq;
        for(int i=0;i<n;i++)
        {
            if(missing[i])
            {
                rq.push_back(rmx[i]-lmx[i]-1);
            }
        }
        sort(rq.begin(), rq.end());
        sort(tools.begin(), tools.end());

        for(int i=0;i<rq.size()&&yes;i++)
        {
            if(tools[i]>rq[i])
            {
                yes=false;
            }
        }

        output << (yes?"YES":"NO") << '\n';

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