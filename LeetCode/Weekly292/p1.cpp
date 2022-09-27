#include <iostream>
#include <string>
using namespace std;

string largestGoodInteger(string num) {
    int max = -1;
    for(int i=0;i<=num.size()-3;i++)
    {
        if(num[i]==num[i+1] && num[i+1]==num[i+2] && num[i]-'0' > max)
        {
            max = num[i]-'0';
        }
    }
    if(max==-1)return "";
    else if(max==0)return "000";
    return to_string(max*100+max*10+max);
}

int main()
{

    return 0;
}