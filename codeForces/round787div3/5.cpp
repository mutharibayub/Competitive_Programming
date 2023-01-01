#include <iostream>
#include <vector>
#include <string>

using namespace std;

void makePaths(vector<vector<int>> &al, vector<vector<int>> &paths, vector<int> &cpath, int root)
{
    cpath.push_back(root);
    if(al[root].size()==0)
    {
        paths.push_back(cpath);
    }
    else
    {
        makePaths(al,paths,cpath,al[root].front());
        for(int i=1;i<al[root].size();i++)
        {
            vector<int> p;
            makePaths(al,paths,p,al[root][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k>=26)
        {
            cout << string(n,'a') << '\n';
        }
        else
        {
            int cnt=0;
            vector<bool> sub(25,0);
            for(int i=0;s[i]&&cnt<k;i++)
            {
                for(int j=s[i]-'a';j>0&&cnt<k;j--)
                {
                    if(sub[j])continue;
                    else
                    {
                        sub[j]=true;
                        cnt++;
                    }
                }
            }
            for(int i=0;s[i];i++)
            {
                for(int j=s[i]-'a';sub[j];j--)
                {
                    s[i]--;
                }
            }
            cout << s << '\n';
        }
    }

    return 0;
}