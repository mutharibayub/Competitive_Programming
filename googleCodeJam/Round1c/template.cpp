#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
using namespace std;

bool checkValid(const string& s)
{
    vector<bool> done(26,false);
    char curChar='0';
    for(int i=0;s[i];i++)
    {
        if(curChar!=s[i])
        {
            if(done[s[i]-'A'])return false;
            if(curChar!='0')done[curChar-'A']=true;
            curChar=s[i];
        }
    }
    return true;
}

bool singleChar(const string& s)
{
    for(int i=1;s[i];i++)
    {
        if(s[i]!=s[0])return false;
    }
    return true;
}

void testCase()
{
    int n;
    cin>>n;
    vector<string> inStrings(n);
    for(int i=0;i<n;i++)
    {
        cin>>inStrings[i];
    }
    for(int i=0;i<n;i++)
    {
        if(!checkValid(inStrings[i]))
        {
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    list<string> li;
    int doneCount=0;
    vector<int> done(n,false);
    for(int i=0;i<n;i++)
    {
        // if(!i)
        // {
        //     for(int a=0;a<n;a++)
        //     {
        //         if(!done[a])cout<<inStrings[a]<<" ";
                
        //     }cout<<'\n';
        // }
        if(!done[i] && singleChar(inStrings[i]))
        {
            for(int j=0;j<n;j++)
            {
                if(!done[j] && i!=j && inStrings[i][0]==inStrings[j].front())
                {
                    inStrings[i]+=inStrings[j];
                    done[j]=true;
                    doneCount++;
                    i=-1;
                    break;
                }
                if(!done[j] && i!=j && inStrings[i][0]==inStrings[j].back())
                {
                    inStrings[j]+=inStrings[i];
                    done[i]=true;
                    doneCount++;
                    i=-1;
                    break;
                }
            }
        }
    }
    // cout<<"\n";
    // for(int i=0;i<n;i++)
    // {
    //     if(!done[i])
    //     {
    //         cout<<inStrings[i]<<" ";
    //     }
    // }cout<<"\n";
    // return;
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            if(li.empty() || li.back().back()==inStrings[i].front())
            {
                li.push_back(inStrings[i]);
                done[i]=true;
                i=-1;
            }
            else if(li.empty() || li.front().front()==inStrings[i].back())
            {
                li.push_front(inStrings[i]);
                done[i]=true;
                i=-1;
            }
        }
    }
    string ans="";
    for(auto it:li)
    {
        ans+=it;
    }
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            ans+=inStrings[i];
        }
    }
    if(!checkValid(ans))
    {
        // cout<<"_"<<ans<<"\n";
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // string a="CODE";
    // cout<<checkValid(a)<<"\n";

    // return 0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        testCase();
    }
}