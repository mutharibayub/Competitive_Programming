#include <iostream>
using namespace std;

int getCount(int num, int d, int depth)
{
    if(depth==0)
    {
        return num%d?1:0;
    }
    else
    {
        int count=0;
        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0 && i%d!=0)
            {
                count += getCount(num/i, d, depth-1);
                if(count>=2)
                {
                    return count;
                }
            }
        }
        return count;
    }
}

void testCase()
{
    int x,d;
    cin>>x>>d;
    x/=d;
    int count=0;
    int depth=1;
    while(1)
    {
        if(x%d!=0)break;
        x/=d;
        count += getCount(x, d, depth);
        if(count>=2)break;
        depth++;
    }
    if(count>=2)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }
}