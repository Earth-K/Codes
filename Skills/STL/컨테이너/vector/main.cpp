#include<iostream>
#include<vector>
using namespace std;

vector<int> meetRequire1(const vector<int>& vt);
vector<int> meetRequire2(const vector<int>& vt);
void printVt(const vector<int>& vt);

int main(){
    int n;
    cin >> n;
    vector<int> vt(n+1, 0);
    vector<int> resVt1 = meetRequire1(vt);
    vector<int> resVt2 = meetRequire2(resVt1);
    printVt(resVt2);

    return 0;
}

vector<int> meetRequire1(const vector<int>& vt){
    vector<int> retVt(vt);
    for(int i=0; i<retVt.size(); i+=5){
        retVt[i] = 1;
    }
    int end = vt.size();
    if(retVt.back() != 1){
        int cnt = 1;
        while(retVt[end-1-cnt] != 1){
            cnt++;
        }
        for(int i=0; i<4-cnt; i++)
            retVt.push_back(0);
        retVt.push_back(1);
    }
    return retVt;
}

vector<int> meetRequire2(const vector<int>& vt){
    vector<int> retVt(vt);
    vector<int>::iterator iter = retVt.begin();
    while(iter != retVt.end()){
        if(*iter == 1)
            iter = retVt.erase(iter);
        else
            iter++;
    }
    return retVt;
}

void printVt(const vector<int>& vt){
    cout<<"[ ";
    for(int i=0; i<vt.size(); i++)
        cout<<vt[i]<<" ";
    cout<<"]"<<endl;
}