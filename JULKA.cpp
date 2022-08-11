#include <iostream>
#include <vector>

using namespace std;

class bigInt
{
    string intToString(int val, int outLen)
    {
        string out = "";
        do
        {
            out.push_back(val%10+'0');
            val/=10;
        } while (val!=0);
        while(out.size()<outLen)out.push_back('0');
        for(int i=0;i<out.size()/2;i++)
        {
            int tmp = out[i];
            out[i] = out[out.size()-i-1];
            out[out.size()-i-1] = tmp; 
        }
        return out;
    }
public:
    vector<int> data;
    
    bigInt(const string& str)
    {
        data.clear();
        for(int i=str.size()-1;i>=0;i--)
        {
            if((str.size()-1-i)%9==0)
            {
                data.push_back(0);
            }
            data.back()*=10;
            data.back()+=str[i]-'0';
        }
    }
    void print()
    {
        for(int i=data.size()-1;i>=0;i--)
        {
            if(i)
            {
                cout<<intToString(data[i],9);
            }
            else
            {
                cout<<intToString(data[i],0);
            }
        }
    }
};

int main()
{
    bigInt a("123");
    a.print();

}