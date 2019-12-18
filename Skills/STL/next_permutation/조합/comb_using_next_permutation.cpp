#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int arr[6] = { 1,2,3,4,5,6 };

	//배열
	int perm[6]={0,};
	for (int i = 0; i < 3; i++)
		perm[5 - i] = 1;
	do {
		for (int i = 0; i < 6; i++) {
			if (perm[i] == 1)
				cout << arr[i] << " ";
		}
		cout << endl;
	} while (next_permutation(perm, &perm[6]));
	cout<<endl;


	//벡터
	vector<int> vt(3, 0);
	for (int i = 0; i<3; i++)
		vt.push_back(1);
	do {
		for (int i = 0; i < 6; i++) {
			if (vt[i] == 1)
				cout << arr[i] << " ";
		}
		cout << endl;
	} while (next_permutation(vt.begin(), vt.end()));
	cout<<endl;

	return 0;
}