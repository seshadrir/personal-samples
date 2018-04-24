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
    int N;
    cin >> N;

    while (N--) {
        unsigned int cost = 0;
        int K;
        cin >> K;
        map<char, unsigned int> price;
        char c;
        unsigned int p;
        while(K--) {
            cin >> c >> p;
            price[c] = p;
        }
        unsigned int L;

        cin >> L ;

        const unsigned int _size = 11000;
        char line[_size];
        cin.getline(line, _size);
        for(unsigned int ii = 0; ii < L;++ii){
            if (cin.getline(line, _size)) {
                for(unsigned int i = 0; line[i]; ++i){
                    unsigned char c = line[i];
                    if(price.find(c) != price.end())
                        cost += price[c];
                }
            }
        }
        printf("%.2f$\n", cost*1.0/100);
    }
//    cout << cost << endl;

    return 0;
}
