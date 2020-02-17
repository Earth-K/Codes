#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};
int rr,rc,br,bc;
vector<string> map(10);

bool valid(int r, int c, vector<string> &cloneMap){
    if(!(0<=r && r<N && 0<=c && c<M))
        return false;
    if(cloneMap[r][c] == '#' || cloneMap[r][c] == 'R' || cloneMap[r][c] == 'B')
        return false;

    return true;
}

bool move(vector<int> &dirs, vector<string> cloneMap){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 'R')
                rr=i, rc=j;
            if(map[i][j] == 'B')
                br=i, bc=j;
        }
    }
    //cout<<rr<<' '<<rc<<' '<<br<<' '<<bc<<endl;
    bool f1, f2;
    f1 = f2 = false;
    for(int dir : dirs){
        while (true)
        {
            bool moved = false;
            while (true)
            {
                int rnR = rr + dr[dir];
                int rnC = rc + dc[dir];
                if (valid(rnR, rnC, cloneMap))
                {
                    if (cloneMap[rnR][rnC] == 'O')
                    {
                        cloneMap[rr][rc] = '.';
                        f1 = true;
                        break;
                    }
                    swap(cloneMap[rnR][rnC], cloneMap[rr][rc]);
                    rr = rnR;
                    rc = rnC;
                    moved = true;
                }
                else{
                    break;
                }
            }
            while (true)
            {
                int bnR = br + dr[dir];
                int bnC = bc + dc[dir];
                if (valid(bnR, bnC, cloneMap))
                {
                    if (cloneMap[bnR][bnC] == 'O')
                    {
                        cloneMap[br][bc] = '.';
                        f2 = true;
                        break;
                    }
                    swap(cloneMap[bnR][bnC], cloneMap[br][bc]);
                    br = bnR;
                    bc = bnC;
                    moved = true;
                }
                else{
                    break;
                }
            }
            if(moved == false)
                break;
        }
        if(f2)  return false;
        if(f1)  return true;
    }
    return false;
}

bool solve(vector<int> &dirs, vector<string> &cloneMap, int len){
    if(dirs.size()==len){
        if(move(dirs, map)){
            cout<<len<<endl;
            for(int dir: dirs){
                if(dir == 0) cout<<'L';
                else if(dir==1) cout<<'R';
                else if(dir==2) cout<<'U';
                else if(dir==3) cout<<'D';
            }
            return true;
        }
        return false;
    }

    for(int i=0; i<4; i++){
        if(!dirs.empty() && dirs.back() == i) continue;
        dirs.push_back(i);
        //cout<<i<<endl;
        if(solve(dirs, cloneMap, len))
            return true;
        dirs.pop_back();
    }
    return false;
}
int main(){
    cin>>N>>M;
    
    for(int i=0; i<N; i++)
        cin>>map[i];
    M=map[0].size();

    int answer = 0;
    for(int len=1; len<=10 ;len++){
        vector<int> dirs;
        //cout<<"len: "<<len<<endl;
        if(solve(dirs, map, len)){
            answer = len;
            break;
        }
    }
    if(answer == 0)
        cout<<"-1";
    return 0;
}