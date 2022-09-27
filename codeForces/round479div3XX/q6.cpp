#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> next(n);
    vector<int> score(n);
    unordered_map<int,int> dict;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int maxScoreInd = -1;
    int maxScore=-1;

    for(int i=n-1;i>=0;i--)
    {
        next[i]=-1;
        score[i]=1;
        if(dict.find(arr[i]+1)!=dict.end())
        {
            next[i]=dict[arr[i]+1];
            score[i]=score[dict[arr[i]+1]]+1;
        }
        if(dict.find(arr[i])==dict.end() || score[dict[arr[i]]]<score[i])
        {
            dict[arr[i]]=i;
        }

        if(score[i]>maxScore)
        {
            maxScoreInd=i;
            maxScore=score[i];
        }
    }

    cout<<maxScore<<'\n';
    while(true)
    {
        cout<<maxScoreInd+1;
        maxScoreInd = next[maxScoreInd];
        if(maxScoreInd==-1)
        {
            cout<<'\n';
            break;
        }
        cout<<' ';
    }
}