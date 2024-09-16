#include <bits/stdc++.h>
using namespace std;

void SelectionSort(int*a, const int n){
	//Sort the n integers a[0] to a[n-1] into nondecreasing order.
	for(int i=0; i<n; i++){
		int j=i;
		//find smallest integer in a[i] to a[n-1]
		for(int k=i+1; k<n; k++){
			if(a[k]<a[j]){
				j=k;
			}
		}
	swap(a[i],a[j]);
	}
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
	int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
} 
