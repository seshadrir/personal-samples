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
        unsigned int SZ, P;
        cin >> SZ >> P;
        if(SZ == 0 && P == 0)
            return 0;

        unsigned int line = 0, col = 0;

        unsigned int c = (SZ+1)/2;
        if(P == 1) {
            cout << "Line = " << c << ", column = " << c << "." << endl;
            continue;
        }
        unsigned int i = 1;
        for(; i < SZ; i = i+2){
            if(P > (i*i) && P <= (i+2)*(i+2))
                break;
        }
        const unsigned int minimum = c-i/2-1, maximum = c+i/2+1;
        const unsigned int sq = i*i, sq1 = sq+i+1, sq2 = sq1+i+1, sq3 = sq2+i+1;
        if( (P > sq) && (P <= sq1) ){
            line = maximum;
            col = maximum - (P-sq);
        } else if( (P > sq1)  &&  (P <= sq2) ){
            line  = maximum-(P-sq1);
            col = minimum;
        } else if( (P > sq2) && (P <= sq3) ){
            line = minimum;
            col = minimum+(P-sq2);
        } else {
            line = minimum + (P-sq3);
            col = maximum;
        }


        cout << "Line = " << line << ", column = " << col << "." << endl;

    }
}
