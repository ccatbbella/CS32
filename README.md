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
    * Provides efficient *search * method : O(1)
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
* Red-Black Tree : perfectly balanced binary tree at all times
|          | Hash Table |red-black tree|
| ---------|:----------:|:------------:|
| search   |O(1)avg/o(n)bad| o(logn)   |
|delete/insert|O(1)avg/o(n)bad|o(logn) |

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
  
