#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
using namespace std;
int gg(int a); 
int main() {
int a;
char b;
cin>>a;
b=gg(a);
cout<<b<<b;
return 0;
}
int gg(int a){
	char j;
	if(a==1){
	j='G'; 
	}else{
		j='8';
	}
	return j;
}
