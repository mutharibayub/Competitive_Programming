#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void testCase()
{
    int n;
    cin>>n;
    string temp;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        for(int j=0;j<n;j++)
        {
            mat[i][j]=temp[j]=='1'?1:0;
        }
    }
    int countOnes=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(mat[i][j])countOnes++;
    int bestScore=1e9+5;
    for(int i=0;i<n;i++)
    {
        pair<int,int> start=make_pair(0,i);
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(mat[start.first][start.second])
            {
                count++;
            }
            start.first=(start.first+1)%n;
            start.second=(start.second+1)%n;
        }   
        bestScore=min(bestScore,(countOnes-count)+(n-count));
    }
    for(int i=0;i<n;i++)
    {
        pair<int,int> start=make_pair(i,0);
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(mat[start.first][start.second])
            {
                count++;
            }
            start.first=(start.first+1)%n;
            start.second=(start.second+1)%n;
        }   
        bestScore=min(bestScore,(countOnes-count)+(n-count));
    }
    cout<<bestScore<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }

    return 0;
}