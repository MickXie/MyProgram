#include <iostream>
#include <cstdlib>
using namespace std;
int val;
int main()
{
    int x = 3;
    cout << (double)x / 2 << endl; // 輸出 1.5
    cout << (char)97 << endl;      // 輸出「a」, 97是字元'a'在ASCII碼中的編號
    int cnt = 0;
    while (x > 0)
    {
        cnt++;
        x = x / 10;
    }
    cout << cnt << endl;
    int y;
    cin >> y;
    if (y > 100)
    {
        cout << y << "大於100" << endl;
    }
    else
    {
        cout << y << "小於等於100" << endl;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << i << ' ';
    }
    cout << endl;
    // do{迴圈內容}while(執行條件);
    int n;
    cin >> n;
    int now = 0;
    while (true)
    {
        if (now >= n)
            break;
        cout << now++ << ' ';
    } // 結束break所屬的迴圈。
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 1)
            continue;
        cout << i << '\n';
    }
    int val = 10; // val is local here
    cout << "Value of global val is " << ::val;
    cout << "\nValue of local val is " << val;
    return 0; // 會跳過迴圈剩下的部分，直接回到判斷迴圈條件的步驟。
    system("pause");
    
}
