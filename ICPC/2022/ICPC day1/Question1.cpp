#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<vector<int>> scoreDict;
    int testCases;
    int numCount;
    int maxPrio;
    int* inputNums;
    string outputString = "";
    cin >> testCases;
    for (int i = 0; i < testCases; i++)
    {
        cin >> numCount >> maxPrio;
        string out = "";
        scoreDict.assign(maxPrio, vector<int>());
        const int arrSize = numCount;
        int highestScore=0;
        int highestScoreIndex=0;
        vector<int> inputNums(arrSize, 0);
        vector<int> scoreCount(arrSize, 0);
        scoreCount[0] = 0;
        cin >> inputNums[0];
        scoreDict[0].push_back(0);
        for (int j = 1; j < arrSize; j++)
        {
            scoreCount[j] = 0;
            int maxScore = -1;
            cin >> inputNums[j];
            for (int k = j - 1; k >= 0; k--)
            {
                if (scoreCount[k] > maxScore && inputNums[k] < inputNums[j])
                {
                    maxScore = scoreCount[k];
                }
            }
            scoreCount[j] = maxScore + 1;
            scoreDict[scoreCount[j]].push_back(j);
            if (scoreCount[j] > highestScore || (scoreCount[j] == highestScore && inputNums[j] > inputNums[highestScoreIndex]))
            {
                highestScore = scoreCount[j];
                highestScoreIndex = j;
            }
        }
        int count = 0;
        bool end = false;
        for (int hScore = highestScoreIndex; !end;)
        {
            if (out != "")
            {
                out = to_string(inputNums[hScore]) + " " + out;
            }
            else
            {
                out = to_string(inputNums[hScore]);
            }
            int max = -1;
            int maxIndex = -1;
            if (scoreCount[hScore]-1<0)
            {
                end = true;
            }
            else
            {
                for (int a = 0; a < scoreDict[scoreCount[hScore] - 1].size(); a++)
                {
                    if (inputNums[scoreDict[scoreCount[hScore] - 1][a]] > max && inputNums[scoreDict[scoreCount[hScore] - 1][a]] < inputNums[hScore] && scoreDict[scoreCount[hScore] - 1][a] < hScore)
                    {
                        maxIndex = scoreDict[scoreCount[hScore] - 1][a];
                        max = inputNums[scoreDict[scoreCount[hScore] - 1][a]];
                    }
                }
            }
            if (max == -1)
            {
                end = true;
            }
            count++;
            hScore = maxIndex;
            if (end)
            {
                out = to_string(count) + " " + out;
                break;
            }
        }
        outputString += out + "\n";
        out.clear();
        scoreDict.clear();
    }
    cout << outputString;
}