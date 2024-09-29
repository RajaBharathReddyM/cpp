#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int longestCommonSubstring(string X, string Y) {
    int m = X.length();
    int n = Y.length();
    int maxLength = 0;  // Length of the longest common substring
    int endIndex = 0;   // To store the ending point of the longest common substring


    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;  // Store the ending index of the longest substring in X
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }
    if (maxLength == 0) {
        cout << "No Common Substring" << endl;
    } else {
        cout << "Longest Common Substring: " << X.substr(endIndex - maxLength, maxLength) << endl;
    }

    return maxLength;
}

int main() {
    string X, Y;

    // Take user input for the two strings
    cout << "Enter the first string: ";
    cin >> X;
    cout << "Enter the second string: ";
    cin >> Y;

    int length = longestCommonSubstring(X, Y);
    cout << "Length of Longest Common Substring: " << length << endl;

    return 0;
}