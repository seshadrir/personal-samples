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

void createPushPop(const string& str, const int i, const int o, const string& source, const string& target, const string sftarget, stack<char> st)
{
    if(i == 0 && o == 0){
        cout << str.substr(1) << endl;
        return;
    }

    if(i > 0) {
        st.push(source[source.size() - i]);
        createPushPop(str + ' ' + 'i', i - 1, o, source, target, sftarget, st);
        st.pop();
    }
    if( o > i){
        char cc = st.top();
        if(target.find(sftarget + cc) != 0)
            return;
        st.pop();
        createPushPop(str + ' ' + 'o', i, o - 1, source, target, sftarget + cc, st);
        st.push(cc);
    }
}


int main()
{
    stack<char> st;
    string source , target ;
    while (cin >> source >> target) {

        stack<char> st;
        const int i = source.size();
        cout << "[" << endl;
        string ss = source, ts = target;
        sort(ss.begin(), ss.end());
        sort(ts.begin(), ts.end());
        if(source.size() == target.size() && ts == ss)
            createPushPop("", i, i, source, target, "", st);
        cout << "]" << endl;
    }
    return 0;
}
