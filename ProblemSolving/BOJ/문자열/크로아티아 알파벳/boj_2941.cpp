#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    string str;
    cin >> str;
    int answer, i;
    answer = i = 0;
    while (str[i])
    {
        if (str[i] == 'c' || str[i] == 's' || str[i] == 'z') {
            if (i + 2 <= str.length()) {
                if ((str[i] == 'c' && (str[i + 1] == '-')) ||
                     str[i + 1] == '=')
                    i++;
            }
            answer++;
        }
        else if (str[i] == 'd') {
            if((i+3<=str.length()) && (str[i + 1] == 'z') && (str[i+2] == '='))
                 i+=2;
             else if((i+2<=str.length()) && (str[i + 1] == '-'))
                 i++;
             answer++;
        }
        else if(str[i] == 'l' || str[i] == 'n'){
            if((i+2<=str.length()) && (str[i+1] == 'j'))
                 i++;
             answer++;
        }
        else if('a' <= str[i] && str[i] <= 'z'){
            answer++;
        }
        i++;
    }
    cout<<answer;
    return 0;
}