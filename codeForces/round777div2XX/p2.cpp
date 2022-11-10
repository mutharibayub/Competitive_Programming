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
    if(r==1 || c==1)
    {
        cout<<"YES\n";
        return;
    }
    for(int i=0;i<r-1;i++)
    {
        for(int j=0;j<c-1;j++)
        {
            int sum=mat[i][j]+mat[i+1][j]+mat[i+1][j+1]+mat[i][j+1];
            if(sum==3)
            {
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
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
}