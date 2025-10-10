#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
   return a > b;
}
int main() {  // main函数的返回类型应为int
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int A[3];  // 将数组大小更改为3，因为您只读取3个值
    for (int i = 0; i < 3; i++) {
        cin >> A[i];
    }
    if (A[0] == A[1] && A[1] == A[2]) {
        cout << "3 " << A[0];
    } else if (A[0] == A[1] || A[0] == A[2]) {  // 将赋值操作符更改为比较操作符
        cout << "2 ";
        sort(A, A + 3,cmp);
        cout << A[1] << " " << A[2];
    } else if (A[1] == A[2]) {
        sort(A, A + 3,cmp);
        cout << "2 ";
        cout << A[0] << " " << A[1];
    } else {
        sort(A, A + 3,cmp);
        cout << "1 ";
        cout << A[0] << " " << A[1] << " " << A[2];
    }

    return 0;  // 返回0以指示成功
}
