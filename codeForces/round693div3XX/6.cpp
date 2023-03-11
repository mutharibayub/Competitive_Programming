#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <map>
#include <cassert>
#include <set>

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
        map<int,array<bool,2>> blocks;
        for(int i=0;i<m;i++)
        {
            int r, c;
            cin>>r>>c;
            --r,--c;
            if(blocks.find(c)==blocks.end())blocks[c]={0,0};
            blocks[c][r]=true;
        }

        int col = -1;
        int dp=0;
        bool ok = true;
        for(auto block:blocks)
        {
            int nxt=-1;
            int mask = block.second[0]+block.second[1]*2;
            
            assert(mask>0&&mask<4);
            if(mask==3)
            {
                if(dp==0)nxt=dp;
            }
            else
            {
                if(dp==0)nxt=mask^3;
                else
                {
                    int nowState=-1;
                    if((block.first-col)%2)nowState=dp;
                    else nowState=dp^3;
                    if(nowState!=mask)nxt=0;
                }
            }

            dp=nxt;
            col=block.first;
            if(dp==-1)ok=false;
            if(!ok)break;
        }
        if(dp!=0)ok=false;

        cout << (ok?"YES":"NO") << '\n';
    }   

    return 0;
}