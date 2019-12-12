#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Truck {
	int weight, arrivedTime;
};
queue<Truck> commingTrucksQ;
int numArrivedTrucks;

int solution(int bridge_length, int maxWeight, vector<int> truck_weights) {
    int time = 0, begin = 0, sumWeights = 0;
    int numTrucks = truck_weights.size();
    
    while(numArrivedTrucks != numTrucks){
        time++;
        
        Truck t = commingTrucksQ.front();
        if(time == t.arrivedTime){
            sumWeights -= t.weight;
            commingTrucksQ.pop();
            numArrivedTrucks++;
        }
        
        int w = truck_weights[begin];
        if(sumWeights + w <= maxWeight){
            sumWeights += w;
            commingTrucksQ.push({w, time+bridge_length});
            begin++;
        }
    }
	return time;
}