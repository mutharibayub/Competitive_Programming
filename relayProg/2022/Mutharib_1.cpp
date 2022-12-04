#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//do i really have to do nothing? seriously you have completed this in 7 minutes. that is so cool. i guess i'd just write stories here then 
//for the sake of doing something. did you know intj's are one of the rarest personality type. not doing anything on a code editor is fun
//i should learn speed programming
//i miss malaika//next time please let me code a little // 30 seconds left //do i actually have to do nothing
//doing nothing is more anxiety inducing than doing something in limited amount of time.
//best of luck for the next question 

int main()
{
    string a,b;
    cin>>a>>b;
    if(a.size()<b.size())swap(a,b);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    while(a.size()>b.size())b.push_back('0');
    for(int i=0;i<a.size();i++)
    {
        a[i]=a[i]=='1';
        b[i]=b[i]=='1';
    }
    int carry=0;
    string ans="";
    for(int i=0;i<a.size();i++)
    {
        int v;
        v=a[i]^b[i]^carry;
        carry=((a[i]+b[i]+carry)>1);
        ans.push_back(v);
    }
    if(carry)ans.push_back(carry);
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        ans[i]+='0';
    }
    cout << ans << '\n';

    return 0;
}