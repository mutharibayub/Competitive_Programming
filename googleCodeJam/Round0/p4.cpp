#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void testCase()
{
    int n;
    cin>>n;
    vector<int> fun(n);
    vector<int> ptr(n);
    vector<int> minParent(n,-1); 
    for(int i=0;i<n;i++)
    {
        cin>>fun[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>ptr[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        if(minParent[i]!=-1)
        {
            fun[i] = max(fun[minParent[i]], fun[i]);
            fun[minParent[i]]=0;
        }
        if(ptr[i]!=0 && (minParent[ptr[i]-1]==-1 || fun[i]<fun[minParent[ptr[i]-1]]))
        {
            minParent[ptr[i]-1]=i;
        }
    }
    int64_t sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=fun[i];
    }
    cout<<sum<<endl;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cout<<"Case #"<<to_string(i+1)<<": ";
        testCase();
    }
    return 0;
}