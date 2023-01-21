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
        int n,m;
        cin>>n>>m;
        array<int,3> locs[2][1000];
        for(int i=0;i<1000;i++)locs[0][i]=locs[1][i]={-1,-1,-1};
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for(int j=0;j+1<s.size();j++)
            {
                int num=(s[j]-'0')*10+s[j+1]-'0';
                locs[0][num]={j,j+1,i};
                if(j+2<s.size())
                {
                    num=(num*10)+s[j+2]-'0';
                    locs[1][num]={j,j+2,i};
                }
            }
        }
        string s;
        cin>>s;
        vector<array<int,3>> ans(s.size(),{-1,-1,-1});
        for(int i=0;i+1<s.size();i++)
        {
            if(i&&ans[i-1]==array<int,3>({-1,-1,-1}))continue;
            int num=(s[i]-'0')*10+s[i+1]-'0';
            if(locs[0][num]!=array<int,3>({-1,-1,-1}))
            {
                ans[i+1]=locs[0][num];
            }
            if(i+2<s.size())
            {
                num=num*10+s[i+2]-'0';
                if(locs[1][num]!=array<int,3>({-1,-1,-1}))
                {
                    ans[i+2]=locs[1][num];
                }   
            }
        }
        if(ans.back()!=array<int,3>({-1,-1,-1}))
        {
            vector<array<int,3>> out;
            int idx = s.size()-1;
            while(idx>=0)
            {
                out.push_back(ans[idx]);
                idx-=ans[idx][1]-ans[idx][0]+1;
            }
            cout << out.size() << '\n';
            for(int i=out.size()-1;i>=0;i--)
            {
                for(int j=0;j<3;j++)
                {
                    if(j)cout << ' ';
                    cout << out[i][j]+1;
                }cout << '\n';
            }
        }
        else
        {
            cout << -1 << '\n';
        }


    }

    return 0;
}