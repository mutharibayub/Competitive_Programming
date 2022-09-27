#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInt
{
    vector<int> arr;
public:
    BigInt(const string &num)
    {
        for(int i=num.size()-1;i>=0;)
        {
            int mult=1, tmp=0;
            for(int j=8;j>=0&&i>=0;j--,i--)
            {
                tmp += mult*(num[i]-'0');
                mult *= 10;
            }
            arr.push_back(tmp);
        }
    }
    void Sub(int num)
    {
        for(int i=0;i<arr.size();i++)
        {
            arr[i] -= num;
            if(arr[i]>=0)break;
            arr[i] += 1e9;
            num = 1;
        }
    }
    void Mult(int num)
    {
        int carry = 0;
        for(int i=0;i<arr.size();i++)
        {
            int64_t tmp = arr[i];
            tmp *= num;
            tmp += carry;
            if(tmp>=1e9)
            {
                carry = tmp/int(1e9);
                arr[i] = tmp%int(1e9);
            }
            else
            {
                carry = 0;
                arr[i] = tmp;
            }
        }
        if(carry)
        {
            arr.push_back(carry);
        }
    }
    void Print()
    {
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(i!=arr.size()-1)
            {
                int tmp = arr[i], c=0;
                do
                {
                    c++;
                    tmp/=10;
                } while (tmp);
                for(int j=0;j<9-c;j++)
                {
                    cout << '0';
                }
                cout << arr[i];
            }
            else
            {
                cout << arr[i];
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string n;
    while(cin>>n)
    {
        if(n=="1")
        {
            cout << "1\n";
        }
        else
        {
            BigInt num(n);
            num.Mult(2);
            num.Sub(2);
            num.Print();
            cout << '\n';
        }
    }
}