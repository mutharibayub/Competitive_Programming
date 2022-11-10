#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void testCase()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<int> dp1;
    
    vector<int64_t> sums(n+1);
    int64_t curSum=0;
    sums[0]=0;
    for(int i=0;i<n;i++)
    {
        curSum+=arr[i];
        sums[i+1]=curSum;
        dp1.push_back(i);
    }

    vector<int> dp2;
    vector<int> *mainDp=&dp1;
    vector<int> *secondDp=&dp2;
    // for(int i=0;i<dp1.size();i++)
    // {
    //     cout<<dp1[i]<<" ";
    // }cout<<"\n";
    int k=0;
    while(mainDp->size()!=0)
    {
        k++;
        int64_t curMax=-1;
        int ptr=mainDp->size()-1;
        // cout<<"K Val: "<<k<<"\n";
        for(int i=mainDp->back()-k-1;i>=0;i--)
        {
            int64_t thisSum=sums[i+k+1]-sums[i];
            if((*mainDp)[ptr]==i+k+1)
            {
                ptr--;
                int64_t prevSum=sums[i+2*k+1]-sums[i+k+1];
                curMax=max(curMax,prevSum);
            }
            // cout<<"i Val: "<<i<<"\n";
            // cout<<"Cur Max: "<<curMax<<" This Sum: "<<thisSum<<"\n";
            if(thisSum<curMax)
            {
                secondDp->push_back(i);
            }
        }
        reverse(secondDp->begin(),secondDp->end());
        // for(int i=0;i<secondDp->size();i++)
        // {
        //     cout<<(*secondDp)[i]<<" ";
        // }cout<<"\n";
        vector<int> *t=mainDp;
        mainDp=secondDp;
        secondDp=t;
        secondDp->clear();
    }
    cout<<k<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--)
    {
        testCase();
    }

    return 0;
}