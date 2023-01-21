#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    int added = 0;
    int minus=0;
    int last = 0;
    for(int jmp=512;jmp;jmp/=2)
    {
        if(jmp+minus>=n)continue;
        int toAdd = (jmp+(n-added%n)%n+minus)%n;
        added+=toAdd;
        cout << "+ " << toAdd << endl;
        int resp;
        cin>>resp;
        if(resp>last)
        {
            last=resp;
        }
        else 
        {
            minus+=jmp;
        }
    }
    cout << "! " << n-minus-1+added << endl;
}