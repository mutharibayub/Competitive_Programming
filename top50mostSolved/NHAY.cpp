#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    int t;
    while(cin>>t)
    {
        string s, p;
        cin>>p>>s;
        if(p.size()>s.size())
        {
            cout << '\n';
            continue;
        }
        vector<int> pfvec(p.size(),0);
        for(int i=1,j=0;p[i];i++)
        {
            if(p[i] == p[j])
            {
                j++;
                pfvec[i]=j;
            }
            else if(j!=0)
            {
                i--;
                j=0;
            }
        }
        
        vector<int> found;
        int i=0;
        int j=0;
        while(s[i])
        {
            if(s[i]==p[j])
            {
                i++,j++;
                if(j==p.size())
                {
                    found.push_back(i-p.size());
                }
            }
            else
            {   
                if(j)
                {
                    j = pfvec[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        if(!found.empty())
        for(auto it:found)
        {
            cout<<it<<'\n';
        }
        else
        {
            cout<<'\n';
        }
    }
    return 0;
}