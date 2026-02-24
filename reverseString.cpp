#include <iostream>
using namespace std;
int main(){

    string s;
    cout<<"enter the string:";
    cin>>s;

    int n=s.length();

    for(int i=n;i>=0;i--){
        cout<<s[i];

    }
    return 0;
}