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
    vector<int> data;
public:
    bigInt(const string& str)
    {
        data.clear();
        int mult=1;
        for(int i=str.size()-1;i>=0;i--)
        {
            if((str.size()-1-i)%9==0)
            {
                data.push_back(0);
                mult=1;
            }
            data.back()+=(str[i]-'0')*mult;
            mult*=10;
        }
    }
    bigInt operator-(const bigInt& obj)
    {
        bigInt temp = *this;
        for(int i=0;i<temp.data.size() && i<obj.data.size();i++)
        {
            temp.data[i]-=obj.data[i];
        }
        for(int i=0;i<temp.data.size()-1;i++)
        {
            if(temp.data[i]<0)
            {
                temp.data[i]+=int(1e9);
                temp.data[i+1]--;
            }
        }
        while(temp.data.back()==0)temp.data.pop_back();
        return temp;
    }
    bigInt operator+(const bigInt& obj)
    {
        bigInt temp = *this;
        while(temp.data.size()<obj.data.size())temp.data.push_back(0);
        int64_t carry = 0;
        for(int i=0;i<temp.data.size();i++)
        {
            int64_t tempNum = temp.data[i];
            tempNum += obj.data[i] + carry;
            temp.data[i] = tempNum % int(1e9);
            carry = tempNum / int(1e9);
        }
        if(carry)temp.data.push_back(0);
        while(temp.data.back()==0)temp.data.pop_back();
        return temp;
    }
    void divideBy2()
    {
        int carry = 0;
        for(int i=this->data.size()-1;i>=0;i--)
        {
            int temp = this->data[i];
            this->data[i] = (temp+carry*int(1e9))/2;
            carry = temp%2;
        }
        while(this->data.back()==0)this->data.pop_back();
    }
    void print()
    {
        if(data.size()==0)cout<<'0';
        else
        {
            for(int i=data.size()-1;i>=0;i--)
            {
                if(i==data.size()-1)
                {
                    cout<<intToString(data[i],0);
                }
                else
                {
                    cout<<intToString(data[i],9);
                }
            }
        }
    }
};

int main()
{
    for(int i=0;i<10;i++)
    {
        string a,b;
        cin>>a>>b;
        bigInt num1(a);
        bigInt num2(b);
        bigInt num3 = num1-num2;
        num3.divideBy2();
        num2 = num2 + num3;
        num2.print();
        cout<<'\n';
        num3.print();
        cout<<'\n';
    }
}