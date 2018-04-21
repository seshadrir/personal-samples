#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <queue>
#include <bitset>
#include <set>

using namespace std;

/// Lessons learned: Create a test case for edge cases.

int main()
{
    int a[3002], v;
    unsigned int k = 0;
    while (scanf("%d", &k) != EOF) {
        for(unsigned int i = 0; i < k; ++i){
            scanf("%d", &v);
            a[i] = v;
        }
        set<unsigned int> b;
        for(unsigned int i = 1; i < k; ++i)
            b.insert(abs(a[i] - a[i-1]));



        bool jolly = (k == 1 && a[0] == 1) /// This case should have been handled by me but I missed it
                || ((b.size() == k-1) && (*b.begin() == 1) && (*b.rbegin() == k-1));

        if(jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }



    return 0;
}
