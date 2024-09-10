#include <bits/stdc++.h> 
using namespace std;

void BubbleSort(char** array, int x){
	for(int i=0; i<x-1; ++i){//control count
		for(int j=0; j<x-i-1; ++j){//to compare
			if(array[j][0]<array[j+1][0]){
				char* temp = array[j];//change point
				array[j] = array[j+1];
				array[j+1]=temp;
			}
		}
	}
}

int main(){
	int x, y;
	cout<<"Please enter the number of strings (x) and the length (y):";
	cin>>x>>y;
	//use malloc
	char** array = (char**)malloc(x*sizeof(char*));
	for(int k=0; k<x; ++k){
		array[k] = (char*)malloc((y+1)*sizeof(char));//each strings has y+1 space
	}
	
	cout<<"Please enter"<<x<<" strings, each string is " <<y<<" characters:\n";
    for (int i = 0; i < x; ++i) {
    	cout << "Enter the " <<i+1<<" : ";
    	cin>>array[i];
    	//check length
    	 if (strlen(array[i]) > y) {
            cout << "String exceeds   " << y << " characters, so will be cut off\n";
            array[i][y] = '\0';  
        }
    }
    //call function
    BubbleSort(array, x);
    //output
    cout<<"\nThe sorted string is (arranged from largest to smallest according to the first character):\n";
    for (int i = 0; i < x; ++i) {
        cout << array[i] << endl;
    }
    //release memory: malloc use free
    for (int i = 0; i < x; ++i) {
        free(array[i]);
    }
    free(array);

    return 0;
	
	
}
