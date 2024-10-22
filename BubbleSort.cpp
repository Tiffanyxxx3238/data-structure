#include <iostream>
using namespace std;

int main() {
    int A[] = {-3, 6, 5, -1, 0, 9, 3};
    int n = sizeof(A) / sizeof(int);//count A has how many number,
    
    // Bubble sort algorithm
    for(int i = n-1; i > 0; i--) {//out for from the last element start until the first one, control everytime you need to chack range
        for(int j = 0; j <= i-1; j++) {//because everytime finish the right side is already order done, so you need to sub them not order them again.
            if(A[j] > A[j+1]) {
                int tmp = A[j];//or can use swap(A[j],A[j+1]);
                A[j] = A[j+1];
                A[j+1] = tmp;
            }
        }
    }
    
    // Print sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}
