#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isPrime(vector<int>& cPrimes, int num)
{
    int checkMax = num/2;
    for(int i=0;i<cPrimes.size();i++)
    {
        if(cPrimes[i]>checkMax)
        {
            break;
        }
        if(num%cPrimes[i]==0)
        {
            return false;
        }
    }
    return true;
}

void updatePrimes(vector<int>& cPrimes, int& cMax, int newMax)
{
    for(int i=cMax+1;i<=newMax;i++)
    {
        if(isPrime(cPrimes, i))
        {
            cPrimes.push_back(i);
        }
    }
    cMax = newMax;
}

int main()
{
    int testCases;
    int num1;
    int num2;
    vector<int> primes(1,2);
    int cMax = 2;
    string outputString = "";    
    cin>>testCases;

    for(int i=0;i<testCases;i++)
    {
        cin>>num1>>num2;
        if(num1>cMax)
        {
            updatePrimes(primes, cMax, num1);
        }
        if(num2>cMax)
        {
            updatePrimes(primes, cMax, num2);
        }
        bool num1Prime = isPrime(primes, num1);
        bool num2Prime = isPrime(primes, num2);
        if(num1Prime && num2Prime)
        {
            outputString += "Case #"+to_string(i+1)+": "+to_string(num1+num2)+"\n";
        }
        else if (num1Prime || num2Prime)
        {
            outputString += "Case #"+to_string(i+1)+": "+to_string(num1*num2)+"\n";
        }
        else
        {
            outputString += "Case #"+to_string(i+1)+": not possible\n";
        }
    }
    cout<<outputString;

    return 0;
}