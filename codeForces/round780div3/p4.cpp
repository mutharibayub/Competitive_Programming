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
    vector<int> zeros,negs;
    for(int i=0;i<n;i++)
    {
        if(!arr[i])
        {
            zeros.push_back(i);
        }
        else if(arr[i]<0)
        {
            negs.push_back(i);
        }
    }
    vector<int> prods(n);
    for(int i=0;i<n;i++)
    {
        if(!arr[i])continue;
        else if(i==0 || arr[i-1]==0)
        {
            prods[i]=arr[i];
        }
        else
        {
            prods[i]=prods[i-1]*arr[i];
        }
    }
    // cout<<"PRODS\n";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<prods[i]<<" ";
    // }cout<<"\n";
    // return;
    int maxProd=1,maxs=-1,maxe=-1;
    int s=0,e;
    for(int i=0;i<=zeros.size();i++)
    {
        e=i==zeros.size()?arr.size():zeros[i];
        // cout<<"s: "<<s<<" _e: "<<e<<endl;
        if(e-s>=1)
        {
            int prod=(prods[e-1]/prods[s])*arr[s],ts=s,te=e;
            // cout<<prod<<endl;
            if(prod<0)
            {
                int first_neg=*(lower_bound(negs.begin(),negs.end(),ts));
                int last_neg=*(lower_bound(negs.begin(),negs.end(),min(te-1,negs.back())));
                // cout<<"first_neg: "<<first_neg<<" - last_neg: "<<last_neg<<endl;
                int first_portion = prods[first_neg]/prods[ts]*arr[ts];
                int second_portion = prods[te-1]/prods[last_neg]*arr[last_neg];
                // cout<<"first_portion: "<<first_portion<<" _ second_portion: "<<second_portion<<endl;
                if(abs(first_portion)>abs(second_portion))
                {
                    prod=prod/second_portion;
                    te=last_neg;
                }
                else
                {
                    prod=prod/first_portion;
                    ts=first_neg+1;
                }
            }
            // cout<<ts<<" "<<te<<endl;
            if(prod>maxProd)
            {
                maxProd=prod;
                maxs=ts;
                maxe=te;
            }
        }
        s=e+1;
    }
    if(maxs==-1 && maxe==-1)
    {
        cout<<"0 "<<arr.size()<<"\n";
        return;
    }
    cout<<maxs<<" "<<arr.size()-maxe<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // vector<int> arr({1,2,3,6});
    // cout<<(*(lower_bound(arr.begin(),arr.end(),min(5,arr.back()))));

    // return 0;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        testCase();
    }

    return 0;
}