#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> q;
    
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<arr.size();j++)
        {
            if(i==j)continue;
            pair<double,pair<int,int>> a = make_pair(double(arr[i])/double(arr[j]), make_pair(arr[i],arr[j]));
            q.push(a);
        }
    }
    pair<double,pair<int,int>> out;
    for(int i=0;i<k && !q.empty();i++)
    {
        out=q.top();
        q.pop();
    }
    return vector<int>({out.second.first,out.second.second});
}

int main()
{
    return 0;
}