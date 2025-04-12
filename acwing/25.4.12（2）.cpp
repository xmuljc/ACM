/*
原题链接：
http://10.26.61.138:3296/contest/44/problem/L414 
*/ 

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k;

    priority_queue<int> max_heap;  
    priority_queue<int, vector<int>, greater<int>> min_heap; 

    for (int i = 0; i < n; ++i) {
        cin >> x;
        max_heap.push(x);
        min_heap.push(x);
    }

    while ((min_heap.size() - 1) % (k - 1) != 0) {
        min_heap.push(0);
    }
    /*
    每次合并，堆数量减少 k - 1，所以总共减少了 (n - 1) 堆：
    t × (k - 1) = n - 1
    (n - 1) % (k - 1) == 0
    */

    int min_cost = 0;
    while (min_heap.size() > 1) {
        int sum = 0;
        for (int i = 0; i < k && !min_heap.empty(); ++i) {
            sum += min_heap.top();
            min_heap.pop();
        }
        min_cost += sum;
        min_heap.push(sum);
    }

    int max_cost = 0;
    while (max_heap.size() > 1) {
        int sum = 0;
        for (int i = 0; i < 2 && !max_heap.empty(); ++i) {
            sum += max_heap.top();
            max_heap.pop();
        }
        max_cost += sum;
        max_heap.push(sum);
    }

    cout << max_cost << " " << min_cost << endl;
    return 0;
}
