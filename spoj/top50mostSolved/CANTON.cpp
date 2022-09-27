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
        int index;
        cin>>index;

        int jump = 1e4;
        int start = 0;
        for(;jump>0;jump/=2)
        {
            while(((start+jump)*(start+jump+1)/2) < index)
            {
                start += jump;
            }
        }
        // cout<<"Start: "<<start<<'\n';
        start++;
        int num1,num2;
        int eleNum = (start*(start+1))/2 - index;
        // cout<<"eleNum: "<<eleNum<<'\n';
        if(start%2)
        {
            num1 = eleNum+1;
            num2 = start+1-num1;
        }
        else
        {
            num2 = eleNum+1;
            num1 = start+1-num2;
        }
        cout<<"TERM "<<index<<" IS "<<num1<<"/"<<num2<<'\n';
    }

    return 0;
}