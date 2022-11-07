#include <iostream>
#include <vector>
#include <array>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string a,b;
        cin>>n>>a>>b;
        bool eq = a[0]==b[0], possible=true;
        for(int i=1;i<n;i++)
        {
            possible = (a[i]==b[i])==eq;
            if(!possible)break;
        }
        if(!possible)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        vector<array<int,2>> steps;
        int count=0;
        for(int i=0;i<n||(i==n&&count);i++)
        {
            if(i<n && b[i]=='1')
            {
                count++;
            }
            else if(count)
            {
                int l = i-count+1;
                int r = i;
                if(count>1)
                {
                    steps.push_back({l, l});
                    steps.push_back({l+1, r}); 
                }
                else
                {
                    if(l>1)
                    {
                        steps.push_back({1,r});
                        steps.push_back({1,l-1});
                    }
                    else
                    {
                        steps.push_back({l,n});
                        steps.push_back({r+1,n});
                    }
                }
                count=0;
            }
        }
        if(!eq)
        {
            steps.push_back({1,n});
        }
        cout << steps.size() << '\n';
        for(int i=0;i<steps.size();i++)
        {
            cout << steps[i][0] << ' ' << steps[i][1] << '\n';
        }
    }

    return 0;
}