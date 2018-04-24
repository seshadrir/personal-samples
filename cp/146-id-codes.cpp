#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <string>

using namespace std;

int main()
{
    while(true){
        string s, emp("#");
        cin >> s;
        if(s == emp)
            return 0;

        string sSorted = s;
        std::sort(sSorted.begin(), sSorted.end());
        if(next_permutation(s.begin(), s.end()))
            cout << s << endl;
        else
            cout << "No Successor" << endl;


    }
}
