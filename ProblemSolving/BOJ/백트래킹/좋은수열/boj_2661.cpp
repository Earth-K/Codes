#include<iostream>
using namespace std;

string str;
bool endFlag;

bool isGood(string &str){
    for(int len=1; len<=str.size()/2; len++){
        int left = 0;
        while(left<str.size()){
            int right = left + len;
            bool good = false;
            for(int i=0; i<len; i++){
                if(str[left+i] != str[right+i]){
                    good = true;
                    break;
                }
            }
            if(good == false)
                return false;
            left += 1;
        }
    }
    return true;
}
void perm(int len, string &str){
    if(endFlag)
        return;

    if(str.size() == len){
        cout<<str<<endl;
        endFlag = true;
        return;
    }

    for(int i=1; i<=3; i++){
        str.push_back(i+'0');
        if(isGood(str))
            perm(len, str);
        str.pop_back();
    }
}

int main(){
    int N;
    cin>>N;
    perm(N,str);
    return 0;
}