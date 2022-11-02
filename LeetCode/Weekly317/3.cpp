#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int digitSum(long long num)
    {
        int sum = 0;
        while(num)
        {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    long long makeLeastZero(long long num)
    {
        long long tmp = num;
        int digitNum = 0;
        int val = tmp%10;
        while(tmp%10==0)
        {
            digitNum++;
            tmp/=10;
            val = tmp%10;
        }
        num += (10ll-val)*(long long)pow(10, digitNum);
        return num;
    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long tmp = n;
        while(digitSum(n)>target)
        {
            n = makeLeastZero(n);
        }
        return n-tmp;
    }
};

int main()
{
    Solution s;
    cout << s.makeIntegerBeautiful(16,6) << '\n';

    return 0;
}
