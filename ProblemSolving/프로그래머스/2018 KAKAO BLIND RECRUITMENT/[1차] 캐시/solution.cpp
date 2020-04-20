#include <string>
#include <cctype>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Obj{
    int age;
    string city;
};

struct cmp{
    bool operator()(const Obj& o1, const Obj& o2){
        return o1.age<o2.age;
    }
};
priority_queue<Obj,deque<Obj>,cmp> pq;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int numCities = cities.size();
    
    if(cacheSize == 0){
        return numCities*5;
    }
    for(int i=0; i<numCities; i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    }
    
    for(int i=0; i<numCities; i++){
        bool flag = false;
        vector<Obj> vt;
        
        while(!pq.empty()){
            Obj o = pq.top();
            pq.pop();
            if(o.city.compare(cities[i]) == 0){
                o.age = 0;
                flag = true;
            }
            o.age += 1;
            vt.push_back(o);
        }
        for(int j=0; j<vt.size(); j++){
            pq.push(vt[j]);
        }
        
        if(flag){ // cache hit
            answer += 1;
        }
        else { // cache miss
            answer += 5;
            if(pq.size() == cacheSize){
                pq.pop();
            }
            pq.push({1,cities[i]});
        }
    }
    
    return answer;
}