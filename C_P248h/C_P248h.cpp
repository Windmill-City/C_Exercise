// C_P248h.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

template<class T>
struct Node
{
	Node<T>* prev;
	Node<T>* after;
	T value;
	Node<T>(Node<T>* _prev, Node<T>* _after, T _value) {
		prev = _prev;
		after = _after;
		value = _value;
	}
};

template<class T>
class LinkedList {
	int _size = 0;

	Node<T>* head;
	Node<T>* tail;

	LinkedList(Node<T>* _head) {
		head = tail = _head;
		Node<T>* node = head;
		while (node)
		{
			_size++;
			node = node->after;
		}
	}

	Node<T>* getNode(int index) {
		if (index < 0 || index > _size) {
			throw "Index out of range";
		}
		else {
			Node<T>* temp = head;
			for (int i = 0; i < index; i++, temp = temp->after);
			return temp;
		}
	};

	void add(Node<T>* node, T value) {
		if (!node)//empty list
			head = tail = new Node<T>(NULL, NULL, value);
		else {
			Node<T>* current = new Node<T>(node, node->after, value);
			node->after = current;
			if (!current->after)//nothing behind set tail
				tail = current;
			else
				current->after->prev = current;
		}
		_size++;
	}

	T remove(Node<T>* node) {
		if (!node)
			return NULL;
		T value = node->value;
		Node<T>* _prev = node->prev;
		Node<T>* _after = node->after;
		if (!_after)//nothing behind, set tail
			tail = _prev;
		else
			_after->prev = _prev;
		if (!_prev)//nothing ahead, so it is head
			head = _after;
		else
			_prev->after = _after;
		delete node;
		_size--;
		return value;
	}
public:
	LinkedList() {
		LinkedList(NULL);
	}

	void addLast(T value) {
		add(tail, value);
	}

	void addFirst(T value) {
		if (head) {
			T _tmp = head->value;
			head->value = value;
			return add(head, _tmp);
		}
		add(head, value);
	}

    void add(int index, T value) {
		add(getNode(index), value);
	}

	T removeLast() {
		return remove(tail);
	}

	T removeFirst() {
		return remove(head);
	}

	T remove(int index) {
		if (index < 0 || index >= _size)
			throw "Index out of range";
		return remove(getNode(index));
	}

	T get(int index) {
		if (index < 0 || index >= _size)
			throw "Index out of range";
		else if (index == 0)
			return head->value;
		else if (index == _size - 1)
			return tail->value;
		else
			return getNode(index)->value;
	}

	int size() {
		return _size;
	}
};
template<class T>
class Stack {
	LinkedList<T>* list;
public:
	Stack() {
		list = new LinkedList<T>();
	}
	void push(T value) {
		list->addFirst(value);
	}
	T pop() {
		return list->removeFirst();
	}
	T get(int index) {
		list->get(index);
	}
	int size() {
		list->size();
	}
};
template<class T>
class Queue {
	LinkedList<T>* list;
public:
	Queue() {
		list = new LinkedList<T>();
	}
	void in(T value) {
		list->addFirst(value);
	}
	T out() {
		return list->removeLast();
	}
	T get(int index) {
		list->get(index);
	}
	int size() {
		list->size();
	}
};

int main() {

	LinkedList<int>* nums = new LinkedList<int>();
	nums->addFirst(1);
	nums->addFirst(2);
	nums->addFirst(3);
	nums->addFirst(4);
	for (int i = 0; i < nums->size(); i++) {
		printf("%d\n", nums->get(i));
	}
	printf("-------------------\n");
	nums->removeFirst();
	nums->removeLast();
	for (int i = 0; i < nums->size(); i++) {
		printf("%d\n", nums->get(i));
	}
	printf("-------------------\n");
	nums->addLast(5);
	nums->addLast(6);
	for (int i = 0; i < nums->size(); i++) {
		printf("%d\n", nums->get(i));
	}
	printf("-------------------\n");
	nums->remove(2);
	nums->add(1, 8);
	for (int i = 0; i < nums->size(); i++) {
		printf("%d\n", nums->get(i));
	}
	Queue<int>* queue = new Queue<int>();
	queue->in(1);
	queue->in(2);
	queue->in(3);
	queue->in(4);
	printf("%d", queue->out());
	printf("%d", queue->out());
	printf("%d", queue->out());
	printf("%d\n", queue->out());
	Stack<int>* stack = new Stack<int>();
	stack->push(1);
	stack->push(2);
	stack->push(3);
	stack->push(4);
	printf("%d", stack->pop());
	printf("%d", stack->pop());
	printf("%d", stack->pop());
	printf("%d", stack->pop());
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
