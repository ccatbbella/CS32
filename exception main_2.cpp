#include <iostream>
using namespace std;
class divideByZeroException{};

double divide(double numerator, double denominator) throw(divideByZeroException){
	//up to the caller to write catch block about what to do with error
	if (denominator == 0)
		throw divideByZeroException(); //similar to return, like a return type
	return numerator/denominator;
}
int main(){

	try{
    	cout << divide(1,1)<<endl;
    	cout << divide(1,0)<< endl;
    	cout << divide(2,2)<<endl;  //will not get executed
    }
    catch(divideByZeroException){
    	cerr << "ERROR" <<endl;

    }

	return 0;
}
