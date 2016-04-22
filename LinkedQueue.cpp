#include <iostream>
#include <stdexcept>

class Node {
	public:
		Node(int data): mData(data), mNext(nullptr){};
		virtual ~Node() 						{ delete mNext; };
		int 		getData()						{ return mData; };
		void 		setData(int data)		{ mData = data; };
		Node*		getNext()						{ return mNext; };
		void 		setNext(Node* next)	{ mNext = next; };
	private:
		int 	mData;
		Node* mNext;
};

class Queue {
	public:
		Queue();
		virtual ~Queue();
		void 		enqueue(int data);
		int 		dequeue() throw (std::runtime_error);
		void 		print();
	private:
		Node* mEnd;
		Node* mBegin;
};

Queue::Queue() {
	mEnd = nullptr;
	mBegin = nullptr;
}

Queue::~Queue() {
	delete mBegin;
}

void Queue::enqueue(int data) {
	Node* node = new Node(data);
	if (mBegin == nullptr) {
		mBegin = mEnd = node;
	} else {
		mEnd->setNext(node);
		mEnd = node;
	}
}

int Queue::dequeue() throw(std::runtime_error) {
	if (mBegin == nullptr) throw std::runtime_error("Empty list");

	int data 	= mBegin->getData();
	Node* tmp	= mBegin->getNext();
	mBegin->setNext(nullptr);
	delete mBegin;
	mBegin = tmp;

	if (mBegin == nullptr) mEnd = nullptr;

	return data;
}

void Queue::print() {
	if (mBegin == nullptr) return;

	for (Node* curr = mBegin; curr != nullptr; curr = curr->getNext())
		std::cout << curr->getData() << " ";
	std::cout << std::endl;
}

int main() {
	Queue queue;
	std::cout << "Insert input: (1> enqueue; 2> dequeue; 3> print; 4> exit)" << std::endl;
	bool cont = true;

	while (cont) {
		int input, data;
		std::cout << "Input: "; std::cin >> input;
		if (input == 1) {
			std::cout << "\tValue: "; std::cin >> data;
		}

		switch(input) {
			case 1:
			  queue.enqueue(data);
				break;
			case 2:
			  try {
					queue.dequeue();
				} catch (std::runtime_error e) {
					std::cout << e.what() << std::endl;
				}
				break;
			case 3:
				queue.print();
				break;
			case 4:
				cont = false;
				break;
		}
	}

	return 0;
}
