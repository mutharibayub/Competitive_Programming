#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

int64_t mini(int64_t num1, int64_t num2)
{
    return num1<num2?num1:num2;
}

int64_t abso(int64_t num)
{
    return num<0?num*-1:num;
}

void testCase()
{
    int n,p;
    int64_t sum=0;
    cin>>n>>p;
    vector<vector<int>> data(n,vector<int>(p));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            cin>>data[i][j];
        }
        sort(data[i].begin(),data[i].end());
        if(i==0)
        {
            sum+=data[i].back();
        }
        else
        {
            sum+=data[i].back()-data[i].front();
        }
    }
    int64_t left=abso(data[0].front()-data[0].back()),right=0;
    for(int i=1;i<n;i++)
    {
        int64_t l,r;
        l=mini(left+abso(data[i-1].front()-data[i].front()),right+abso(data[i-1].back()-data[i].front()));
        r=mini(left+abso(data[i-1].front()-data[i].back()),right+abso(data[i-1].back()-data[i].back()));
        left=r;
        right=l;
    }
    sum+=mini(left,right);
    cout<<sum<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        testCase();
    }

    return 0;
}