#include<iostream>
#include<vector>
#include<cctype>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    vector<string> vt = {"Talk", "taLk"};
    cout<<"before: "<<vt[0]<<" "<<vt[1]<<endl;

    for(int i=0; i<vt.size(); i++){
        transform(vt[i].begin(), vt[i].end(), vt[i].begin(), ::tolower);
    }
    /*
    for (string &str : vt) {
        for(char &ch : str){
            if('A'<=ch&&ch<='Z')
                ch += 32;
        }
    }
    */
    cout<<"after: "<<vt[0]<<" "<<vt[1]<<endl;
    return 0;
}