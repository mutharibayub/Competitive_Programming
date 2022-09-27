#include <iostream>
#include <vector>
using namespace std;

int getMaxSum(int t)
{
    int lastVal=-1;
    int sum=-1;
    for(int i=1;i<t;i++)
    {
        sum=2*i+t*i-i*i-3*i;
        if(sum<lastVal)
        {
            return lastVal;
        }
        lastVal=sum;
    }
    return -1;
}

int main()
{
    int maxVal=75;
    vector<int> additions(maxVal+1,0);
    vector<int> maxPoints(maxVal+1,0);
    for(int i=1;i<=maxVal;i++)additions[i]=i;
    for(int i=1;i<=maxVal;i++){additions[i]=max(getMaxSum(i),additions[i]);}
    for(int i=0;i<=maxVal;i++)
    {
        for(int j=1;j+i<=maxVal;j++)
        {
            maxPoints[i+j]=max(maxPoints[i]+additions[j],maxPoints[i+j]);
            if(i+j==75)cout<<maxPoints[i+j]<<endl;
        }
    }
    for(int i=0;i<=75;i++)
    {
        cout<<i<<" : "<<additions[i]<<endl;
    }
    return 0;
}