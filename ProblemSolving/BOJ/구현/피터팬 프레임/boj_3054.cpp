#include<iostream>
#include<string>
using namespace std;
string str;
char answer[5][70];
void printChar(int c, char ch, char frame[5][6]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(i==2 && j==2)
                answer[i][c+j] = ch;
            else{
                if(answer[i][c+j] != '*')
                    answer[i][c+j] = frame[i][j];
            }
        }
        answer[i][c+5] = '\0';
    }
}
char Wframe[5][6]={"..*..",
                   ".*.*.",
                   "*...*",
                   ".*.*.",
                   "..*.."};
char Pframe[5][6]={"..#..",
                   ".#.#.",
                   "#...#",
                   ".#.#.",
                   "..#.."};
int main(){
    int cnt;
    
    cin>>str;
    cnt = 0;
    for(int i=0; i<str.size(); i++){
        cnt += 1;
        if(cnt % 3 == 0)
            printChar(i*4,str[i],Wframe);
        else
            printChar(i*4,str[i],Pframe);
    }
    for(int i=0; i<5; i++){
        cout<<answer[i]<<"\n";
    }
    return 0;
}