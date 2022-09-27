#include <iostream>
#include <vector>
#include <Algorithm>
#include <unordered_map>
using namespace std;

class playerData
{
public:
    int id;
    vector<int64_t> holeScore;
    int64_t sum = 0;
};

bool comp(const playerData& obj1, const playerData& obj2)
{
    return obj1.sum<obj2.sum;
}

void updatePositions(vector<playerData>& allData, vector<int>& positions) //Updates vector if better rank 
{
    sort(allData.begin(), allData.end(), comp);
    for(int lastCount=0,pos=allData.size(),i=allData.size()-1;i>=0;i--)
    {
        if(i+1!=allData.size() && allData[i].sum!=allData[i+1].sum)
        {
            pos-=lastCount;
            lastCount = 0;
        }
        lastCount++;
        if (pos<positions[allData[i].id-1])
        {
            positions[allData[i].id-1] = pos;
        }
    }   
}

void flattenHoleScore(vector<playerData>& allData, int holeScore)
{
    for(auto oIter = allData.begin();oIter!=allData.end();oIter++)
    {
        for(auto iIter = oIter->holeScore.begin();iIter!=oIter->holeScore.end();iIter++)
        {
            if(*iIter>holeScore)
            {
                oIter->sum-=(*iIter)-holeScore;
                *iIter = holeScore;
            }
        }
    }
}

int main()
{   
    vector<playerData> allData;
    unordered_map<int64_t, int> uniqueHoles;
    int players, holes;
    cin>>players>>holes; //Get intput line 1
    for(int i=0;i<players;i++) //Get input 
    {
        allData.push_back(playerData());
        allData[allData.size()-1].id = i+1;
        for(int j=0;j<holes;j++)
        {
            int64_t val;
            cin>>val;
            allData[allData.size()-1].sum += val;
            allData[allData.size()-1].holeScore.push_back(val);
            uniqueHoles[val] = 0;
        }
    }

    vector<int> uniqueHoleScores;
    for(auto iter = uniqueHoles.begin();iter!=uniqueHoles.end();iter++)
    {
        uniqueHoleScores.push_back(iter->first);
    }
    sort(uniqueHoleScores.rbegin(), uniqueHoleScores.rend());
    vector<int> positions(allData.size(), allData.size());
    updatePositions(allData, positions);

    for(auto iter = uniqueHoleScores.begin()+1;iter!=uniqueHoleScores.end();iter++)
    {
        flattenHoleScore(allData, *iter);
        updatePositions(allData, positions);
    }
    for(int i=0;i<positions.size();i++)
    {
        cout<<positions[i]<<endl;
    }
    return 0;
}