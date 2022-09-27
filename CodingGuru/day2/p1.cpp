#include <iostream>
#include <vector>
#include <string>
#include <Algorithm>
#include <map>
using namespace std;

string testCase()
{
    string out = "";
    int carCount;
    map<int, vector<int>> carTimes;
    cin >> carCount;
    int moreThanTwo = 0;
    for (int i = 0; i < carCount; i++)
    {
        int carTime;
        cin >> carTime;
        if (carTimes.find(carTime) == carTimes.end())
        {
            carTimes[carTime] = vector<int>({ i });
        }
        else
        {
            carTimes[carTime].push_back(i);
            moreThanTwo++;
        }
    }
    if (moreThanTwo <= 1)
    {
        return "IMPOSSIBLE\n";
    }
    out += "POSSIBLE\n";
    string possibs[3] = { "","","" };
    int possibCount = 1;
    for (auto iter = carTimes.begin(); iter != carTimes.end(); iter++)
    {
        if(possibCount == 3 || iter->second.size()==1)
        for (int i = 0; i < iter->second.size(); i++)
        {
            for(int j=0;j<possibCount;j++)
            possibs[j] += to_string(iter->second[i]+1) + " ";
        
        }
        else if(possibCount==1)
        {
            if(iter->second.size()>=3)
            {   
                for(int i=0;i<iter->second.size()-3;i++)
                {
                    possibs[0] += to_string(iter->second[i]+1) + " ";
                }
                possibs[1] = possibs[2] = possibs[0];
                possibs[0] += to_string(iter->second[iter->second.size()-3]+1) + " " + to_string(iter->second[iter->second.size()-2]+1) + " " + to_string(iter->second[iter->second.size()-1]+1) + " ";
                possibs[1] += to_string(iter->second[iter->second.size()-3]+1) + " " + to_string(iter->second[iter->second.size()-1]+1) + " " + to_string(iter->second[iter->second.size()-2]+1) + " ";
                possibs[2] += to_string(iter->second[iter->second.size()-2]+1) + " " + to_string(iter->second[iter->second.size()-3]+1) + " " + to_string(iter->second[iter->second.size()-1]+1) + " ";
                possibCount = 3;
            }
            else if(iter->second.size()==2)
            {
                possibs[1] = possibs[0];
                possibs[0] += to_string(iter->second[0]) + " " + to_string(iter->second[1]) + " ";
                possibs[1] += to_string(iter->second[1]) + " " + to_string(iter->second[0]) + " ";
                possibCount = 2;
            }
        }
        else 
        {
            if(iter->second.size()>=3)
            {   
                for(int i=0;i<iter->second.size()-3;i++)
                {
                    possibs[0] += to_string(iter->second[i]+1) + " ";
                    possibs[1] += to_string(iter->second[i]+1) + " ";
                }
                possibs[2] = possibs[0];
                possibs[0] += to_string(iter->second[iter->second.size()-3]+1) + " " + to_string(iter->second[iter->second.size()-2]+1) + " " + to_string(iter->second[iter->second.size()-1]+1) + " ";
                possibs[1] += to_string(iter->second[iter->second.size()-3]+1) + " " + to_string(iter->second[iter->second.size()-2]+1) + " " + to_string(iter->second[iter->second.size()-1]+1) + " ";
                possibs[2] += to_string(iter->second[iter->second.size()-3]+1) + " " + to_string(iter->second[iter->second.size()-1]+1) + " " + to_string(iter->second[iter->second.size()-2]+1) + " ";
                possibCount = 3;
            }
            else if(iter->second.size()==2)
            {
                possibs[2] = possibs[0];
                possibs[0] += to_string(iter->second[0]) + " " + to_string(iter->second[1]) + " ";
                possibs[1] += to_string(iter->second[0]) + " " + to_string(iter->second[1]) + " ";
                possibs[2] += to_string(iter->second[1]) + " " + to_string(iter->second[0]) + " ";
                possibCount = 3;
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        possibs[i] = possibs[i].substr(0, possibs[i].size()-1);
        out += possibs[i] + "\n"; 
    }
    return out;
}

int main()
{
    int testCases;
    string out;
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        out += testCase();
    }
    cout << out;
    return 0;
}