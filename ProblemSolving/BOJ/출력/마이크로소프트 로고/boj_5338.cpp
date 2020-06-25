#include<iostream>
#include<string>
using namespace std;
int main(){
    string str[5];
    str[0] = "       _.-;;-._";
    str[1] = "'-..-'|   ||   |";
    str[2] = "'-..-'|_.-;;-._|";
    str[3] = "'-..-'|   ||   |";
    str[4] = "'-..-'|_.-''-._|";
    for(int i=0; i<5; i++)
        cout<<str[i]<<"\n";
    return 0;
}