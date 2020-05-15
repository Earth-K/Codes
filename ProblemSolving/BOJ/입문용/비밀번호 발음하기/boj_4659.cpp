#include<iostream>
#include<string>
using namespace std;
bool isMoum(char ch){
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') ? true : false;
}
bool isJaum(char ch){
    return !isMoum(ch);
}
bool oneCheckFunc(const string& str){
    for(char ch : str){
        if(isMoum(ch)) 
            return true;
    }
    return false;
}
bool twoCheckFunc(const string& str){
    if(str.size()<3) return true;

    for(int i=0; i<str.size()-2 ;i++){
        if((isMoum(str[i]) && isMoum(str[i+1]) && isMoum(str[i+2])) 
        || (isJaum(str[i]) && isJaum(str[i+1]) && isJaum(str[i+2])))
            return false;
    }
    return true;
}
bool threeCheckFunc(const string& str){
    if(str.size() == 1) return true;

    for(int i=0; i<str.size()-1; i++){
        if(str[i] == str[i+1]){
            if(!(str[i] == 'e' || str[i] == 'o'))
                return false;
        }
    }
    return true;
}

int main(){
    while(true){
        string str;
        cin>>str;
        if(str.compare("end") == 0) break;
        if(oneCheckFunc(str) && twoCheckFunc(str) && threeCheckFunc(str))
            cout<<"<"<<str<<"> is acceptable."<<"\n";
        else
            cout<<"<"<<str<<"> is not acceptable."<<"\n";
    }
    return 0;
}