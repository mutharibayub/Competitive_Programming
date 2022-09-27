#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <list>
#include <unordered_map>
#include <unordered_set>


using namespace std;

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    vector<string> allList;

    unordered_map<string, bool> done;
    unordered_map<string, list<pair<string,int>>> adjList;

    ifstream fin("21input.txt");
    while(!fin.eof())
    {
        string temp;
        vector<string> vals;
        while(1)
        {
            fin>>temp;
            if(temp[0]=='|')break;
            vals.push_back(temp);
            done[temp] = false;
            allList.push_back(temp);
        }
        while(1)
        {
            fin>>temp;
            if(temp[0]=='|')break;
            for(int i=0;i<vals.size();i++)
            {
                bool found = false;
                for(auto iter = adjList[temp].begin(); iter!=adjList[temp].end(); iter++)
                {
                    if(iter->first==vals[i])
                    {
                        found = true;
                        iter->second++;
                    }
                }               
                if(!found)
                {
                    adjList[temp].push_back(make_pair(vals[i], 1));
                }

            }
        }   
    }

    unordered_set<string> allergensDone;

    int ambig;
    while(1)
    {
        ambig = 0;
        for(auto it:adjList)
        {
            if(allergensDone.find(it.first)!=allergensDone.end())continue;
            int maxCount = -1;
            string maxVal = "";
            for(auto inIt:it.second)
            {
                if(inIt.second>maxCount && !done[inIt.first])
                {
                    maxCount = inIt.second;
                    maxVal = inIt.first;
                }
            
            }
            int count = 0;
            for(auto inIt:it.second)
            {   
                if(inIt.second == maxCount && !done[inIt.first])
                {
                    count ++;
                }
            }
            if(maxCount == -1)continue;
            if(!(count-1))
            {
                done[maxVal] = true;
                allergensDone.insert(it.first);
            }
            else
            {
                ambig++;
            }
        }
        if(!ambig)break;
    }

    int count = 0;
    unordered_set<string> ingWithoutAllergen;
    for(auto it:done)
    {
        if(!it.second)
        {
            ingWithoutAllergen.insert(it.first);
        }
    }

    for(auto it:allList)
    {
        if(ingWithoutAllergen.find(it)!=ingWithoutAllergen.end())
        {
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}