
#include <iostream>
#include <queue>
#include <map>
using namespace std;

string reorderString(string s) {
    int n = s.length();
    
    // Count the frequency of each character
    map<char, int> freq;
    for(char c : s) {
        freq[c]++;
    }
    
    // Initialize result string and priority queue
    string result = "";
    priority_queue<pair<int, char>> pq;
    
    // Push characters into priority queue based on their frequencies
    for(auto it : freq) {
        pq.push({it.second, it.first});
    }
    
    // Reorder the string
    while(!pq.empty()) {
        pair<int, char> curr = pq.top();
        pq.pop();
        
        // Append the character to the result string
        result += curr.second;
        
        // Decrease the frequency by 1
        curr.first--;
        
        // Push the character back into the priority queue if its frequency is still greater than 0
        if(curr.first > 0) {
            pq.push(curr);
        }
    }
    
    // If the result string is not complete, it is not possible to create a valid string
    if(result.length() != n) {
        return "-1";
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    string result = reorderString(s);
    cout << result << endl;
    
    return 0;
}
