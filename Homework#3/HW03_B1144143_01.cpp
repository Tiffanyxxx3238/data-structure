//Write a function String:: Frequency the determines the frequency of occurrence of each of the distinct characters in the string. Test your function using suitable data

#include <bits/stdc++.h>
using namespace std;
//declares a function:Frequency
void Frequency(const string& str){
	int frequency[256]={0};//ASCII has 256 charaters , and give them all 0
	
	for(char c:str){//match the charater, and if match +1
		frequency[c]++;	
	} 
	
	for(int i=0; i<256; i++){//find all 256 characters where is more then 0, and show it 
		if(frequency[i]>0){
			cout<<"'"<<char(i)<<"':"<<frequency[i]<<endl;
		}
	}
}
/test string
int main(){
	cout<<"Frequency for 'Hello, World!':"<<endl;/
	Frequency("Hello, World!")//call Frequency function and give it test string
	
	return 0;
} 
