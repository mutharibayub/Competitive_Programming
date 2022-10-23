#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{
    for(int i=2;i<num;i++)
    {
        if(!(num%i))return false;
    }return true;
}

int main()
{
    vector<int> primes;
    for(int i=2;i<50;i++)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }
    string inp;
    int divCount = 0;
    int mult = 1;
    for(int i=0;i<primes.size()&&primes[i]*mult<100;i++)
    {
        cout << "? " << primes[i]*mult << endl;
        cin >> inp;
        if(inp=="yes")
        {
            divCount++;
            mult*=primes[i];
            i--;  
        }
        if(divCount>1)
        {
            cout << "! composite" << endl;
            return 0;
        }
    }
    cout << "! prime" << endl;

    return 0;
}