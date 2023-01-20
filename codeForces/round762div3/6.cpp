#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int upTables = n%m;
        int upSeats = upTables*((n+m-1)/m);
        vector<vector<int>> upAssignment(k);
        int nxt=0;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<upSeats;j++)
            {
                upAssignment[i].push_back(nxt);
                nxt=(nxt+1)%n;
            }
        }
        vector<vector<int>> dnAssignment(k);
        for(int i=0;i<k;i++)
        {
            nxt=((upAssignment[i].size()?upAssignment[i].back():-1)+1)%n;
            for(int j=0;j<(n-upSeats);j++)
            {
                dnAssignment[i].push_back(nxt);
                nxt=(nxt+1)%n;
            }
        }
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<upTables;j++)
            {
                int tableCount = (n+m-1)/m;
                cout << tableCount;
                for(int k=0;k<tableCount;k++)
                {
                    cout << ' ' << upAssignment[i][j*tableCount+k]+1;
                }cout << '\n';
            }
            for(int j=0;j<(m-upTables);j++)
            {
                int tableCount = n/m;
                cout << tableCount;
                for(int k=0;k<tableCount;k++)
                {
                    cout << ' ' << dnAssignment[i][j*tableCount+k]+1;
                }cout << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}