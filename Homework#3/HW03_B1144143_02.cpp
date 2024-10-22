#include <bits/stdc++.h>
using namespace std;

string CharDelete(const string& str, char c){//declare a function:CHarDelete,and has a str and c input, and reurn a string
//use const to avoid copy all string , and impove efficiency,c is need to delete char
	string result;//result is to store delete after answer
	for(char ch:str){//search all str in string to find all ch
		if(ch!=c){//if ch not the same as c, put it in result
			result+=ch;//put ch in result
		}
	}
	return result;//return answer
}

int main(){
	string test = "Hello, World!";//test string
	char to_delete;//to_delete is user want to delete char
	
	cout<<"Original string: "<<test<<endl;//show original test string
	cout<<"Enter character to delete: ";//tell user to put the charater they want to delete
	cin>>to_delete;
	string result = CharDelete(test, to_delete);//call CharDelete function to to the action
	cout<<"Charater to delete: "<<to_delete<<endl;//show user what they want to delete
	cout<<"Result after delete: "<<result<<endl;//show the the answer after delete
	
	return 0;
} 
