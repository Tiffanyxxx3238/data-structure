#include <bits/stdc++.h>
using namespace std;

//bubble sort
void BubbleSort(char** array,int x){
	for (int i = 0; i < x - 1; ++i) {//control count
        for (int j = 0; j < x - i - 1; ++j) { // compare near by numbers
            if (array[j][0] < array[j + 1][0]) {
                char* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
int main() {
	int x,y;
	cout<<"Please enter the number of strings (x) and the length (y):";
	cin>>x>>y;
	char** array = new char*[x];//create dynamic 2d array
	for(int i=0;i<x;++i){
		 array[i] = new char[y + 1];  //each string up to y letters, and put the terminator on the end
	}
	//get each string
	cout<<"Please enter"<<x<<" strings, each string is " <<y<<" characters:\n";
	cout << "the string is:\n";
    for (int i = 0; i < x; ++i) {
    	cout << "Enter the " <<i+1<<" ";
    	cin>>array[i];
    	//check length
    	 if (strlen(array[i]) > y) {
            cout << "over the  " << y << " will be cut off\n";
            array[i][y] = '\0';  
        }
    }
    //call function
    BubbleSort(array,x);
    //output
    cout<<"\nThe sorted string is (arranged from largest to smallest according to the first character):\n";
    for (int i = 0; i < x; ++i) {
        cout << array[i] << endl;
    }
    //release memory: new use delete
    for (int i = 0; i < x; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
	
}
