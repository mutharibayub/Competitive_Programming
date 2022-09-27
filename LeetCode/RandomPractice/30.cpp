// Substring with Concatenation of All Words
#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <algorithm>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, array<int,2>> wordMap;
    wordMap.reserve(words.size());
    for(int i=0;i<words.size();i++)
    {
        if(wordMap.find(words[i]) == wordMap.end())
        {
            wordMap[words[i]]={1,i};
        }
        else
        {
            wordMap[words[i]][0]++;
        }
    }
    vector<int> out;
    for(int i=0;i<words[0].size();i++)
    {
        vector<int> wordWindowMap(words.size(),0);
        int wordWindowMapSize = 0;
        if(i+words[0].size()*words.size() > s.size())break;
        int windowStart = i;
        int windowEnd = i+(words[0].size()*words.size());
        for(int j = windowStart;j<windowEnd;j+=words[0].size())
        {
            string tmp = s.substr(j, words[0].size());
            if(wordMap.find(tmp)!=wordMap.end())
            {
                auto &ref = wordMap[tmp];
                wordWindowMap[ref[1]]++;
                if(wordWindowMap[ref[1]] == ref[0])
                {
                    wordWindowMapSize += ref[0];
                }
            }
        }
        if(wordWindowMapSize==words.size())
        {
            out.push_back(windowStart);
        }
        while(windowEnd+words[0].size() <= s.size())
        {
            string addWord = s.substr(windowEnd, words[0].size());
            string removeWord = s.substr(windowStart, words[0].size());
            //removing word
            if(wordMap.find(removeWord)!=wordMap.end())
            {
                auto &ref = wordMap[removeWord];
                wordWindowMap[ref[1]]--;
                if(wordWindowMap[ref[1]]+1 == ref[0])
                {
                    wordWindowMapSize -= ref[0];
                }
            }
            //adding word
            if(wordMap.find(addWord)!=wordMap.end())
            {
                auto &ref = wordMap[addWord];
                wordWindowMap[ref[1]]++;
                if(wordWindowMap[ref[1]] == ref[0])
                {
                    wordWindowMapSize += ref[0];
                }
            }
            windowStart += words[0].size();
            windowEnd += words[0].size();
            if(wordWindowMapSize==words.size())
            {
                out.push_back(windowStart);
            }
        }
    }
    sort(out.begin(), out.end());
    
    return out;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    vector<int> expectedOutput = {0,9};
    vector<int> actualOutput = findSubstring(s, words);

    assert(expectedOutput == actualOutput);
    cout<<"Solution Correct\n";

    return 0;
}
