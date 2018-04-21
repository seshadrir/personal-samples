#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>
#include <queue>

using namespace std;


template< typename T>
void printContainer(const vector<T>& cl)
{
    std::copy(cl.begin(),       cl.end(),       std::ostream_iterator<T>(std::cout, " "));
    cout << endl;

}
/// 1. Sort
int findKthSmallestNumberUsingSort(const vector<int>& arr, const unsigned int k)
{
    vector<int> a(begin(arr), end(arr));
    sort(begin(a), end(a));
    return a.at(k);
}

int kthSmallest(vector<int>& arr, const unsigned int begin, const unsigned int end, const unsigned int k)
{
//    assert(begin <= end);
    unsigned int b = begin+1, e = end-1;
    const int pivot = arr[begin];
    while(b <= e){
        while(b < end && arr[b] < pivot)
            b++;
        while (e >= 0 && arr[e] > pivot) {
            e--;
        }
        if(b <= e)
            swap(arr[b], arr[e]);
    }
    swap(arr[begin], arr[e]);
    /// Partition of the array is done
    if(k == e)
        return arr[e];
    if(k < e)
        return kthSmallest(arr, begin, e, k);
    return kthSmallest(arr, e+1, end, k);
}
/// 2. use partial quick sort algorithm
int findKthSmallestNumberUsingPartialQuickSort(vector<int> arr, const unsigned int k)
{
    return kthSmallest(arr, 0, arr.size(), k);
}

/// 4. use max priority queue with size k
int findKthSmallestNumberUsingPQ1(const vector<int>& arr, const unsigned int k)
{
    priority_queue<int > q;
    for(unsigned int i = 0; i < k+1; ++i)
        q.push(arr[i]);
    for(unsigned int i = k+1; i < arr.size(); ++i)
        if(!q.empty() && q.top() > arr[i]){
//            cout << q.top() << endl;
            q.pop();
            q.push(arr[i]);
        }

    return q.top();
}

/// 3. use priority queue o(nlogn)
int findKthSmallestNumberUsingPQ(const vector<int>& arr, const unsigned int k)
{
    priority_queue<int, std::vector<int>, std::greater<int> > q;
    for(const int i : arr){
        q.push(i);
    }
    unsigned int co = k;
    while(co--)
        q.pop();
    return q.top();
}

int main()
{
//    assert(false);
    cout << "Hello World!" << endl;
    vector<int> array1 = {5, 6, 3, 7, 8, 9, 1, 2};
    printContainer(array1);

//    cout << findKthSmallestNumberUsingPQ1(array1, array1.size()/2) << endl;

//    return 1;

    for(unsigned int i = 0; i < array1.size(); ++i)
        cout << i << "th smallest number is " << findKthSmallestNumberUsingSort(array1, i) << endl;

    for(unsigned int i = 0; i < array1.size(); ++i)
        cout << findKthSmallestNumberUsingSort(array1, i) << " " <<  findKthSmallestNumberUsingPartialQuickSort(array1, i) << endl;

    for(unsigned int i = 0; i < array1.size(); ++i)
        cout << findKthSmallestNumberUsingSort(array1, i) << " " <<  findKthSmallestNumberUsingPQ(array1, i) << endl;

    for(unsigned int i = 0; i < array1.size(); ++i)
        cout << findKthSmallestNumberUsingSort(array1, i) << " " <<  findKthSmallestNumberUsingPQ1(array1, i) << endl;

    /// ans = {3, 5, 7, 8, 9}
    vector<int> array2 = {12, 13, 1, 5, 4, 7, 8, 10, 11};
    printContainer(array2);
    for(unsigned int i = 0; i < array2.size(); ++i)
        cout << i << "th smallest number is " << findKthSmallestNumberUsingSort(array2, i) << endl;
    for(unsigned int i = 0; i < array2.size(); ++i)
        cout << findKthSmallestNumberUsingSort(array2, i) << " " <<  findKthSmallestNumberUsingPartialQuickSort(array2, i) << endl;

    for(unsigned int i = 0; i < array2.size(); ++i)
        cout << findKthSmallestNumberUsingSort(array2, i) << " " <<  findKthSmallestNumberUsingPQ(array2, i) << endl;

    for(unsigned int i = 0; i < array2.size(); ++i)
        cout << findKthSmallestNumberUsingSort(array2, i) << " " <<  findKthSmallestNumberUsingPQ1(array2, i) << endl;


    ///The subarray is {4, 7, 8, 10}
    return 0;
}
/***
 * {5, 6, 3, 7, 8, 9, 1, 2};
 * {5, 2, 3, 7, 8, 9, 1, 6};
 * {5, 2, 3, 9, 8, 7, 1, 6};
 *
 * */
