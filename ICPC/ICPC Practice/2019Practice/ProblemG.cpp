#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int getNum(const string::iterator& begin, const string::iterator& end)
{
    int out = 0;
    auto b = begin;
    for(;b!=end;b++)
    {
        out = (out*10) + (*b) - '0';
    }
    return out;
}

int main()
{
    int ladiesCount;
    int queryCount;
    string temp;
    vector<pair<char,int>> ladies;    
    unordered_map<char, vector<int>> dict;
    for(char i='A';i<='Z';i++)
    {
        dict[i] = vector<int>();
    }
    getline(cin, temp);
    int t = temp.find(' ');
    ladiesCount = getNum(temp.begin(), temp.begin()+t);
    queryCount = getNum(temp.begin()+t+1, temp.end());
    for(int i=0;i<ladiesCount;i++)
    {
        getline(cin, temp);
        ladies.push_back({temp[0],getNum(temp.begin()+2, temp.end())-1});
        dict[temp[0]].push_back(i);
    }
    string query = "";
    vector<int> toRemove;
    vector<int> outputVals;
    for(int i=0;i<queryCount;i++)
    {
        cin>>query;
        int removeCount = 0;
        for(int iter=0;iter<dict[query[0]].size();iter++)
        {
            bool remove = false;
            int currIndex = dict[query[0]][iter];
            for(int j=1;query[j];j++)
            {
                if (currIndex == 0 || ladies[ladies[currIndex].second].first != query[j])
                {
                    remove = true;
                    removeCount++;
                    break;
                }
                currIndex = ladies[currIndex].second;
            }
        }
        outputVals.push_back(dict[query[0]].size()-removeCount);
    }
    for(auto iter = outputVals.begin();iter!=outputVals.end();iter++)
    {
        cout<<*iter<<endl;
    }

    return 0;
}