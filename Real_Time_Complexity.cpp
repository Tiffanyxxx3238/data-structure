#include "stdafx.h"
#include <iostream>
#include "time.h"
using namespace stdd;

int tmain(int argc,_TCHAR*argv[]){
	clock_t start_time = 0;
	float total _time = 0;
	start_time = clock();
	double x = 0;
	for(double i=0;i<1000000000;i++){
		x=x+1;
	}
	end_time=clock();
	total_time = (float)(end_time-start_time)/CLOCKS_PER_SEC;
	cout<<"start clock tick= "<<strat_time<<endl;
	cout<<"end clock tick= "<<end_time<<endl;
	cout<<"total time="<<total_time<<"second"<<endl;
	system("pause");
	return 0;
	
	
} 
