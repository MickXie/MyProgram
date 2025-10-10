#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); // 優化
    cin.tie(0); // 優化

    long long int num;
    for (;;) {
        if (!(cin >> num)) {
            break; // 终止循环，当输入无法读取时（比如输入非整数或者文件结束符）
        }
        cin >> num;
        bool first = true;
        for(int i = 2; i <=num;i++) {
            int cum=0;
            while(num%i==0){
                num=num/i;
                cum++;
            }
            if(cum>=1){
                if(!first) cout << " * ";
                first = false;
                if (cum>1){
                    cout << i << '^' << cum;
                }else{
                    cout << i ;
                }
            }
        }
    }
    return 0;
}
