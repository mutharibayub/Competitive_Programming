#include <iostream>
#include <vector>

using namespace std;

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> gamesWonBy(n-1);
        int p1=1,p2=2,p1Won=0,p2Won=0;
        bool notPossible = false;
        for(int i=0;i<n-1;i++)
        {
            if((p2Won==x || p2Won==y)&&(p1Won+1<=x || p1Won+1<=y))
            {
                gamesWonBy[i]=p1;
                p2=i+3;
                p1Won++;
                p2Won=0;
            }
            else if((p1Won==x || p1Won==y)&&(p2Won+1<=x || p2Won+1<=y))
            {
                gamesWonBy[i]=p2;
                p1=i+3;
                p2Won++;
                p1Won=0;
            }
            else
            {
                notPossible=true;
                break;
            }
        }
        if((p1Won!=x && p1Won!=y) || (p2Won!=x && p2Won!=y))notPossible=true;
        if(notPossible)
        {
            cout << "-1\n";
            continue;
        }
        for(int i=0;i<gamesWonBy.size();i++)
        {
            if(i)cout << ' ';
            cout << gamesWonBy[i];
        }
        cout << '\n';
    }


    return 0;
}