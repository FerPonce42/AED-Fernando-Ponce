#include <iostream>
#include <list>
#include <vector>
#include <deque>

#include <stack>
#include <queue>

using namespace std; 

template <class T, class C>
struct MiStack { // deque, vector, list

	void push(T x);
	void pop();
	T top();


	C contenedor;
};


template <class T, class C>
void MiStack<T, C>::push(T x) {
	contenedor.push_back(x);
}


template <class T, class C>
void MiStack<T, C>::pop() {
	contenedor.pop_back();
}

template <class T, class C>
T MiStack<T, C>::top() {
	return contenedor.back();
}



/********************/

template <class T, class C>
struct MiQueue { // deque, vector(ineficiente), list

	void push(T x);
	void pop();
	T front();


	C contenedor;
};


template <class T, class C>
void MiQueue<T, C>::push(T x) {
	contenedor.push_back(x);
}


template <class T, class C>
void MiQueue<T, C>::pop() {
	contenedor.pop_front();
}

template <class T, class C>
T MiQueue<T, C>::front() {
	return contenedor.front();
}



int main() {

	cout << "stack STL:" << endl;

	stack <int, deque<int>> stack;

	stack.push(5);
	stack.push(7);
	stack.push(3);

	cout << stack.top() << " ";

	stack.pop();

	cout << stack.top() << " ";

	stack.pop();

	cout << stack.top() << " ";

	cout << endl;
	cout << "Mi Stack: " << endl;

	MiStack<int, list<int>> mistack;

	mistack.push(5);
	mistack.push(7);
	mistack.push(3);

	cout << mistack.top() << " ";

	mistack.pop();

	cout << mistack.top() << " ";

	mistack.pop();

	cout << mistack.top() << " ";


	cout << endl;
	cout << endl;

	cout << "Queue STL:" << endl;
	queue<int,list<int>> queue;

	queue.push(2);
	queue.push(6);
	queue.push(10);

	cout << queue.front() << " ";
	queue.pop();

	cout << queue.front() << " ";
	queue.pop();

	cout << queue.front() << " ";

	cout << endl;

	cout << "MiQueue:" << endl;
	MiQueue<int, list<int>> miqueue;

	miqueue.push(2);
	miqueue.push(6);
	miqueue.push(10);

	cout << miqueue.front() << " ";
	miqueue.pop();

	cout << miqueue.front() << " ";
	miqueue.pop();

	cout << miqueue.front() << " ";
}