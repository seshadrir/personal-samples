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

bool smallSquare(const vector<string>& big, int i, int j, const vector<string>& small)
{
    for(int k = 0; k < small.size(); ++k) {
        const string ss = big[i+k].substr(j, small.size());
        if(small[k] != ss)
            return false;
    }
    return true;
}

int num(const vector<string>& big, const vector<string>& small)
{
    unsigned int n = 0;

    for(unsigned int i = 0; i <= big.size()-small.size(); ++i){
        for (unsigned int j = 0; j <= big.size()-small.size(); ++j) {
            bool ok = smallSquare(big, i, j, small);
            n = ok?n+1:n;
        }
    }
    return n;
}

vector<string> rotateBy90(const vector<string>& s)
{
    vector<string> r(s.size());
    for(int i = s.size()-1; i >= 0; --i){
        string str = s[i];
        for(unsigned int j = 0; j < str.size();++j){
            r[j] += str[j];
        }
    }


    return r;
}

int main()
{

    while(true){
        int N, n;
        cin >> N >> n;
        if(N == 0 && n == 0)
            return 0;
        vector< string > big, small, small90, small180, small270;
        string l;
        while (N--) {
            cin >> l;
            big.push_back(l);
        }
        while (n--) {
            cin >> l;
            small.push_back(l);
        }
        small90 = rotateBy90(small);
        small180 = rotateBy90(small90);
        small270 = rotateBy90(small180);

        const int a1 = num(big, small) ;
        const int a2 = num(big, small90) ;
        const int a3 = num(big, small180) ;
        const int a4 = num(big, small270) ;

        cout << a1 << " "
             << a2 << " "
             << a3 << " "
             << a4 << endl;

    }

    return 0;
}
