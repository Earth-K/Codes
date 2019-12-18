#include<iostream>
#include<algorithm>
#include<string>
#define NUM_PERSONS 10
using namespace std;

struct Person{
    string name;
    int age, height, weight;
}persons[10];

bool compare(const Person& p1, const Person& p2){
    if(p1.height == p2.height){
        if(p1.weight == p2.weight){
            return p1.age < p2.age;    
        }
        else
            return p1.weight < p2.weight;
    }
    else
        return p1.height > p2.height;
}
void printArray(const Person persons[], int size){
    for(int i=0; i<NUM_PERSONS; i++){
        const Person& p = persons[i];
        cout << p.name << " " << p.age << " " << p.height << " " << p.weight << endl;
    }
    cout<<endl;
}

int main(){
    freopen("input.txt","r",stdin);
    for(int i=0; i<NUM_PERSONS ;i++){
        Person& p = persons[i];
        cin >> p.name >> p.age >> p.height >> p.weight;
    }
    printArray(persons, NUM_PERSONS);
    sort(persons, persons+NUM_PERSONS, compare);
    printArray(persons, NUM_PERSONS);

    cout<< "answer :" << persons[0].name << endl;
    return 0;
}