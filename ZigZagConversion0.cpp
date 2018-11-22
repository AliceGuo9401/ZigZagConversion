#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*start*/
#define FLAG '#'

string convert(string s, int numRows) {
    if(numRows == 1)
        return s;

    else if(numRows < s.size() && s.size() < (numRows + numRows - 2)) {
        int numCols = s.size() - numRows + 1;
        char table[numRows][numCols];   //二维数组
        int k(0);

        for(int m = 0; m < numCols; ++m) {
            for(int n = 0; n < numRows; ++n) {
                if(m == 0) {
                    table[n][m] = s[k];
                    ++k;
                }else if(m != 0) {
                    if(n == numRows - 1 - m) {
                        table[n][m] = s[k];
                        ++k;
                    }else if(n != numRows - 1 - m) {
                        table[n][m] = FLAG;
                    }
                }
            }
        }
        vector<char> strTemp;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (table[i][j] != FLAG)
                    strTemp.push_back(table[i][j]);
            }
        }

        string str(strTemp.begin(), strTemp.end());
        return str;
    }

    else {
        int blocks = s.size() / (numRows + numRows - 2);
        int remain = s.size() % (numRows + numRows - 2);
        int cols = 1 + (numRows - 2);
        int numCols(0);
        if (remain > 0) {
            if(remain - numRows > 0)
                numCols = cols * blocks + 1 + remain - numRows;
            else if(remain - numRows <= 0)
                numCols = cols * blocks + 1;
        }
        else if (remain == 0)
            numCols = cols * blocks;

        int k(0);
        char table[numRows][numCols];

        if (blocks > 0) {
            for (int i = 0; i < blocks; ++i) {
                for (int m = 0; m < cols; ++m) {
                    for (int n = 0; n < numRows; ++n) {
                        if (m == 0) {
                            table[n][cols * i + m] = s[k];
                            ++k;
                        } else if (m != 0) {
                            if (n == numRows - 1 - m) {
                                table[n][cols * i + m] = s[k];
                                ++k;
                            } else if (n != numRows - 1 - m)
                                table[n][cols * i + m] = FLAG;
                        }
                    }
                }
            }
        }

        if (0 < remain && remain <= numRows ) {
            for (int i = 0; i < numRows; i++) {
                if (i < remain) {
                    table[i][numCols - 1] = s[k];
                    ++k;
                } else if (remain <= i)
                    table[i][numCols - 1] = FLAG;
            }
        }else if(remain > numRows) {
            int remainStart = cols * blocks;
            for(int m = remainStart; m < numCols; ++m) {
                for(int n = 0; n < numRows; ++n) {
                    if(m == remainStart) {
                        table[n][m] = s[k];
                        ++k;
                    }else if(m != remainStart) {
                        if(n == numRows - 1 - (m - remainStart)) {
                            table[n][m] = s[k];
                            ++k;
                        }else if(n != numRows - 1 - (m - remainStart)) {
                            table[n][m] = FLAG;
                        }
                    }
                }
            }
        }

        //打印“之”字形
        /*for(int i = 0; i < numRows; ++i) {
            for(int j = 0; j < numCols; ++j) {
                cout << table[i][j] << ' ';
            }
            cout << endl;
        }
        return 0;*/

        vector<char> strTemp;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (table[i][j] != FLAG)
                    strTemp.push_back(table[i][j]);
            }
        }
        string str(strTemp.begin(), strTemp.end());
        return str;
    }
}
/*end*/

int main() {
    string s("PAYPALISHIRING");
    int numRows(5);
    string str = convert(s, numRows);
    cout << str;
    return 0;
}
