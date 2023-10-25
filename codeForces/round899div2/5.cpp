#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>

using namespace std;

typedef long long ll;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

void doOp(vector<int> &arr, vector<int> &steps, int num)
{
    int loc=-1;
    for(int i=0;i<arr.size()&&loc==-1;i++)
        if(arr[i]==num)
            loc=i;
    steps.push_back(loc+1);
    vector<int> tmp;
    tmp.insert(tmp.end(), arr.begin()+loc+1, arr.end());
    tmp.insert(tmp.end(), arr.begin()+loc, arr.begin()+loc+1);
    tmp.insert(tmp.end(), arr.begin(), arr.begin()+loc);
    arr = tmp;
}

void doSort(vector<int> &arr, vector<int> &steps)
{
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==i+1)
            continue;
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]!=i+1)
                continue;
            int t1=arr[i], t2=arr[j];
            doOp(arr, steps, t1);
            doOp(arr, steps, t2);
            doOp(arr, steps, t1);
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tttt=1;
    // cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> a(n), b(m), stepsa, stepsb;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        doSort(a, stepsa);
        doSort(b, stepsb);
        if(int(stepsa.size())%2!=int(stepsb.size())%2 && n%2==0 && m%2==0)
        {
            cout << -1 << '\n';
            continue;
        }
        if(int(stepsa.size())%2!=int(stepsb.size())%2)
        {
            if(n%2)
            {
                for(int i=0;i<n;i++)
                {
                    stepsa.push_back(n);
                }
            }
            else
            {
                for(int i=0;i<m;i++)
                {
                    stepsb.push_back(m);
                }       
            }
        }
        while(abs((int)stepsa.size()-(int)stepsb.size()))
        {
            if(stepsa.size() < stepsb.size())
            {
                stepsa.push_back(n);
                stepsa.push_back(1);
            }
            else 
            {
                stepsb.push_back(m);
                stepsb.push_back(1);
            }
        }
        cout << (int)stepsa.size() << '\n';
        for(int i=0;i<(int)stepsa.size();i++)
        {
            cout << stepsa[i] << ' ' << stepsb[i] << '\n';
        }
    }
    return 0;
}