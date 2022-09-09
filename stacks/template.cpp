#include<iostream>
using namespace std;
template<class t>
t name(t c, t d){
    return c+d;

}
int main(){
    int a = 8;
    float b = 7;
    cout<<name<char>(a,b);
    return 0;
}