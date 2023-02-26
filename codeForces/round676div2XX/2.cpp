#include <iostream>
#include <vector>
#include <array>
#include <cassert>

using namespace std;

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
        vector<string> mat(n);
        for(int i=0;i<n;i++)cin>>mat[i];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mat[i][j]-='0';

        vector<array<int,3>> pts = {{0,1,mat[0][1]},{1,0,mat[1][0]},{n-1,n-2,mat[n-1][n-2]},{n-2,n-1,mat[n-2][n-1]}};
        vector<array<int,3>> flip;
        int t1 = 0, t2 = 1;
        if(pts[0][2]==pts[1][2])t1=pts[0][2], t2=t1^1;
        else if(pts[2][2]==pts[3][2])t2=pts[2][2], t1=t2^1;
        for(int i=0;i<4;i++)
        {
            int t = i/2?t2:t1;
            if(pts[i][2]!=t)flip.push_back(pts[i]);
        }
        assert(flip.size()<=2);
        cout << flip.size() << '\n';
        for(int i=0;i<flip.size();i++)
        {
            cout << flip[i][0]+1 << ' ' << flip[i][1]+1 << '\n';
        }
    }


    return 0;
}