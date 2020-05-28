#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int main()
{
    int X;
    deque<int> poles;
    cin >> X;
    poles.push_back(64);
    if(X == 64){
        cout<<"1";
        return 0;
    }

    while (true)
    {
        int p = poles.front();
        poles.pop_front();
        poles.push_front(p / 2);
        poles.push_front(p / 2);

        int sum = 0;
        for (int n : poles){
            sum += n;
        }

        if (sum - poles.front() >= X)
        {
            sum -= poles.front();
            poles.pop_front();
        }
        if(sum == X) break;
    }
    cout << poles.size();
    return 0;
}