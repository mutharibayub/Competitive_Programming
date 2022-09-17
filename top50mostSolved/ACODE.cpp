#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string code;
    cin>>code;
    while(code!="0")
    {
        vector<int64_t> dp(code.size()+1,0);
        dp[0] = 1;
        for(int i=1;i<=code.size();i++)
        {
            if(code[i-1]-'0'!=0)dp[i]+=dp[i-1];
            if(i>1 && (code[i-2]-'0'==1 || (code[i-1]-'0'<=6 && code[i-2]-'0'==2)))
            {
                dp[i]+=dp[i-2];
            }    
        }
        cout<<dp.back()<<'\n';
        cin>>code;
    }
    return 0;
}