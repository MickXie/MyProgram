#include <iostream>
using namespace std;
int main (){
    ios_base::sync_with_stdio(0);//優化
	cin.tie(0);//優化
    string sen;
    cin >> sen;
    for(char cen:sen){
    int c=cen-7;
    char resultChar = static_cast<char>(c);
    cout << resultChar ;
    }
    cout << endl;
    return 0;
}