#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <queue>
#include <bitset>
#include <set>
#include <map>

using namespace std;

int main()
{
    while(true){
        int S, B;
        cin >> S >> B;
        if(S == 0 && B == 0)
            return 0;
        set<int> s;
        for(int i = 1; i <= S; ++i)
            s.insert(i);
        while(B--){
            int L, R;
            cin >> L >> R;
            set<int>:: iterator f = s.find(L), e = s.find(R);

            if(f == s.begin())
                cout << "*";
            else
                cout << *(--f);

            cout << " ";
            e++;
            if(e == s.end())
                cout << "*";
            else
                cout << *e;

            cout << endl;


            for(int i = L; i <= R; ++i)
                s.erase(i);

        }
        cout << "-" << endl;
    }
    return 0;
}
