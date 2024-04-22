#include <iostream>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

using MeraMap = unordered_map<int, string>;
using PairType = pair<int, string>;

// Custom comparison functor to compare pairs based on their first elements
struct ComparePairs {
    bool operator()(const PairType& a, const PairType& b) const {
        return a.first < b.first; // Changed to greater than for min heap behavior
    }
};

int main() {
    MeraMap m;
    m.emplace(1, "Himanshu");
    m.emplace(2, "Kushagra");
    m.emplace(3, "Priyanshu");

    // Using a priority queue with custom comparison function
    priority_queue<PairType, vector<PairType>, ComparePairs> p;

    // Adding elements from unordered_map to priority_queue
    for (const auto& pair : m) {
        p.push(pair);
    }

    // Printing elements from priority_queue
    while (!p.empty()) {
        cout << "The key is: " << p.top().first << "   The value is: " << p.top().second << endl;
        p.pop();
    }

    return 0;
}
