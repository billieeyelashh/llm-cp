
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string createPalindrome(string s) {
    vector<int> count(26, 0); // Frequency array for characters A-Z

    // Count the occurrences of each character
    for (char c : s) {
        count[c - 'A']++;
    }

    string left = "", right = "";
    string middle = "";

    // Iterate through the frequency array
    for (int i = 0; i < 26; i++) {
        // Divide the count by 2 to get the number of times to include the character in the palindrome
        int numTimes = count[i] / 2;

        // Append the character to both the left and right strings
        left += string(numTimes, 'A' + i);
        right = string(numTimes, 'A' + i) + right;

        // Decrement the count by 2
        count[i] -= (2 * numTimes);
    }

    // Check if there is a character with a count of 1 remaining
    for (int i = 0; i < 26; i++) {
        if (count[i] == 1) {
            middle = 'A' + i;
            break;
        }
    }

    // If there is no character with a count of 1, there is no solution
    if (middle.empty()) {
        return "NO SOLUTION";
    }

    // Concatenate the left, middle, and right strings
    return left + middle + right;
}

int main() {
    string s;
    cin >> s;

    cout << createPalindrome(s) << endl;

    return 0;
}
