#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Task{
    int priority, number;
};
queue<Task> Q;

int main(){
    int T,N,M;
    cin >> T;
    while(T--){
        int cnt = 0;
        cin>>N>>M;
        while(!Q.empty()) Q.pop();

        int maxPriority = 0;
        for(int i=0, p; i<N ;i++){
            cin >> p;
            Q.push({p,i});
            maxPriority = max(maxPriority,p);
        }

        while (!Q.empty()) {
            bool flag = false;
            int sz = Q.size();
            for (int i = 0; i < sz; i++) {
                Task t = Q.front();
                Q.pop();
                
                if (maxPriority == t.priority){
                    cnt++;
                    if(t.number == M){
                        flag = true;
                        cout << cnt << endl;
                    }
                    else{
                        maxPriority = 0;
                        for(int i=0; i<Q.size() ; i++){
                            Task t = Q.front();
                            maxPriority = max(maxPriority, t.priority);
                            Q.pop();
                            Q.push(t);
                        }
                    }
                    break;
                }
                else {
                    Q.push(t);
                }
            }
            if(flag)break;
        }
    }
    return 0;
}