#include <iostream>
using namespace std;

class negativeValueException{};

class evenValueException{};
int main(){
	
    int value;
    try{
      cout << "Enter a positive and odd number" << endl;
      cin >> value;
      if(value < 0)
        throw negativeValueException();
      if(value%2 == 0)//anonymous object
      	throw evenValueException();
      cout << "The number entered is" << value << endl;
    }
    catch(negativeValueException e){//catch block has input type same as the type of thing thrown
    //if number entered is positive, catch block is not executed
      cout << "The number entered is not positive" <<endl;
    }
    catch(evenValueException e){
    	cout << "The number entered is not odd" << endl;

    }

    cout << "Statement after try catch block" << endl;
  
	return 0;

}
