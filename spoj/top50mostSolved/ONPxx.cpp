#include <iostream>
#include <vector>
using namespace std;

bool higherPrio(const char &a, const char &b)
{
    if(a==')' && b!='(')return true;
    if(a==')' && b=='(')return false;
    if(a=='(')return false;
    char prioArr[5] = {'+', '-', '*', '/', '^'};
    int prios[2] = {0,0};
    for(int i=0;i<5;i++)
    {
        if(prioArr[i]==a)prios[0]=i;
        if(prioArr[i]==b)prios[1]=i;
    } 
    return prios[0]<=prios[1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string output = string();
        vector<char> stack = vector<char>();
        cin>>s;
        for(int i=0;s[i];i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                output.push_back(s[i]);
            }
            else if(s[i]==')')
            {
                while(!stack.empty() && stack.back()!='(')
                {
                    output.push_back(stack.back());
                    stack.pop_back();                    
                }
                stack.pop_back();
            }
            else
            {
                while(!stack.empty() && higherPrio(s[i],stack.back()))
                {
                    output.push_back(stack.back());
                    stack.pop_back();
                }
                stack.push_back(s[i]);
            }
        }
        while(!stack.empty())
        {
            output.push_back(stack.back());
            stack.pop_back();
        }
        cout<<output<<'\n';
    }

}