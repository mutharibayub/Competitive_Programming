#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
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

    unordered_map<int,array<int,2>> maxScore;
    maxScore.reserve(2e5+1);
    int maxScoreNum = -1;
    vector<int> next(n,-1);
    for(int i=n-1;i>=0;i--)
    {
        if(maxScore.find(arr[i])==maxScore.end())
        {
            if(maxScore.find(arr[i]+1)==maxScore.end())
            {
                maxScore[arr[i]]={1, i};
            }
            else
            {
                maxScore[arr[i]]={maxScore[arr[i]+1][0]+1, i};
                next[i]=maxScore[arr[i]+1][1];
            }
        }
        else if(maxScore.find(arr[i]+1)!=maxScore.end() && maxScore[arr[i]+1][0]+1 > maxScore[arr[i]][0])
        {       
            maxScore[arr[i]] = {maxScore[arr[i]+1][0]+1, i};
            next[i]=maxScore[arr[i]+1][1];
        }
        if(maxScoreNum==-1 || maxScore[arr[i]][0]>maxScore[maxScoreNum][0])
        {
            maxScoreNum = arr[i];
        }
    }
    int k = maxScore[maxScoreNum][0], start = maxScore[maxScoreNum][1];
    cout << k << '\n';
    while(start!=-1)
    {
        cout << start+1 << ' ';
        start = next[start];
    }
    cout << '\n';
}