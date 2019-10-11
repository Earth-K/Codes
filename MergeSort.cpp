#include<iostream>
#define SZ 7
using namespace std;

int arr[SZ]={6,5,4,1,3,7,2};
int tmp[SZ];

bool comp(const int& a, const int& b) {
	return a<b;
}
void MergeSort(int arr[SZ], int s, int e) {
	if (s>=e) return;

	int mid = (s+e)>>1;
	int i=s, j=mid+1, k=s;

	MergeSort(arr, i, mid);
	MergeSort(arr, mid+1, e);

	while (i<=mid && j<=e) {
		if (comp(arr[i], arr[j]))
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}
	while (i<=mid) tmp[k++] = arr[i++];
	while (j<=e) tmp[k++] = arr[j++];
	for (int i=s; i<=e; i++)
		arr[i] = tmp[i];
}
void printArr() {
	for (int num : arr)
		cout<<num<<" ";
	cout<<'\n';
}

int main() {
	printArr();
	MergeSort(arr,0,SZ-1);
	printArr();
	return 0;
}