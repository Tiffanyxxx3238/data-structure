#include <bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cout<<"Please enter the name number:";
	cin>>x;
	cin.ignore();
	
	vector<string> first_names(x);
	vector<string> last_names(x);
	string first_name,last_name;
	size_t max_first_length = 0;
	size_t max_last_length = 0;
	
	cout<<"Please enter "<<x<<" names: "<<endl;
	for(int i=0; i<x; ++i){
		cin>>first_name>>last_name;
		first_names[i] = first_name;
		last_names[i] = last_name;
		
		if(first_name.length()>max_first_length){
			max_first_length = first_name.length();
		}
		if(last_name.length()>max_last_length){
			max_last_length = last_name.length();
		}
	}
	
	char** first_array = new char*[x];
	char** last_array = new char*[x];
	for(int k=0; k<x; ++k){
		first_array[k] = new char[max_first_length+1];
		last_array[k] = new char[max_last_length+1];
		strcpy(first_array[k], first_names[k].c_str());
		strcpy(last_array[k], last_names[k].c_str());
	}
	
	cout <<"Please enter the name:"<<endl;
	for(int j = 0; j<x; ++j){
		int total_length = max_first_length + max_last_length + 1; 
        int current_length = first_names[j].length() + last_names[j].length() + 1;
        int padding = (total_length - current_length) / 2; 

        cout << setw(padding + first_names[j].length()) << right << first_array[j]
                  << " "
                  << setw(padding + last_names[j].length()) << right << last_array[j]
                  << endl;
	}
	
	for(int z=0; z<x; ++z){
		delete[] first_array[z];
		delete[] last_array[z];
	}
	delete[] first_array;
	delete[] last_array;
	
	return 0;
} 
