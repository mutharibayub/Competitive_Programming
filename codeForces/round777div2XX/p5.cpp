#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> switcher(n+1);
    vector<bool> isDone(n+1,false);
    vector<int> finalForm(n+1);
    int repeatCount=0;
    for(int i=1;i<=n;i++)
    {
        cin>>switcher[i];
        if(isDone[switcher[i]])
        {
            repeatCount++;
        }
        else
        {
            isDone[switcher[i]]=true;
        }
    }
    int maxFinal=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>finalForm[i];
        maxFinal = max(maxFinal, finalForm[i]);
    }
    int steps=(maxFinal-n)/repeatCount;
    if(!steps)
    {
        for(int i=1;i<=n;i++)
        {
            if(i!=1)cout<<" ";
            cout<<finalForm[i];
        }
        cout<<"\n";
        return 0;
    }
    vector<vector<int>> arr1(n+1);
    vector<vector<int>> arr2(n+1);
    for(int i=1;i<=n;i++)
    {
        arr1[i].push_back(i);
    }
    bool use1=true;
    vector<vector<int>> *a1,*a2;
    int nextNum=n+1;
    for(int iter=0;iter<steps;iter++)
    {
        if(use1)
        {
            a1=&arr1;
            a2=&arr2;
        }
        else
        {
            a1=&arr2;
            a2=&arr1;
        }
        for(int i=1;i<=n;i++)
        {
            if((*a2)[switcher[i]].size()==0)
            {
                (*a2)[switcher[i]]=(*a1)[i];
            }
            else if((*a2)[switcher[i]][0]<=n && (*a1)[i][0]<=n)
            {
                for(auto it:(*a1)[i])
                {
                    (*a2)[switcher[i]].push_back(it);
                }
            
            }
            else
            {
                if((*a2)[switcher[i]][0]>(*a1)[i][0])
                {
                    (*a2)[switcher[i]]=(*a1)[i];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if((*a2)[i].size()==0)
            {
                (*a2)[i].push_back(nextNum);
                nextNum++;
            }
        }
        if(iter+1<steps)
        {
            for(int i=1;i<=n;i++)
            {
                (*a1)[i].clear();
            }
        }
        use1=!use1;
    }
    vector<int> ans(n+1);
    set<int> numsLeft;    
    for(int i=1;i<=n;i++)
    {
        numsLeft.insert(i);
        isDone[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        if((*a2)[i].size()>1)
        {
            sort((*a2)[i].begin(),(*a2)[i].end());
        }
        if((*a2)[i][0]<=n)
        {
            for(auto it:(*a2)[i])
            {
                ans[it]=finalForm[i];
            }isDone[(*a2)[i][0]]=true;
            numsLeft.erase(finalForm[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!isDone[i])
        {
            ans[i]=*(numsLeft.upper_bound(ans[i]));
            numsLeft.erase(ans[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=1)cout<<" ";
        cout<<ans[i];
    }cout<<"\n";
}