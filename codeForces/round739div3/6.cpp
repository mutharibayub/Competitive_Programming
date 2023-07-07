#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int countUnique(ll num)
{
    int digit[10], cnt=0;
    for(int i=0;i<10;i++)digit[i]=0;
    while(num)
    {
        if(!digit[num%10]++)cnt++;
        num/=10;
    }
    return cnt;
}

int smallestDigit(ll num) 
{
    int smallest = 9;
    while(num)
    {
        smallest=min(1ll*smallest, num%10);
        num/=10;
    }
    return smallest;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll num;
        int k;
        cin>>num>>k;
        int toAdd=0;
        bool found = false;
        while(1)
        {
            int digit=num%10;
            for(int i=digit;i<10;i++)
            {
                if(countUnique(num-digit+i)<=k)
                {
                    num=num-digit+i;
                    found=true;
                    break;
                }
            }
            if(found)break;
            num=num/10+1;
            toAdd++;
        }
        int smallest = countUnique(num)<k?0:smallestDigit(num);
        for(int i=0;i<toAdd;i++)
        {
            num*=10;
            num+=smallest;
        }
        cout << num << '\n';
    }

    return 0;
}