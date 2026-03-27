#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); // 優化
    int column, row;
    int  invertMatrix[105][105];
    
    while (cin >> column >> row) {
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {
                cin >> invertMatrix[i][j];
            }
        }
        for (int m = 0; m < row; m++) {
            for (int n = 0; n < column; n++) {
                cout << invertMatrix[n][m] << " \n"[n == column - 1];
            }
        }
    }
    
    return 0;
}
