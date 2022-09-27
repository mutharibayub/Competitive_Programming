#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<int> wall(n);
    vector<int> min1Hits(n);
    for(int i=0;i<n;i++)    
    {
        cin>>wall[i];
    }
    int min1=1e9+7,min2=1e9+7;
    for(int i=0;i<n;i++)
    {
        min1Hits[i] = (wall[i]+1)/2;
        if(i)
        {
            int larger=max(wall[i-1],wall[i]);
            int smaller=min(wall[i-1],wall[i]);
            int movesToSame=larger-smaller;
            int movesForLarger=(larger+1)/2;
            int movesForSmaller=smaller;
            if(movesToSame>=movesForSmaller || movesToSame>=movesForLarger)
            {
                if(movesForSmaller>movesForLarger)
                {
                    min2=min(min2,movesForLarger+(movesForSmaller-movesForLarger+1)/2);
                }
                else
                {
                    min2=min(min2,movesForLarger);
                }
            }
            else
            {
                int sameVal=smaller-movesToSame;
                min2=min(min2,movesToSame+(2*sameVal+2)/3);
            }
            if(i+1!=n)
            {
                if((wall[i]+1)/2>wall[i-1] && (wall[i]+1)/2>wall[i+1])
                {
                    min2=min(min2,max(wall[i+1],wall[i-1]));
                }
            }
        }
        // cout<<min2<<" "<<min1Hits[i]<<"\n";
    }
    sort(min1Hits.begin(),min1Hits.end());
    int lowest=min(min2,min1Hits[0]+min1Hits[1]);
    cout<<lowest<<"\n";

    return 0;
}