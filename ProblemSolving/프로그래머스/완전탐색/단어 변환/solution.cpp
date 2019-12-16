#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool usedWord[50];
int findWord(string nowWord, const string& targetWord, const vector<string>& words, int cnt);

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    answer = findWord(begin, target, words, 0);
    return (answer == 987654321) ? 0 : answer;
}

int findWord(string nowWord, const string& targetWord, const vector<string>& words, int cnt){
    int answer = 987654321;
    if(nowWord.compare(targetWord) == 0){
        return cnt;
    }
    
    for(int i=0; i<nowWord.length(); i++){
        if(nowWord[i] == targetWord[i]) 
            continue;
        
        string nextWord(nowWord);
        for(int j=0; j<26 ;j++){
            nextWord[i]='a'+j;
            for(int k=0; k<words.size(); k++){
                if(usedWord[k] == false && words[k].compare(nextWord) == 0){
                    usedWord[k] = true;
                    int ret = findWord(nextWord, targetWord, words, cnt+1);
                    answer = min(answer,ret);
                    usedWord[k] = false;
                }
            }
        }
    }
    return answer;
}

int main(){
    vector<string> ex1_words = {"hot","dot","dog","log","log","cog"};
    cout<<solution("hit","cog",ex1_words)<<endl;
    vector<string> ex2_words = {"hot, dot, dog, lot, log"};
    cout<<solution("hit","cog",ex2_words)<<endl;
    return 0;
}