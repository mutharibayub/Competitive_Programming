#include <iostream>
#include <vector>
#include <Algorithm>
using namespace std;

bool compPair(const vector<int>& obj1, const vector<int>& obj2)
{
    return obj1[0]<obj2[0] || (obj1[0]==obj2[0] && obj1[1]<obj2[1]);
}

int getStart(const vector<vector<int>>& arr, int currIndex)
{
    int val = arr[currIndex][0];
    while(currIndex>-1 && arr[currIndex][0] == val)
    {
        currIndex--;
    }
    return currIndex+1;
}

int getEnd(const vector<vector<int>>& arr, int currIndex)
{
    int val = arr[currIndex][0];
    while(currIndex<arr.size() && arr[currIndex][0] == val)
    {
        currIndex++;
    }
    return currIndex-1;
}

int main()
{
    int tileCount;
    vector<vector<int>> bTiles;
    vector<vector<int>> fTiles;
    cin>>tileCount;
    for(int i=0;i<tileCount;i++)
    {
        int price;
        cin>>price;
        bTiles.push_back(vector<int>());
        bTiles[i].push_back(price);
    }
    for(int i=0;i<tileCount;i++)
    {
        int height;
        cin>>height;
        bTiles[i].push_back(height);
        bTiles[i].push_back(i+1);
    }
    for(int i=0;i<tileCount;i++)
    {
        int price;
        cin>>price;
        fTiles.push_back(vector<int>());
        fTiles[i].push_back(price);
    }
    for(int i=0;i<tileCount;i++)
    {
        int height;
        cin>>height;
        fTiles[i].push_back(height);
        fTiles[i].push_back(i+1);
    }
    sort(bTiles.begin(), bTiles.end(), compPair);
    sort(fTiles.begin(), fTiles.end(), compPair);
    for(int i=0;i<tileCount;i++)
    {
        if (fTiles[i][1] >= bTiles[i][1])
        {
            int fStart = getStart(fTiles, i);
            int fEnd = getEnd(fTiles, i);
            int bStart = getStart(bTiles, i);
            int bEnd = getEnd(bTiles, i);
            bool swap = false;
            if (fEnd-fStart>0)
            {
                for(int iter = fStart; iter!=fEnd+1;iter++)
                {
                    if(iter != i)
                    {
                        if(fTiles[iter][1]<bTiles[i][1] && (fTiles[iter][1] >= bTiles[iter][1] || fTiles[i][1]<bTiles[iter][1]))
                        {
                            swap = true;
                            vector<int> temp = fTiles[iter];
                            fTiles[iter] = fTiles[i];
                            fTiles[i] = temp;
                            break;
                        }
                    }
                }
            }
            if(!swap && bEnd-bStart>0)
            {
                for(int iter = bStart; iter!=bEnd+1;iter++)
                {
                    if(iter != i)
                    {
                        if(fTiles[i][1]<bTiles[iter][1] && (fTiles[iter][1] >= bTiles[iter][1] || fTiles[iter][1]<bTiles[i][1]))
                        {
                            swap = true;
                            vector<int> temp = bTiles[iter];
                            bTiles[iter] = bTiles[i];
                            bTiles[i] = temp;
                            break;
                        }
                    }
                }
            }
            if (!swap)
            {
                cout<<"impossible";
                return 0;
            }
        }
    }
    for(int i=0;i<tileCount;i++)
    {
        cout<<bTiles[i][2];
        if(i+1!=tileCount)
        {
            cout<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<tileCount;i++)
    {
        cout<<fTiles[i][2];
        if(i+1!=tileCount)
        {
            cout<<" ";
        }
    }    
}