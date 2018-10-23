# CS32
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
        
        
## Week 2
### Binary Search and Sorting,           10/11/2018/Thur
* size_t : a data type for integers that has cross-platform compatibility.
* Binary Search
    * on a sorted array, if unsorted, bad, o(n)
    * each iteration cut half of the array
    * scale well
* coding of recursive binary search

* Quadratic-time sorting algorithm O(n^2), O(nlogn) is considered fast
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
  
