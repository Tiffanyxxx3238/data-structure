#include <bits/stdc++.h>
using namespace std;

void Magic(const int n){
	const int MaxSize=51;
	int square [MaxSize][MaxSize],k,l;
	if(n>MaxSize||(n<1)){
		throw "Error!...n out of range";
	}
	else if(!(n%2))throw "Error!...n is even\n";
	
	for(int i=0;i<n;i++)
		fill(square[i]+n,0);
	square[0][(n-1)/2]=1;
	int key=2; i=0; int j=(n-1)/2;
	while(key<=n*n){
		if(i-1<0) k=n-1; else k=i-1;
		if(j-1<0)l=n-1; else l=j-1;
		if(square[k][l])i=(i+1)%n;
		else{
			i=k;
			j=l;
		}
		square[i][l]=key;
		key++;
	}
	cout<<"magic square of size "<<n<<endl;
	for(i=0;i<n;i++){
		for(j=0; j<n;j++)
			copy(square[i],square[i]+n,ostream_iterator<int>(count," "));
			cout<<endl;	
		}
	}
	
}
