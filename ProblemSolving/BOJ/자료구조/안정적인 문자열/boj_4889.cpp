#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    
    int t=1;
    string str;
    while (true)
    {
        int answer,st;
        answer = st = 0;
        cin >> str;
        if(str.find("-") != string::npos)
            break;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '{')
            {
                 st += 1;
            }
            else if(str[i] == '}')
            {
                if (st == 0)
                {
                    st += 1;
                    answer += 1;
                }
                else
                {
                    st -= 1;
                }
            }
        }
        if (st != 0)
        {
            answer += st/2;
        }
        cout << t++ <<". "<<answer << "\n";
    }
    return 0;
}