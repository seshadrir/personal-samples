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
#include <stack>

using namespace std;

int main()
{
    int c = 1;
    while(true) {
        string end("end"), s;
        cin >> s;
        if(s == end)
            return 0;
        vector<stack<char>> cont;
        vector<int> count(26, 0);
        for(unsigned int i = 0; i < s.size(); ++i)
            count[s[i] - 'A']++;

        for(int i = 0; i < s.size(); ++i){
            const unsigned char c = s[i];
            int index = -1;
            for(unsigned int j = 0; j < cont.size(); ++j){
                if(cont[j].top() == c){
                    index = j;
                    cont[j].push(c);
                    break;
                }
            }

            if(index == -1){
                for(unsigned int j = 0; j < cont.size(); ++j){
                    if(cont[j].empty())
                        continue;
                    char tc = cont[j].top();
                    if((count[tc-'A'] == 0) && (c < tc)){
                        cont[j].push(c);
                        index = j;
                        break;
                    }
                }
            }
            if(index == -1){
                for(unsigned int j = 0; j < cont.size(); ++j){
                    if(cont[j].size() == 0){
                        cont[j].push(c);
                        index = j;
                    }
                }
            }
            if(index == -1){
                stack<char> sss;
                sss.push(c);
                cont.push_back(sss);
            }

            count[c-'A']--;

        }


        unsigned int a = 0;
        for(unsigned int i = 0; i < cont.size(); ++i){
            a = (cont[i].size() == 0) ? a : a+1;
        }

        cout << "Case " << c << ": " << a << endl;
        c++;
    }
}
