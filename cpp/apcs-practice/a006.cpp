#include <iostream>
#include <cmath>
using namespace std;
int answerRoot(int a, int b, int c) {
    int discriminant = b * b - 4 * a * c;
    if (discriminant == 0) {
        return 1;  // One real root
    } else if (discriminant > 0) {
        return 2;  // Two real roots
    } else {
        return 0;  // No real roots (complex roots)
    } 
}

int main(){
    int a,b,c;
    while(cin >> a >> b >> c ){
    int answer=answerRoot(a,b,c);
    int discriminant = b * b - 4 * a * c;
    if (answer==2) {
        cout <<"Two different roots ";
        int x1 =(-b + sqrt(discriminant)) / (2.0 * a);
        int x2 =(-b - sqrt(discriminant)) / (2.0 * a);
        cout << "x1=" <<x1<< " , " << "x2="<<x2<<endl;
    }else if (answer==1) {
        cout <<"Two same roots ";
        int x =(-b + sqrt(discriminant)) / (2.0 * a);
        cout << "x=" <<x<<endl;
    }else {
        cout <<"No real root ";
    }
}
    return 0;
}