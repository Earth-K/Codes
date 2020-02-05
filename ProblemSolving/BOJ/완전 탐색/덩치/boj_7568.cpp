#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Person{
    int weight,height;
};
vector<Person> vt;

int N;
int main(){
    cin>>N;
    for(int i=0,x,y; i<N; i++){
        cin>>x>>y;
        vt.push_back({x,y});
    }
    
    for(int i=0; i<vt.size(); i++){
        int cnt = 0;
        for(int j=0; j<vt.size(); j++){
            if(i==j) continue;
            if(vt[i].height < vt[j].height && vt[i].weight < vt[j].weight){
                cnt++;
            }
        }
        cout<<cnt+1<<" ";
    }
    return 0;
}