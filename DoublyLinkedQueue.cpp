#include <iostream>
#include <stdexcept>

using namespace std;

class Node {
	public:
		Node(int data);
		~Node();
		Node* next;
		Node* prev;
		int data;
};

Node::Node(int data) {
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

Node::~Node() {
	delete next;
}

class Queue {
	private:
		Node* head;
		Node* tail;
	public:
		Queue();
		~Queue();
		void enqueue(int data);
		int dequeue();
		void print();
};

Queue::Queue() {
	head = nullptr;
	tail = nullptr;
}

Queue::~Queue() {
	delete tail;
}

void Queue::enqueue(int data) {
	Node* node = new Node(data);

	if (head == nullptr && tail == nullptr) {
		head = node;
		tail = node;
	} else {
		node->next = tail;
		tail->prev = node;
		tail = node;
	}
}

int Queue::dequeue() {
	if (head == nullptr) throw runtime_error("Empty list");

	int tmp = head->data;

	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	} else {
		head = head->prev;
		delete head->next;
		head->next = nullptr;
	}

	return tmp;
}

void Queue::print() {
	for (Node* tmp = tail; tmp != nullptr; tmp = tmp->next)
		cout << tmp->data << " ";
	cout << endl;
}

int main() {
	Queue queue;
	queue.enqueue(1);
	queue.print();
	queue.enqueue(2);
	queue.print();
	queue.enqueue(3);
	queue.print();
	queue.enqueue(4);
	queue.print();
	queue.enqueue(5);
	queue.print();

	queue.dequeue();
	queue.print();
	queue.dequeue();
	queue.print();
	queue.dequeue();
	queue.print();
	queue.dequeue();
	queue.print();
	queue.dequeue();
	queue.print();
	queue.dequeue();
	queue.print();
	
	return 0;
}
