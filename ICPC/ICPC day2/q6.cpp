#include <iostream>
#include <vector>
#include <string>
using namespace std;

void vectorizeStr(const string& str, char delim, vector<int>& out)
{
	out.clear();
	string temp="";
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == delim)
		{
			out.push_back(stoi(temp));
			temp = "";
		}
		else
		{
			temp.push_back(str[i]);
		}
		if (!str[i + 1])
		{
			out.push_back(stoi(temp));
		}
	}
}

string testCase()
{
	string str;
	cin >> str;
	vector<int> temp;
	vectorizeStr(str, ',', temp);
	vector<int> scores(temp.size(), 0);
	vector<vector<int>> scoreDict(100, vector<int>());
	int highestScore = -1;
	for (int i = temp.size()-1; i >= 0; i--)
	{
		int max = -1;
		for (int j = highestScore; j >= 0; j--)
		{
			bool found = false;
			if (scoreDict[j].size() == 0)
			{
				continue;
			}
			for (int k = 0; k < scoreDict[j].size(); k++)
			{
				if (temp[scoreDict[j][k]] >= temp[i])
				{
					max = j;
					found = true;
					break;
				}
			}
			if (found) { break; }
		}
		scores[i] = max + 1;
		scoreDict[scores[i]].push_back(i);
		if (scores[i] > highestScore)
		{
			highestScore = scores[i];
		}
	}
	return to_string(highestScore + 1) + "\n";
}

int main()
{
	int testCases;
	cin >> testCases;
	string out="";
	for (int i = 0; i < testCases; i++)
	{
		out += testCase();
	}
	cout << out;
}