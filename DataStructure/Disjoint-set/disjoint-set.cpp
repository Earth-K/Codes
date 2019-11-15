#include<iostream>
#define NODE_NUM 5
using namespace std;

int parent[NODE_NUM];

void init(){
	for (int i = 0; i < NODE_NUM; i++)
		parent[i] = i;
}

int Find(int n) {
	return (parent[n] == n) ? n : parent[n] = Find(parent[n]);
}

void Union(int a, int b) {
	int i = Find(a);
	int j = Find(b);

	if (i == j)
		return;

	parent[i] = j;
}

bool isInSameSet(int a, int b) {
	if (Find(a) == Find(b))
		return true;
	else
		return false;
}

int main() {
	init();

	Union(0, 1);
	Union(1, 2);
	Union(3, 4);

	if (isInSameSet(1,4))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

	return 0;
}