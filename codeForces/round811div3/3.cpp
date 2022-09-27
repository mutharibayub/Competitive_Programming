#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>s;
        string num="";
        int nextMax = 9;
        while(s)
        {
            if(s>nextMax)
            {
                num.push_back(nextMax+'0');
                s-=nextMax;
                nextMax--;
            }
            else
            {
                num.push_back(s+'0');
                s=0;
            }
        }
        for(int i=num.size()-1;i>=0;i--)
        {
            cout<<num[i];
        }
        cout<<'\n';
    }

    return 0;
}