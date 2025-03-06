#include <iostream>
using namespace std;
bool isa(int a , int b , int c ,int d){
    return((b-a == c-b) && (c-b == d-c));
}
bool isg(int a, int b , int c ,int d){
    return((b/a == c/b) && (c/b == d/c));
}
int main(){
    int t;
    cin >> t;
    while (t--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(isa(a,b,c,d)){
            int di=b-a;
            int e=d+di;
            cout << a <<" "<< b <<" "<< c <<" "<< d <<" "<< e <<endl;
        }else if(isg(a,b,c,d)){
            int ra=b/a;
            int e=d*ra;
            cout << a <<" "<< b <<" "<< c <<" "<< d <<" "<< e <<endl;
        }}
    return 0;
}
