#include <iostream>
#include <string>
#include <list>
using namespace std;

void listifyStr(const string& str, char delim, list<int>& out)
{
	out.clear();
	string temp = "";
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


int main() {
	int numCases;
	cin >> numCases;
	string inputStr;
	list<int> nums;
	string outputStr = "";
	for (int i = 0; i < numCases; i++)
	{
		cin >> inputStr;
		listifyStr(inputStr.substr(1, inputStr.length() - 1), ',', nums);
		int sum = 0;
		while (nums.size() != 1)
		{
			sum += nums.front() + nums.back();
			if (nums.front() > nums.back())
			{
				nums.pop_front();
			}
			else
			{
				nums.pop_back();
			}
		}
		outputStr += to_string(sum) + "\n";
	}
	cout << outputStr;
	return 0;
}