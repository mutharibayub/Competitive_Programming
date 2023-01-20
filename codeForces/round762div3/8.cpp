#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int jmp = sqrt(1e5);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,q;
    cin>>n>>q;
    vector<int> nxt(n),prv(n),nxtJmp(n,-1);
    for(int i=0;i<n;i++)
    {
        int pi;
        cin>>pi;
        pi--;
        nxt[i]=pi;
        prv[pi]=i;
    }
    for(int i=0;i<n;i++)
    {
        int jmpVal=i;
        for(int j=0;j<jmp;j++)
        {
            jmpVal=nxt[jmpVal];
        }
        nxtJmp[i]=jmpVal;
    }
    for(int i=0;i<q;i++)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,y;
            cin>>x>>y;
            x--,y--;
            swap(nxt[x],nxt[y]);
            prv[nxt[x]]=x;
            prv[nxt[y]]=y;
            int lst=nxt[x];
            int cur=nxt[x];
            for(int i=0;i<jmp;i++)
            {
                lst=prv[lst];
            }
            for(int i=0;i<jmp;i++)
            {
                nxtJmp[lst]=cur;
                lst=nxt[lst];
                cur=nxt[cur];
            }
            lst=nxt[y];
            cur=nxt[y];
            for(int i=0;i<jmp;i++)
            {
                lst=prv[lst];
            }
            for(int i=0;i<jmp;i++)
            {
                nxtJmp[lst]=cur;
                lst=nxt[lst];
                cur=nxt[cur];
            }
        }
        else
        {
            int idx,jm;
            cin>>idx>>jm;
            idx--;
            while(jm>=jmp)
            {
                idx=nxtJmp[idx];
                jm-=jmp;
            }
            for(int j=0;j<jm;j++)
            {
                idx=nxt[idx];
            }
            cout << idx + 1 << '\n';
        }
    }
}