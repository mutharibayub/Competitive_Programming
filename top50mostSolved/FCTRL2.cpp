#include <iostream>
#include <vector>
#include <string>
using namespace std;

string itos(int n,int len)
{
    int zeroes = len-to_string(n).size();
    if(zeroes)return string(zeroes,'0')+to_string(n);
    return to_string(n);
}

class longInt
{
    int digitCount;
    vector<int64_t> num;
    void normalise()
    {
        for(int i=num.size()-1;i>0;i--)
        {
            if(num[i]>(int)1e8)
            {
                num[i-1] += num[i]/(int)1e8;
                num[i] %= (int)1e8;
            }
        }        
    }
public:
    longInt(int digits,int n):digitCount(digits)
    {
        num.assign(digits%8==0?digits/8:digits/8+1, 0);
        num[num.size()-1] = n%(int)1e8;
        num[num.size()-2] = n/(int)1e8;
    }
    void print()
    {
        bool print=false;
        for(auto it:num)
        {
            if(print || it)
            {
                if(!print)cout<<it;
                else
                {
                    cout<<(it==0?"00000000":itos(it,8));
                }
                print=true;
            }
        }
        cout<<'\n';
    }
    void multiply(int n)
    {
        for(int i=0;i<num.size();i++)
        {
            num[i] *= n;
        }
        normalise();
    }
    // void debug()
    // {
    //     bool print=false;
    //     for(auto it:num)
    //     {
    //         if(it)print=true;
    //         if(print)
    //         cout<<(it==0?"00000000":to_string(it))<<'\n';
    //     }
    // }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        cin>>a;
        longInt num(1000,a);
        for(int i=1;i<a;i++)
        {
            num.multiply(i);
        }
        num.print();
    }

}