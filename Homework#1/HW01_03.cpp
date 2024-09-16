#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cout<<"Please enter the number of names: ";
	cin>>x;//input how many names
	cin.ignore();//skip \n
	//four array use new
	string* full_names =  new string[x];
	string* first_names =  new string[x];
	string* second_names =  new string[x];
	string* rest_names =  new string[x];
	//count the most long firstname
	size_t max_first_length = 0;
	
	cout<<"Please enter "<<x<<" names: "<<endl;
	//read every line name
	for(int i=0; i<x; ++i){
		getline(cin, full_names[i]);
		//use stringstream take name apart
		stringstream ss(full_names[i]);//read name in full_name array, and output to stringsstream ss's object 
		string first_name, second_name, rest_name;
		ss>>first_name>>second_name; //read first and second name
		getline(ss, rest_name);// if have remain, then read the remain one
		//give to corresponding array
		first_names[i] = first_name;
		second_names[i] = second_name;
		rest_names[i] = rest_name;
		//renew the most long name length(everytime read name)
		if (first_name.length() > max_first_length) {
            max_first_length = first_name.length();
        }
	}
	//print
	cout<<"\nName List:\n";
	for(int j=0; j<x; ++j){//setw is define the wight
		cout<<setw(max_first_length)<<right<<first_names[j]<<" "<<left<<second_names[j]<<rest_names[j]<<endl;//use setw, right, left to Alignment and width 
	}
	//release memory,use new way
	delete[] full_names;
    delete[] first_names;
    delete[] second_names;
    delete[] rest_names;
    
	return 0;
}
