#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <string>
#include <array>
#include <unordered_set>
using namespace std;

int main()
{ 
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<array<int,4>> pairs1({{arr[0],arr[0],arr[1],arr[1]}
                                ,{max(arr[0],arr[1]),arr[1],-1,-1}
                                ,{-1,-1,max(arr[0],arr[1]),arr[1]}});
    vector<array<int,4>> pairs2;
    bool use1=false;
    vector<array<int,4>> *p1=&pairs2;
    vector<array<int,4>> *p2=&pairs1;
    for(int i=2;i<n;i++)
    {
        use1=!use1;
        if(use1)
        {
            p1=&pairs1;
            p2=&pairs2;
        }
        else
        {
            p1=&pairs2;
            p2=&pairs1;
        }
        (*p2).clear();
        int t;
        // cout<<"i: "<<i<<" p1_size: "<<(*p1).size()<<"\n";
        // cout<<"____________________________________\n";
        // if(1)
        // {
        //     for(auto it:(*p1))
        //     {
        //         for(int a=0;a<4;a++)
        //         {
        //             cout<<it[a]<<" ";
        //         }cout<<"\n";
        //     }
        // }cout<<"____________________________________\n";
        for(auto it:(*p1))
        {
            if(it[0]==-1)
            {
                (*p2).push_back({arr[i],arr[i],it[2],it[3]});
            }
            if(it[2]==-1)
            {
                (*p2).push_back({it[0],it[1],arr[i],arr[i]});
            }
            if(it[0]!=-1 && ((it[0]==it[1] && arr[i]>=it[0]) || (arr[i]<=it[1])))
            {
                t=max(it[0],arr[i]);
                (*p2).push_back({t,arr[i],it[2],it[3]});
            }
            if(it[2]!=-1 && ((it[2]==it[3] && arr[i]>=it[2]) || (arr[i]<=it[3])))
            {
                t=max(it[2],arr[i]);
                (*p2).push_back({it[0],it[1],t,arr[i]});
            }
        }
        // cout<<"____________________________________\n";
        // if(1)
        // {
        //     for(auto it:(*p2))
        //     {
        //         for(int a=0;a<4;a++)
        //         {
        //             cout<<it[a]<<" ";
        //         }cout<<"\n";
        //     }
        // }cout<<"____________________________________\n";
        if((*p2).size()==0)
        {
            // cout<<"ENDING AT "<<i<<"\n";
            cout<<"0\n";
            return 0;
        }
    }
    // for(auto it:(*p2))
    // {
    //     for(auto i:(it))
    //     {
    //         cout<<i<<" ";
    //     }cout<<"\n";
    // }
    set<pair<int,int>> count;
    for(auto it:(*p2))
    {
        if(it[0]!=-1 && it[2]!=-1)
        count.insert(make_pair(min(it[0],it[2]),max(it[0],it[2])));
    }   
    cout<<count.size()<<"\n";
}