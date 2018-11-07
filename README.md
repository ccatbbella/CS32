# CS32
## Week 6 
### Exception handling                     11/6/2018/Tue
* Exception handler: code that deals with/catch an exception (inside the catch block)
* Basic model for exceptions:
    * When an error condition occurs, an exception thrown
    * The code that deals with the error condition is said to catch the exception
* logic flow: [code](https://github.com/ccatbbella/CS32/blob/master/exception%20main.cpp)
   * code within the try block are executes, if nothing thrown, code inside the catch block will not be executed.
   * If an exception is thrown, corresponding catch code block with the right input data type will be executed. After the catch code done executing, the code within the try block after the line of throwing will not be executed. Instead, execution begins outside the try catch block.
* Catch statements are looked from top to bottom, the one with the right input type will be executed
* If something is thrown but no corresponding catches for the data type, code crashes.
* Only one object is thrown at a time
* Why is it bad to wrap your main function into a try block? You can only catch one error one type. Main can't recover because the layers are too complicated. Catch should be close to the throw.
* Why not use if else statement? flexibility and readibility. catch block are expensize while try block is cheap. If some error tends to happen very often, use if else instead of catch.
* How does vector class throw exception to consumer of the class? [code]()
* 




## Week 5
### Polymorphism and Inheritance         11/01/2018/Thur
* Inheritance (:)
    * Public inheritance: public member of base class become public member of children class, protected member of base class become protected member of children class
    * Protected interitance: public and protected member of the base/parent class become protected member of the children class
    * Private inheritance: public and protected member of the base class become private member of the children class
    * How does it look in memory !!! keep in mind when code
        * person p2 = s1 is legal, student s2 = person p1 is not legal
        * Putting bigger object into smaller object is ok. All fields are filled. Reversely, some fields can not be filled, and that's not ok.
        * object slicing: result of person p2 = s1, the studentID part get sliced away
        * person* p1 = new person("a",10);
        * student* s2 = p1; non-legal
        * person* p2 = s1; legal
        * can't do p2->getStudentID() because of visibility of method, not object slicing
        * does object slicing happen on heap? No!!!
    * destructor
        * delete a student will call both student and person destructor
        * Look for to_string method in the children before the parent
        * cannot instantiate abstract class, can have pointer to it
* Polymorphism
    * manuel in C++
    * virtual keyword
    * called the method for constructed objects not its actual data type
    * Can constructor be virtual? No
    * Can destructor be virtual? yes
    
         
* Talking about Lab
    * for helper function, define and declare it in cpp file
### Testing                              10/30/2018/Tue
* Testing
    * Complete test infeasible
    * test normal (expected input), edge/boundry (edge value of possible input), and error cases (invalid input, mostly wrong data type. C++ catch it in compile time, but for Python, need to rigoriously check input data type!)
    * unit testing: structural your program into different units. Units build on top of each other. When testing, first test the the smaller unit work, then test larger unit until the whole program tested.
    * Test suite: a pool of tests for automating testing, especially for large scale projects. (eg. lab assignment submission testing)

## Week 4
### Merge Sort and Quick Sort           10/25/2018/Thur
* Run in O(nlogn) in the worst case
* Merge Sort
    * Idea: 
        * break an array into half each time until you have subarray of size = 1
        * Merge two subarrays into one sorted array
        * Do this from bottom to top, merge is called after mergesort is called on the left and right subarray
    * Notable details:
        * work on the left side first, after the merging for left side is done, split right side
        * merge: repeatly look at the front value of two arrays and put the smallest into the sorted array. If one list is empty, cost the remaining of the other list into the sorted array
    * Run time Analysis:
        * O(nlogn) for best, average, and worst case
        * Require O(n) extra space for the sorted array
    * [code](https://github.com/ccatbbella/CS32/blob/master/mergeSort.cpp)
    
## Week 3 
### Hash Tables (unordered_map) and Red-Black Tree (map)       10/16/2018/Tue
* Hashing : when key values are large, hash them to a smaller index
* Hash Function
    * Input: a unique key 
    * Output: an index of an array
    * A good hash function will evenly distribute inputs
* Hash Tables  
    * Underlying structure is : vector
    * Provides efficient *search * method : O(1), also true for insert and delete, o(n) in bad case
    * Collision: when 2 inputs are mapped to same index 
    * The template data structure that uses hash table is : unordered_map
* Three ways to solve the collision problems  
    * Open Address Hashing : 
        * Linear Probing : when collision happened at i, visit i + 1, i+2 until an open spot
        * Two problems of this method 
            * delayed insertion : takes time to find empty spot. Take time when searching because keys not at computed index.
            * cluster
    * Double Hashing :
        * Used a second hash function to compute step when collision happened, reduce cluster
        * Require table size to be a *prime* number
        * Problems of this method
            * might go out of bound
            * might not uniformly distributed
    * Chain Hashing (Stdlib implementation) :  
        * a linked list is stored at each index
        * Eliminate need for resizing table  
* Red-Black Tree : perfectly balanced binary tree at all times, o(logn) for search, insert, and delete

* Coding
    * To use STL unordered map : unordered_map<int,string> students;
    * To put items into my unordered_map
        * students[4528133] = "Bella"; this way can overwrite existing data
        * students.insert(pair<int,string>(4528133,"Bella")); In this way, the pair template has member variable first and second
    * To search for an item in unordered_map
        * students.find(4528133) returns an iterator if found, unordered_map::end if not found, take in key as parameter
        * if (students.find(4528133) != students.end()) { }
    * To delete an item in unordered_map
        * By key : students.erase(4528133);
        * By iterator : unordered_map<int,string>::iterator p = students.find(4528133); students.erase(p);
    * To iterator through the unordered_map and print elements
        * for(unordered_map<int,string>::iterator p = students.begin(); p != students.end(); p++){cout<< i->first << i->second;
* Side note: a quick way to compute the mod of a sequence
of numbers is to use Python's lambda function and map feature
    * map(lambda x:x%10, perms) [3, 4, 5, 2, 5, 5]
    * map(lambda x:x%9, perms)  [3, 5, 6, 2, 2, 8]
        
## Week 2
### Binary Search and Sorting,           10/11/2018/Thur
* size_t : a data type for integers that has cross-platform compatibility.
* Binary Search
    * on a sorted array, if unsorted, bad, o(n)
    * each iteration cut half of the array
    * scale well
* coding of recursive binary search

* Quadratic-time sorting algorithm O(n^2), O(nlogn) is considered fast
    * [handout](http://cs.ucsb.edu/~richert/cs32/misc/h07-handout.pdf)
    * Bubble sort 
        * starting from beginning, compare every adjacent pair and swap if necessary. After each iteration, one element must be at the right place
        * Optimization: one whole pass with no swapping make it stop
        * Code: void bubbleSort(int arr[], size_t size){  //increasing order  
                       int temp;  
                       bool swapped;  
                       for(int i = size-1; i>0; i--){  
                       swapped = false
                         for(int j = 0; j<i; j++){  
                           if(arr[j+1] < arr[j]){  
                             temp = a[j];
                             a[j] = a[j+1];
                             a[j+1] = temp;
                             swapped = true
                           }
                         }
                         if(!swapped)  
                           return;  
                       }
    * Insertion sort
        * Initially, the first element is the only one in the sorted array. Iterate through each elements in the unsorted array, find its place in the sorted array, shift elements as necessary to create an open slot, insert the element. Done when all elements in the unsorted array is visited.
        * O(n) for mostly sorted array
        * Coding: void insertionSort(int arr[], size_t size){  //sort to increasing order  
                    int itemToBeInserted;  
                    int shiftIndex; //index of item compared with itemToBeInserted and shift right if necessary  
                    for(int i = 1; i<size; i++){  
                    itemToBeInserted = arr[i];
                      shiftIndex = i - 1;
                      while(shiftIndex>=0 && arr[shiftIndex]>itemToBeInserted){  //shift elements as necessary to create an open slot  
                        arr[shiftIndex+1] = arr[shiftIndex];  
                        shiftIndex--;
                      }  
                      arr[shiftIndex+1] = itemToBeInserted;  
                    }
                      
                     
    * Selection sort  
        * Find the largest/smallest element in the unsorted array, swap it with a[i] 
        * Coding: void selectionSort(int arr[], size_t size){  
                    int temp;  
                    int largest;  
                    int largestIndex;  
                    for(i = size-1;i>o;i--){  
                      largestIndex = 0;  
                      largest = arr[largestIndex];  
                      for(j = 1; j<i;j++){  
                        if(arr[j] > largest){  
                          largestIndex = j;  
                          largest = a[j];  
                        }  
                        temp = a[i];  
                        a[i] = largest;  
                        a[largestIndex] = temp;  
                      }  
                    }
                        
                        
                         


### Struct, Namespace, 10/09/2018


## Week 1
### Class Design, 10/04/2018
* What is a class?
  * An abstract data type whose variable is an object
  * Allows programmers to define their own data type
* 2 components of class:
  * Interface
  * Implementation
<details>
  <summary> Note 1</summary>
  <p> For .h file, NO "using namespace std" because the consumer of your class might not want to use std.</p>
</details>

* "this" keyword
  * this is a pointer that points to the object invoking a member function
  * It is used in constructor, assignment operator if the member variable name is the same as the parameter to distinguish

* "private" keyword
  * Make thing only usable for member function implementation
* Abstract Data Type(ADT)/Encapsulation
  * A special way of presenting that hides implementation details to its users
 * Scope resolution operator :: is used in *.cpp*     file
* Constructor
  * syntax feature:
    * No return type
    * same name as class
* 2 syntax for using copy constructor
  * Person t = s;
  * Person t(s);
* 2 situations where a destructor is invoked
  * When an object is created inside a function implementation, destructor is called when the function ends executing
  * When _delete_ keyword is used on pointer, the object it points to is deleted
### STL vector, 10/02/2018/Tue
* #include<vector>
    * Vectors are dynamically-resizable
    * Vectors have a size associated with it. *Arrays do not know their size and the programmer must be aware of it.
    * Access Element:Unlike [ ], if .at() references an element that the vector doesn’t contain, an exception is thrown
    * Remove element:
        * v2.erase(v2.begin() + 2); // Removing 2nd index of the vector  
        * v2.erase(v2.begin() + 1, v2.begin() + 3);  // Removing 1st and 2nd index - (1,3)
    * Supported methods
        * front() – returns the first element
        * back() – returns the last element
        * pop_back() – delete the last element 
        * push_back() - insert  
    * vector<int> v1(100); // initializes vector with 100 elements.
    * vector<int> v2(100, 1); //initializes vector with 100 elements = 1
    * iterators
        * begin() – returns an iterator that points to the first element
        * end() – returns an iterator that points to one element passed the last element
  
### Basic, 09/27/2018/Thur
* c++ build process
    * Pre-processor: for all #include, copy the appriate code into the cpp file
    * Compiler: translate source code to object code (which is a lower level representation good for executing instructions on specific platform)
    * Linker: link different object codes correctly to produce an executable
* Makefile
    * target: dependencies  
               commands
    * To declare variables: DEPENDENCIES = sth.o
    * To clean: /bin/rm -f *.o ${DEPENDENCIES}
    * To make main: main: ${DEPENDENCIES}  
                  ${CXX} $^ -o $@
    * Having .o file so that
