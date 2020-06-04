#include<iostream>
#include<string>
using namespace std;
int dr[8]={0,0,1,-1,-1,-1,1,1};
int dc[8]={1,-1,0,0,1,-1,1,-1};
int kr,kc,rr,rc,N;
bool chk(int r, int c){
    return 1<=r && r<=8 && 1<=c && c<=8;
}
int main(){
    string pos1,pos2,cmd;
    cin>>pos1>>pos2>>N;
    kr = 8-(pos1[1]-'1');
    kc = pos1[0]-'A'+1;
    rr = 8-(pos2[1]-'1');
    rc = pos2[0]-'A'+1;
    for(int i=0; i<N; i++){
        cin>>cmd;
        int d;
        if(cmd.compare("R") == 0){
            d = 0;
        } else if(cmd.compare("L") == 0){
            d = 1;
        } else if(cmd.compare("B") == 0){
            d = 2;
        } else if(cmd.compare("T") == 0){
            d = 3;
        } else if(cmd.compare("RT") == 0){
            d = 4;
        } else if(cmd.compare("LT") == 0){
            d = 5;
        } else if(cmd.compare("RB") == 0){
            d = 6;
        } else if(cmd.compare("LB") == 0){
            d = 7;
        }
        if(chk(kr+dr[d],kc+dc[d])){
           if(kr+dr[d] == rr && kc+dc[d] == rc){
               if(chk(rr+dr[d],rc+dc[d])){
                   kr += dr[d];
                   kc += dc[d];
                   rr += dr[d];
                   rc += dc[d];
               }
           }
           else{
               kr += dr[d];
               kc += dc[d];
           }
        }
    }
    char ch = kc+'A'-1;
    cout<<ch<<9-kr<<endl;
    ch = rc+'A'-1;
    cout<<ch<<9-rr<<endl;
    return 0;
}