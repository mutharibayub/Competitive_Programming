#include <iostream>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

const int sqrt = 1000;

int main() {
    
    int num = 0;
    map<int, int> locs;

    cin >> num;
    locs[num] = 0;
    for(int i=1;i<sqrt;i++) {
        cout << "+ 1" << endl;
        cin>>num;
        if(locs.find(num) != locs.end()) {
            cout << "! " << i << endl;
            return 0;
        }
        locs[num] = i; 
    }
    for(int i=1;true;i++) {
        cout << "+ " << sqrt << endl;
        cin>>num;
        if(locs.find(num) != locs.end()) {
            assert(locs[num] < sqrt);
            cout << "! " << ((i+1)*sqrt)-1-locs[num] << endl;
            return 0;
        }
    }
    assert(false);

    return 0;
}