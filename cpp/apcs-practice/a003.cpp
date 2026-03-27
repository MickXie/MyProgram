#include <iostream>
using namespace std;
int main()
{
int M,D;
int s;
while( cin >>M>>D)
    {
        s=(M*2+D)%3;
        if(s==0){
           cout <<"普通"<< endl; 
        }else if (s==1){
           cout <<"吉"<< endl;  
        }else {
            cout <<"大吉"<< endl;
        }
        s=0;
    }
    
    return 0;
}
