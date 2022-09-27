#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int makeNum(const string& str)
{
	int num = 0;
	for (int i = 0; str[i]; i++)
	{
		num = num * 10 + str[i] - '0';
	}
	return num;
}

string intToString(int num)
{
	string out = "";
	do
	{
		out.push_back(num%10+'0');
		num /= 10;
	}while (num != 0);
	string rout = "";
	for (int i = 0;i< out.size(); i++)
	{
		rout.push_back(out[out.size()-1-i]);
	}
	return rout;
}

bool checkSubstr(const string& str, int start, int stop)
{
	int count = 0;
	stack<char> stk;
	for(int i=start;i<stop;i++)
	{
		if(str[i]=='(')
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	if (count==0)
	{
		return true;
	}
	else
	{
		return false;
	}
} 

string testCase(const string& input)
{
	vector<int> countSubstr(10000,0);
	int maxSubstr=-1;
	stack<char> stk;
	int start;
	for (int i = 0; i < input[i]; i++)
	{
		if (input[i] == '(')
		{
			if (stk.empty())
			{
				start = i;
			}
			stk.push('(');	
		}
		else 
		{
			if(stk.empty())
			{
				continue;
			}
			else
			{
				stk.pop();
				if(stk.empty())
				countSubstr[i-start] += 1;
				if (i-start > maxSubstr)
				{
					maxSubstr = i-start;
				}
			}
		}
	}
	if (maxSubstr == -1) { return "0 1"; }
	return intToString(maxSubstr+1) + " " + intToString(countSubstr[maxSubstr])+"\n";
}

int main()
{
	int testCases;;
	cin >> testCases;
	vector<string> inputs(testCases);
	for (int i = 0; i < testCases; i++)
	{
		cin >> inputs[i];
	}
	string out="";
	for (int i = 0; i < testCases; i++)
	{
		out += testCase(inputs[i]);
	}
	cout << out;
}