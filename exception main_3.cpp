#include <iostream>
using namespace std;
class A{};
class B : public A{};
class C{};
int main(){
	int value;
	try{
		cout << "Enter a positive and odd number:";
		cin >> value;

		if(value < 0)
			throw B();

	}
	catch(C){}
	catch(A){cout << "Inside catch A";}//B is considered a type of A, this will catch the throw
	catch(B){//this block can never be executed
     cout << "Inside catch B";
	}
	return 0;
}//always go from top to bottom
