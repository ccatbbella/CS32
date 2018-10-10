# CS32
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
  
