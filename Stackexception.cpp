#include <iostream>
#include <string>
using namespace std;


class StackEmpty {
private:
  string errMessage;
public:
  string getErrMessage() {
    return errMessage;
  }
  StackEmpty(const string & e) {
    errMessage = e;
  }
};

class StackFull {
private:
  string errMessage;
public:
  string getErrMessage() {
    return errMessage;
  }
  StackFull(const string & e) {
    errMessage = e;
  }
};

template < typename E >
class ArrayStack {
enum { DEF_CAPACITY = 100 }; // default stack capacity

public:
 ArrayStack(int cap = DEF_CAPACITY);// constructor from capacity
 int size() const;  // number of items in the stack
 bool empty() const;// is the stack empty?
 const E& top() const throw(StackEmpty); // get the top element
 void push(const E& e) throw(StackFull); // push element onto stack
 // void pop() throw(StackEmpty); // pop the stack
// ...housekeeping functions omitted
private:      // member data
  E* S;  // array of stack elements
  int capacity;  // stack capacity
  int t; // index of the top of the stack

};

template <typename E>
ArrayStack<E>::ArrayStack(int cap) {

 S = new E[cap];
 capacity = cap;
 t = -1;
}

template <typename E>
int ArrayStack<E>::size() const {
  return t+1; // return the number of items in the list and it starts from 1 not zero
}

template <typename E>
bool ArrayStack<E>::empty() const {
  if (size() == 0) {
    return true;
  } else {
    return false;
  }
}

template <typename E>
const E& ArrayStack<E>::top() const throw(StackEmpty) {
  if (empty() == true) {
    throw StackEmpty("The stack is empty");
  }
  return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e) throw(StackFull) {
  if (size() == capacity) {
    throw StackFull("The stack is full");
  }
  S[t++] = e;
  // t++;
  cout << "we have added a new element " << e << endl;
}


int main() {
  ArrayStack<int> instance;
  // cout << instance.size() << endl;
  instance.push(11);
  instance.push(12);
  instance.push(13);
  instance.push(13);
  // cout << instance.top() << endl;
  // cout << instance.size() << endl;
}
