#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


template< typename T>
void printContainer(const vector<T>& cl)
{
    std::copy(cl.begin(),       cl.end(),       std::ostream_iterator<T>(std::cout, " "));
    cout << endl;

}

// Longest increasing sub array
vector<int> lisa(const vector<int>& arr)
{
    vector<unsigned int> cl(arr.size(), 0), backT(arr.size(), 0);
    cl.at(0) = 1;
    for(unsigned int i = 1; i < arr.size();++i){
        const int ce = arr.at(i);
        if(ce >= arr.at(i-1)){
            cl[i] = cl[i-1]+1;
            backT[i] = backT[i-1];
        } else {
            cl[i] = 1;
            backT[i] = i;
        }
    }
    vector<unsigned int>::const_iterator it = std::max_element(begin(cl), end(cl));
    cout << "Maximum size of the longest sub array is :: " << *it << endl;
    const unsigned int d = distance(cl.cbegin(), it);
    cout << d << endl;
    printContainer(arr);
    printContainer(cl);
    printContainer(backT);
    vector<int> v(arr.cbegin() + backT.at(d), arr.cbegin() + d + 1);
    printContainer(v);
    return v;
}

int main()
{
    cout << "Hello World!" << endl;
    vector<int> array1 = {5, 6, 3, 5, 7, 8, 9, 1, 2};
    lisa(array1);
    /// ans = {3, 5, 7, 8, 9}
    vector<int> array2 = {12, 13, 1, 5, 4, 7, 8, 10, 10, 11};
    lisa(array2);
    ///The subarray is {4, 7, 8, 10}
    return 0;
}
