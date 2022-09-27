#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

void addNext(array<int,2>& pair, int val)
{
    pair[pair[0]==-1?0:1] = val;
}

bool goToNext(vector<int>& used, vector<array<int,2>>& next, vector<int64_t>& array, vector<int>& newNext, int usedCount, int curIndex)
{   
    used[curIndex]=true;
    if(usedCount==array.size())return true; 
    for(int i=0;i<2;i++)
    {
        if(next[curIndex][i]!=-1 && used[next[curIndex][i]]==false)
        {
            newNext[curIndex]=next[curIndex][i];
            bool ret = goToNext(used,next,array,newNext,usedCount+1,next[curIndex][i]);
            if(ret)return true;
            else 
            {
                newNext[curIndex]=-1;
            }
        }
    }
    used[curIndex] = false;
    return false;
}

int main()
{
    int n;
    vector<int64_t> arr;
    vector<array<int,2>> next;
    cin>>n;
    arr.resize(n);
    next.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        next[i][0]=-1;
        next[i][1]=-1;
    }
    
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++)
    {
        auto iter = lower_bound(arr.begin(),arr.end(),arr[i]*2);
        if(*iter == arr[i]*2)
        {
            addNext(next[i],iter-arr.begin());
        }
        if(arr[i]%3==0)
        {
            iter = lower_bound(arr.begin(),arr.end(),arr[i]/3);
            if(*iter == arr[i]/3)
            {
                addNext(next[i],iter-arr.begin());
            }
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<':';
    //     cout<<next[i][0]<<" "<<next[i][1]<<'\n';
    // }
    // return 0;

    int starter = -1;
    vector<int> used(n,false);
    vector<int> newNext(n,-1);
    for(int i=0;i<n;i++)
    {
        // cout<<"starterIndex:"<<i<<'\n';
        if(goToNext(used,next,arr,newNext,1,i))
        {
            starter=i;
        }
    }

    // cout<<starter<<'\n';
    // return 0;

    cout<<arr[starter]<<' ';
    while(newNext[starter]!=-1)
    {
        cout<<arr[newNext[starter]]<<' ';
        starter=newNext[starter];
    }

    return 0;
}