#include <iostream>
#include <string>
using namespace std;

void modification(std::string &name){
    cout<<name<<endl;
    name[0] = '\0';
    cout<<name<<endl;
}

int main(){
    std::string sentence = "hello, world";
    std::string t = sentence;
    // std::string a = *sentence;
    cout<<t<<endl;
    modification(sentence);
    cout<<sentence<<endl;
    cout<<t<<endl;
    return 0;
}

// Student s[10];