#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int classes[10] = {2,0,0,1,0,2,1,1,0,1};

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }

        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%10==5)arr[i]+=5;
        }

        sort(arr.begin(), arr.end());

        if(n==1)
        {
            cout << "YES\n";
            continue;
        }

        bool yes=true;
        for(int i=0;i<arr.size()-1;i++)
        {
            int num1 = arr[i], num2 = arr[i+1];
            // cout << num1%10 << ' ' << num2%10 << '\n';
            // cout << classes[num1%10] << ' ' << classes[num2%10] << '\n';
            if(classes[num1%10]==2 && classes[num2%10]==2 && num1%10==0 && num1<num2)
            {
                yes=false;
                break;
            }
            else if((classes[num1%10]==2) ^ (classes[num2%10]==2))
            {
                yes=false;
                break;
            }
            else
            {
                if(!(classes[num1%10]^classes[num2%10]==((num2/10-num1/10)%2)))
                {
                    yes=false;
                    break;
                }
            }
        }
        if(yes)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}