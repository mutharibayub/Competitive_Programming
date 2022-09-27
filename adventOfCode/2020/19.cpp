#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Rule
{
    vector<vector<string>> statement;
    vector<int> implement(const string &inputStr, const vector<int> &inProgress);
};

vector<Rule> allRules(1000);

vector<int> Rule::implement(const string &inputStr, const vector<int> &inProgress)
{
    vector<int> out;
    for(int i=0;i<statement.size();i++)
    {
        vector<int> progress = inProgress;
        for(int j=0;j<statement[i].size();j++)
        {
            string term = statement[i][j];
            if(term[0]=='"')
            {
                for(int k=0;k<progress.size();k++)
                {
                    if(progress[k]!=-1)
                    for(int l=1;term[l]!='"';l++)
                    {
                        if(inputStr[progress[k]]==term[l])
                        {
                            progress[k]++;
                        }
                        else
                        {
                            progress[k]=-1;
                            break;
                        }
                    }
                }
                vector<int> temp = progress;
                progress.clear();
                for(auto it:temp)
                {
                    if(it!=-1)progress.push_back(it);
                }
            }
            else
            {
                int ruleNum = stoi(term);
                progress = allRules[ruleNum].implement(inputStr, progress);
                if(!progress.size())break;
            }
        }
        for(auto it:progress)out.push_back(it);
    }
    if(out.size()==0)return out;
    sort(out.begin(), out.end());
    vector<int> realOut;
    for(auto it:out)
    {
        if(realOut.empty() || realOut.back()!=it)
        {
            realOut.push_back(it);
        }
    }
    return realOut;
}

int main()
{
    string inp;
    int ruleNum;

    ifstream fin("19_2input.txt");

    vector<string> strInputs;

    bool inputStrings = false;
    while(!fin.eof())
    {
        if(!inputStrings)
        {
            fin >> ruleNum;
            allRules[ruleNum].statement.push_back(vector<string>());
            while(1)
            {
                fin>>inp;
                if(inp[0]=='!')break;
                else if(inp[0]=='x')
                {
                    inputStrings=true;
                    break;
                }
                else if(inp[0]=='|')
                {
                    allRules[ruleNum].statement.push_back(vector<string>());
                }
                else
                {
                    allRules[ruleNum].statement.back().push_back(inp);
                }
            }
        }
        else
        {
            fin >> inp;
            strInputs.push_back(inp);
            fin >> inp;
        }
    }
    int count = 0;
    for(auto strInput:strInputs)
    {
        vector<int> out = allRules[0].implement(strInput, {0});
        for(auto it:out)
        {
            if(it==strInput.size())
            {
                count++;
                break;
            }
        }        
    }
    cout << count <<'\n';
}