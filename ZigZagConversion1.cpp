#include <iostream>
#include <string>
#include <vector>

#define FLAG '#'
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    int blocks = s.size() / (numRows + numRows - 2);
    int remain = s.size() % (numRows + numRows - 2);
    int numCols(0);
    if (remain > 0) {
        if (remain > numRows)
            numCols = (1 + numRows - 2) * blocks + 1 + remain - numRows;
        else if (remain <= numRows)
            numCols = (1 + numRows - 2) * blocks + 1;
    }
    else if (remain == 0)
        numCols = (1 + numRows - 2) * blocks;
    char table[numRows][numCols];

    int k(0);
    if (blocks > 0) {
        for (int i = 0; i < blocks; ++i) {
            for (int n = 0; n < 1 + numRows - 2; ++n) {
                for (int m = 0; m < numRows; ++m) {
                    if (n == 0) {
                        table[m][n + i * (1 + numRows - 2)] = s[k];
                        ++k;
                    }
                    else if (n != 0) {
                        if (m != numRows - n - 1)
                            table[m][n + i * (1 + numRows - 2)] = FLAG;
                        else if (m == numRows - n - 1) {
                            table[m][n + i * (1 + numRows - 2)] = s[k];
                            ++k;
                        }
                    }
                }
            }
        }
    }
    if (remain > 0) {
        if (remain <= numRows) {
            int n = blocks * (1 + numRows - 2);
            for (int m = 0; m < numRows; ++m) {
                if (m < remain) {
                    table[m][n] = s[k];
                    ++k;
                }
                else if (remain <= m)
                    table[m][n] = FLAG;
            }
        }
        else if (numRows < remain) {
            int n = blocks * (1 + numRows - 2);
            for (int m = 0; m < numRows; ++m) {
                table[m][n] = s[k];
                ++k;
            }
            for (int i = 0; i < remain - numRows; ++i) {
                for (int m = 0; m < numRows; ++m) {
                    if (m == numRows - 1 - (i + 1)) {
                        table[m][blocks * (1 + numRows - 2) + i + 1] = s[k];
                        ++k;
                    } else if (m != numRows - 1 - (i + 1))
                        table[m][blocks * (1 + numRows - 2) + i + 1] = FLAG;
                }
            }

        }
    }
    vector<char> charVector;
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (table[i][j] != FLAG)
                charVector.push_back(table[i][j]);
        }
    }
    string str(charVector.begin(), charVector.end());
    return str;
}
int main() {
    string s("PAYPALISHIRING");
    string str = convert(s, 2);
    cout << str;
    return 0;
}
