#include<iostream>
#include<deque>
using namespace std;

deque<int> meetRequire1(const deque<int>& dq);
deque<int> leftRotation(const deque<int>& dq, int num);
deque<int> rightRotation(const deque<int>& dq, int num);
void printDq(const deque<int>& dq);

int main(){
    int n;
    cin >> n;
    deque<int> dq(n, 0);
    deque<int> resDq1 = meetRequire1(dq);
    deque<int> resDq2 = leftRotation(resDq1, 5);
    printDq(resDq2);
    deque<int> resDq3 = rightRotation(resDq1, 2);
    printDq(resDq3);

    return 0;
}

deque<int> meetRequire1(const deque<int>& dq){
    deque<int> retDq(dq);
    int end = retDq.size();
    for(int i=0; i<end; i+=5){
        retDq[i] = 1;
    }
    if(retDq.back() != 1){
        int cnt = 1;
        while(retDq[end-1-cnt] != 1){
            cnt++;
        }
        for(int i=0; i<4-cnt; i++)
            retDq.push_back(0);
        retDq.push_back(1);
    }
    return retDq;
}

deque<int> leftRotation(const deque<int>& dq, int num){
    deque<int> resDq(dq);

    for(int i=0; i<num ;i++){
        int e = resDq.front();
        resDq.pop_front();
        resDq.push_back(e);
    }

    return resDq;
}

deque<int> rightRotation(const deque<int>& dq, int num){
    deque<int> resDq(dq);

    for(int i=0; i<num ;i++){
        int e = resDq.back();
        resDq.pop_back();
        resDq.push_front(e);
    }

    return resDq;
}

void printDq(const deque<int>& dq){
    cout<<"[ ";
    for(int i=0; i<dq.size(); i++)
        cout<<dq[i]<<" ";
    cout<<"]"<<endl;
}