#include<iostream>
#include<string>
using namespace std;
int n;
int main(){
    cin>>n;
    for(int i=1 ;i<=n; i++){
        string str;
        cin >> str;
        for(int j=0; j<str.size(); j++){
            if(str[j] == 'Z')
                str[j] = 'A';
            else
                str[j] += 1;
        }
        cout<<"String #"<<i<<"\n";
        cout<<str<<"\n\n";
    }
    return 0;
}