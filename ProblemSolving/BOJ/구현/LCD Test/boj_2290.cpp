#include<iostream>
#include<string>
using namespace std;

int s;
string n;
char map[23][131];
void printV(int r, int c){
    for(int i=r; i<r+s; i++)
        map[i][c] = '|';
}   
void printH(int r, int c){
    for(int i=c; i<c+s; i++)
        map[r][i] = '-';
}

void printOne(int col){
    printV(1,col+s+1);
    printV(2+s,col+s+1);
}
void printTwo(int col){
    printV(1,col+1+s);
    printV(2+s,col);
    printH(0,col+1);
    printH(s+1,col+1);
    printH(s+1+s+1,col+1);
}
void printThree(int col){
    printOne(col);
    printH(0,col+1);
    printH(s+1,col+1);
    printH(s+1+s+1,col+1);
}
void printFour(int col){
    printOne(col);
    printV(1,col);
    printH(s+1,col+1);
}
void printFive(int col){
    printV(1,col);
    printV(2+s,col+1+s);
    printH(0,col+1);
    printH(s+1,col+1);
    printH(s+1+s+1,col+1);
}
void printSix(int col){
    printFive(col);
    printV(2+s,col);
}
void printSeven(int col){
    printOne(col);
    printH(0,col+1);
}
void printEight(int col){
    printThree(col);
    printSix(col);
}
void printNine(int col){
    printThree(col);
    printFour(col);
}
void printZero(int col){
    printSeven(col);
    printH(s+1+s+1,col+1);
    printV(2+s,col);
    printV(1,col);
}
void printNumber(char ch, int col){
    switch(ch){
        case '1':
            printOne(col);
            break;
        case '2':
            printTwo(col);
            break;
        case '3':
            printThree(col);
            break;
        case '4':
            printFour(col);
            break;
        case '5':
            printFive(col);
            break;
        case '6':
            printSix(col);
            break;
        case '7':
            printSeven(col);
            break;
        case '8':
            printEight(col);
            break;
        case '9':
            printNine(col);
            break;
        case '0':
            printZero(col);
            break;
    }
}
int main(){
    cin>>s>>n;
    for(int r=0; r<2*s+3; r++){
        for(int c=0; c<(s+3)*n.size(); c++){
            map[r][c] = ' ';
        }
    }
    int col = 0;
    for(int i=0; n[i]; i++){
        printNumber(n[i],col);    
        col += s+3;
    }
    for(int r=0; r<2*s+3; r++){
        map[r][(s+3)*n.size()]='\0';
    }
    for(int i=0;i<2*s+3;i++){
        cout<<map[i]<<"\n";
    }
        
    return 0;
}