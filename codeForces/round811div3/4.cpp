#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>s>>n;
        vector<string> subs(n); 
        for(int i=0;i<n;i++)cin>>subs[i];
        vector<vector<array<int,3>>> ocrns(s.size()); // occurence string id, startindex, endindex 
        for(int a=0;a<subs.size();a++)
        {
            string sub = subs[a];
            for(int i=0;s[i];i++)
            {
                for(int j=0;s[i+j]&&sub[j];j++)
                {
                    if(s[i+j]!=sub[j])break;
                    else if(!sub[j+1])
                    {
                        // cout << "a: " << a << "i: " << i << ' ' << "i+j: " << i+j << endl;
                        for(int k=i+j;k>=i;k--)
                        {
                            ocrns[k].push_back({a+1,i,i+j});
                        }
                    }
                }
            }
        }

        // for(int a=0;a<ocrns.size();a++)
        // {
        //     auto it = ocrns[a];
        //     cout << a <<'\n';
        //     for(auto iter:it)
        //     {
        //         cout << iter[0] << ' ' << iter[1] << ' ' << iter[2] << '\n';
        //     }cout<<'\n';
        // }

        // return 0;

        vector<array<int,2>> ans;
        bool impossible = false;
        for(int i=0;s[i];i++)
        {
            int maxAdd = -1;
            int maxAddStringId = -1;
            int startInd = -1;
            for(auto it:ocrns[i])
            {
                if(it[2] > maxAdd)
                {
                    maxAdd = it[2];
                    maxAddStringId = it[0];
                    startInd = it[1];
                }
            }
            // cout << "i: " << i << " maxAdd: " << maxAdd << endl;
            if(maxAdd == -1)
            {
                impossible=true;
                break;
            }
            i=maxAdd;
            ans.push_back({maxAddStringId, startInd+1});
        }
        if(impossible)
        {
            cout << "-1\n";
            continue;
        }
        cout << ans.size() << '\n';
        for(auto it:ans)
        {
            cout << it[0] << ' ' << it[1] << '\n';
        }
    }

    return 0;
}