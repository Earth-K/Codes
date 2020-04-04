#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define pii pair<int,int>
using namespace std;
int N,M;
map<int,pii> photos;
int main(){
    cin>>N>>M;
    for(int i=0,num; i<M; i++){
        cin>>num;
        if(photos.find(num) == photos.end()){
            if(photos.size() < N){
                photos[num].first = 1;
                photos[num].second = i;
            }
            else{
                int delNum = 0;
                pii minPii = {987654321,987654321};
                for(pair<int,pii> p : photos){
                    if(minPii > p.second){
                        delNum = p.first;
                        minPii = p.second;
                    }
                }
                photos.erase(photos.find(delNum));
                photos[num].first = 1;
                photos[num].second = i;
            }
        }
        else{
            photos[num].first += 1;
        }
    }
    vector<int> vt;
    for(pair<int,pii> p : photos){
        vt.push_back(p.first);
    }
    sort(vt.begin(), vt.end());
    for(int n : vt)
        cout<<n<<" ";
    return 0;
}