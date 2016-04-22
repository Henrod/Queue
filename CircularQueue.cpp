#include <iostream>
#include <stdexcept>

class Queue {
	public:
		Queue(int size): mHead(0), mTail(0), mSize(size) { mQueue = new int[mSize]; };
		~Queue() { delete[] mQueue; };
		bool enqueue(const int& data);
		bool dequeue(int& data);
		void print();
		int mHead, mTail;
		int mSize;
	private:
		int* mQueue;

};

bool Queue::enqueue(const int& data) {
	if (mTail - mHead == mSize) return false;

	mQueue[mTail % mSize] = data;
	mTail++;

	return true;
}

bool Queue::dequeue(int& data) {
	if (mTail == mHead) return false;

	data = mQueue[mHead % mSize];
	mQueue[mHead % mSize] = 0;
	mHead++;

	return true;
}

void Queue::print() {
	//for (int i = 0; i < mSize; ++i)
	for (int i = mHead; i < mTail; ++i)
		std::cout << mQueue[i % mSize] << " ";

	std::cout << std::endl;
}

int main() {
	Queue queue = Queue(4);
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
			  if (!queue.enqueue(data)) std::cout << "Full queue" << std::endl;
				break;
			case 2:
				if (!queue.dequeue(data)) std::cout << "Empty queue" << std::endl;;
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
