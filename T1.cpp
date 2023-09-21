#include <iostream>

//队列或栈的最大数据量
const int MAX_SIZE = 100;

struct Queue {
	long long data[MAX_SIZE];
	int front = 0,rear = 0;


	void Init() {
		front = 0;
		rear = 0;
	}

	int Add(long long e) {
		if (rear == MAX_SIZE - 1) {
			std::cout << "Queue is full!" << std::endl;
			return -1;
		}
		else {
			rear++;
			data[rear] = e;
			return 0;
		}

	}

	int Pop(long long &e) {
		if (rear == front) {
			std::cout << "Queue is empty!" << std::endl;
			return -1;
		}
		else {
			front++;
			e = data[front];
			return 0;
		}
	}

};

struct Stack {
	long long data[MAX_SIZE];
	int front = 0, bottom = 0;


	void Init() {
		front = 0;
		bottom = 0;
	}

	int Add(long long e) {
		if (front == MAX_SIZE - 1) {
			std::cout << "Stack is full!" << std::endl;
			return -1;
		}
		else {
			front++;
			data[front] = e;
			return 0;
		}

	}

	int Pop(long long& e) {
		if (bottom == front) {
			std::cout << "\n"<<"Stack is empty!" << std::endl;
			return -1;
		}
		else {
			e = data[front];
			front--;
			return 0;
		}
	}

};

void id() {
	//定义一个队列
	Queue queue;
	//队列初始化
	queue.Init();


	long long id;
	std::cout << "Please input an element to the queue:";
	std::cin >> id;
	if(queue.Add(id))std::cout<<"fail";

	long long e;
	std::cout << "Output an element from the queue:";
	if(queue.Pop(e))std::cout<<"fail";
	std::cout << e << std::endl;
}

//实现进制转换
void numChange() {
	Stack stack;
	stack.Init();

	std::cout << "Please input a number to change:";
	int num;
	std::cin >> num;
	std::cout << "Input scale,no more than 10:";
	int divide;
	std::cin >> divide;

	while (num!=0)
	{
		int a = num % divide;
		stack.Add(a);
		num = num / divide;
	}

	while (true) {
		long long a = 0;
		if(stack.Pop(a))break;
		std::cout << a;
	}
	std::cout << std::endl;

}

int main()
{

	start:std::cout << "Choose Mode:\n" << "1.Queue\n" << "2.Number scale change\n";
	int mode;
	std::cin >> mode;
	switch (mode)
	{
	case 1:
		id();
		break;
	case 2:
		numChange();
		break;
	default:
		std::cout << "Error"<<std::endl;
		goto start;
		break;
	}
}
