#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testCase()
{
    int r,c;
    cin>>r>>c;
    vector<vector<int>> mat(r,vector<int>(c));
    for(int i=0;i<r;i++)
    {
        string temp;
        cin>>temp;
        for(int j=0;j<c;j++)
        {
            if(temp[j]=='0')mat[i][j]=0;
            else mat[i][j]=1;
        }
    }
    if(mat[0][0]==1)
    {
        cout<<-1<<"\n";
        return;
    }
    vector<vector<int>> coords;
    for(int i=r-1;i>=0;i--)
    {
        for(int j=c-1;j>=0;j--)
        {
            if(mat[i][j])
            {
                int x1=i?i-1:i;
                int y1=i?j:j-1;
                coords.push_back({x1+1,y1+1,i+1,j+1});
            }
        }
    }
    cout<<coords.size()<<"\n";
    for(int i=0;i<coords.size();i++)
    {
        for(int j=0;j<coords[i].size();j++)
        {
            if(j)cout<<" ";
            cout<<coords[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }

    return 0;
}