// 6. Zigzag Conversion
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = true;

        for (char c : s) {
            rows[currentRow] += c;

            if (currentRow == 0)
                goingDown = true;
            else if (currentRow == numRows - 1)
                goingDown = false;

            if (goingDown)
                currentRow++;
            else
                currentRow--;
        }

        string ans = "";

        for (string row : rows)
            ans += row;

        return ans;
    }
};
