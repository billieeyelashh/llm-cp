
#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Create a deque to store the children
    deque<int> children;
    
    // Initialize the deque with the numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        children.push_back(i);
    }
    
    // Initialize a variable to keep track of the removal order
    vector<int> removal_order;
    
    // Perform the game until all children are removed
    while (!children.empty()) {
        // Remove the first child and add it to the removal order
        int removed_child = children.front();
        children.pop_front();
        removal_order.push_back(removed_child);
        
        // If there is still a child left, remove the next child and move it to the end of the deque
        if (!children.empty()) {
            int next_child = children.front();
            children.pop_front();
            children.push_back(next_child);
        }
    }
    
    // Print the removal order
    for (int i = 0; i < n; i++) {
        cout << removal_order[i] << " ";
    }
    
    return 0;
}
