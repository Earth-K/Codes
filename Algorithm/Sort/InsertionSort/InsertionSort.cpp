#define NUM_STUDENTS 10
#include<iostream>
using namespace std;

struct Student{
    int stNum, age, height;
}students[NUM_STUDENTS];

void swap(Student* &s1, Student* &s2){
    Student* tmp = s1;
    s1 = s2;
    s2 = tmp;
}
bool comp(const Student* s1, const Student* s2){
    if(s1->age == s2->age)
        return s2->height > s1->height;
    else
        return s2->age > s1->age;
}
void insert(Student* arr[], int insertedPos, Student* student){
    arr[insertedPos] = student;
    for(int i = insertedPos ; i>0 && comp(arr[i-1], arr[i]); i--){
        swap(arr[i-1], arr[i]);
    }
}
void setStudentInfo(Student* student, int stNum, int age, int height){
    student->stNum = stNum;
    student->age = age;
    student->height = height;
}

int main(){
    Student* arr[NUM_STUDENTS];
    int n_arr = 0;

    freopen("input.txt","r",stdin);

    cout<<"\nbefore sorting"<<endl;
    for(int i=0 ;i<NUM_STUDENTS; i++){
        int stNum, age, height;
        cin >> stNum >> age >> height;
        cout << stNum << " " << age << " " << height << endl;

        setStudentInfo(&students[i], stNum, age, height);
        insert(arr, n_arr++, &students[i]);
    }

    cout<<"\nafter sorting"<<endl;
    for(int i=0 ;i<NUM_STUDENTS; i++){
        cout<<arr[i]->stNum<<" "<<arr[i]->age<<" "<<arr[i]->height<<endl;
    }
    return 0;
}