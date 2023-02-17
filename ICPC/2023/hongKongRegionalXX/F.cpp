#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class BigInt
{
    string num;
public:
    BigInt(const string &s)
    {
        num=s;
        reverse(num.begin(), num.end());
        while(num.size()>1&&num.back()=='0')num.pop_back();
        for(int i=0;i<num.size();i++)num[i]-='0';
    }
    BigInt(const BigInt& obj){*this=obj;}
    BigInt& operator=(const BigInt& obj)
    {
        this->num=obj.num;
        return *this;
    }
    BigInt operator+(const BigInt& obj1)
    {
        int carry = 0;
        BigInt outNum("");
        string &out = outNum.num;
        const string &s1 = this->num, &s2 = obj1.num;
        for(int i=0;i<s1.size()||i<s2.size();i++)
        {
            int sum = carry+(i<s1.size()?s1[i]:0)+(i<s2.size()?s2[i]:0);
            out.push_back(sum%10);
            carry=sum/10;
        }
        if(carry)out.push_back(carry);
        return outNum;
    }
    bool operator<(const BigInt& obj1)
    {
        if(this->num.size()!=obj1.num.size())
        {
            return this->num.size()<obj1.num.size();
        }
        else
        {
            for(int i=num.size()-1;i>=0;i--)
            {
                if(obj1.num[i]!=num[i])return num[i]<obj1.num[i];
            }
            return false;
        }
    }
    friend ostream &operator<<(ostream&,const BigInt&);
};

ostream& operator<<(ostream& out, const BigInt &obj)
{
    for(int i=obj.num.size()-1;i>=0;i--)
    {
        out<<char(obj.num[i]+'0');
    }
    if(obj.num.empty())out<<'0';
    return out;
}

void createTries(vector<int> &trie, int sum, int lim, int n, vector<vector<int>> &tries)
{
    int left = lim-trie.size();
    if(left==0&&sum==n)
    {
        tries.push_back(trie);
        return;
    }
    int minPos = sum+trie.back()*left-left*(left+1)/2;
    int maxPos = sum+trie.back()*left+left*(left+1)/2;
    if(minPos>n||maxPos<n)return;
    for(int i=-1;i<2;i++)
    {
        if(trie.back()+i<=0)continue;
        trie.push_back(trie.back()+i);
        sum+=trie.back();
        createTries(trie, sum, lim, n, tries);
        sum-=trie.back();
        trie.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<vector<int>> tries;
        vector<int> trie;
        for(int i=1;i<n;i++)
        {
            trie.push_back(i);
            createTries(trie, i, k+1, n, tries);
            trie.pop_back();
        }

        BigInt best(string(n+1, '9'));
        for(auto trie:tries)
        {
            int ptr=0;
            BigInt test("0");
            for(auto len:trie)
            {
                test = test+BigInt(s.substr(ptr, len));
                ptr+=len;
            }
            if(test<best)best=test;
        }
        cout << best << '\n';
    }

    return 0;
}