#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int N, answer;
vector<vector<int>> map, temp;

void move(vector<vector<int>>& temp, int dir){
    vector<vector<bool>> check(N,vector<bool>(N,false));
    if(dir == 0){ // up
        for(int c=0; c<N; c++){
            while(true){
                bool moved = false;
                for (int r = 0; r < N-1; r++){
                    if (temp[r][c] == temp[r+1][c]){
                        if(check[r][c] || check[r+1][c]) continue;
                        temp[r][c] += temp[r+1][c];
                        temp[r+1][c] = 0;
                        check[r][c] = true;
                        moved = true;
                    }
                    else if (temp[r][c] == 0 && temp[r+1][c] != 0){
                        swap(check[r][c], check[r+1][c]);
                        swap(temp[r][c], temp[r+1][c]);
                        moved = true;
                    }
                }
                if(moved == false)
                    break;
            }
        }
    }
    else if(dir == 1){ // down
        for(int c=0; c<N; c++){
            while(true){
                bool moved = false;
                for (int r = N-1; r >= 1; r--){

                    if (temp[r][c] == temp[r-1][c]){
                        if(check[r][c] || check[r-1][c]) continue;
                        temp[r][c] += temp[r-1][c];
                        temp[r-1][c] = 0;
                        check[r][c] = true;
                        moved = true;
                    }
                    else if (temp[r][c] == 0 && temp[r-1][c] != 0){
                        swap(check[r][c], check[r-1][c]);
                        swap(temp[r][c], temp[r-1][c]);
                        moved = true;
                    }
                }
                if(moved == false)
                    break;
            }
        }
    }
    else if(dir == 2){ // left
        for(int r=0; r<N; r++){
            while(true){
                bool moved = false;
                for (int c = 0; c < N-1; c++){

                    if (temp[r][c] == temp[r][c+1]){
                        if(check[r][c] || check[r][c+1]) continue;
                        temp[r][c] += temp[r][c+1];
                        temp[r][c+1] = 0;
                        check[r][c] = true;
                        moved = true;
                    }
                    else if (temp[r][c] == 0 && temp[r][c+1] != 0){
                        swap(check[r][c], check[r][c+1]);
                        swap(temp[r][c], temp[r][c+1]);
                        moved = true;
                    }
                }
                if(moved == false)
                    break;
            }
        }
    }
    else if(dir == 3){ // right
        for(int r=0; r<N; r++){
            while(true){
                bool moved = false;
                for (int c = N-1; c >= 1; c--){

                    if (temp[r][c] == temp[r][c-1]){
                        if(check[r][c] || check[r][c-1]) continue;
                        temp[r][c] += temp[r][c-1];
                        temp[r][c-1] = 0;
                        check[r][c] = true;
                        moved = true;
                    }
                    else if (temp[r][c] == 0 && temp[r][c-1] != 0){
                        swap(check[r][c], check[r][c-1]);
                        swap(temp[r][c], temp[r][c-1]);
                        moved = true;
                    }
                }
                if(moved == false)
                    break;
            }
        }
    }
}
int getMaxVal(vector<int> &arr){
    int maxVal = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            temp[i][j] = map[i][j];
        }
    }

    for(int dir: arr){
        move(temp, dir);
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            maxVal = max(maxVal, temp[i][j]);
        }
    }
    return maxVal;
}
void solve(vector<int>& arr){
    if(arr.size() == 5){
        int val = getMaxVal(arr);
        answer = max(answer,val);
        return;
    }

    for(int dir=0; dir<4; dir++){
        arr.push_back(dir);
        solve(arr);
        arr.pop_back();
    }
}
int main(){
    vector<int> dirs;
    cin>>N;
    map.resize(N);
    temp.resize(N);
    for(int i=0; i<N; i++){
        map[i].resize(N);
        temp[i].resize(N);
    }

    for(int i=0; i<N ;i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }

    solve(dirs);
    
    cout<<answer;
    return 0;
}