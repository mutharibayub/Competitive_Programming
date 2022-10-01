#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include <unordered_set>

using namespace std;

void addDomin(array<int,2> &arr, int val)
{
    if(arr[0]==-1)arr[0]=val;
    else arr[1]=val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> counts(n+1,0);
        vector<array<int,2>> domins(n+1,{-1,-1});
        vector<int> set1(n+1,0),set2(n+1,0);
        bool yes=true;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            if(!yes || a==b || counts[a]==2 || counts[b]==2)
            {
                yes=false;
                continue;
            }
            counts[a]++;
            counts[b]++;
            addDomin(domins[a], b);
            addDomin(domins[b], a);
        }
        if(!yes)
        {
            cout << "NO\n";
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            // vector<array<int,2>> confs;
            unordered_map<int,int> tmp;
            for(int j=0;j<2;j++)
            {
                if(domins[i][j]==-1 || (j==1 && domins[i][j]==domins[i][j-1]))continue;
                for(int k=0;k<2;k++)
                {
                    if(domins[domins[i][j]][k]!=-1)
                    {
                        if(tmp[domins[i][j]]==2 || tmp[domins[domins[i][j]][k]]==2)
                        {
                            yes=false;
                            break;
                        }
                        tmp[domins[i][j]]++;
                        tmp[domins[domins[i][j]][k]]++;
                        // confs.push_back({domins[i][j],domins[domins[i][j]][k]});
                    }
                }
                if(!yes)break;
            }
            if(!yes)break;
        }
        if(yes)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}