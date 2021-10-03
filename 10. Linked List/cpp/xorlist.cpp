/**
 * XOR Linked List
 * ---------------
 * 
 * An XOR linked list is a more memory efficient doubly linked list. 
 * Instead of each node holding next and prev fields, it holds a 
 * field named both, which is an XOR of the next node and the previous node.
 * 
 * Following is an implementation of XOR linked list in CPP
 * */

#include <iostream>

using namespace std;

class Node {
public:
	int _val;
	Node* _both;

	Node() {
		_val = 0;
		_both = nullptr;
	}

	Node(int val) {
		_val = val;
		_both = nullptr;
	}
};

class XORList {
	Node* start;
	Node* end;
public:
	XORList() {
		start = nullptr;
		end = nullptr;
	}

	XORList(vector<int> values) {
		start = nullptr;
		end = nullptr;
		for (size_t i = 0; i < values.size(); i++) {
			addNode(values[i]);
		}
	}

	void addNode(int val) {
		Node* newNode = new Node(val);
		if (start == nullptr) {
			// empty list!
			start = newNode;
			end = newNode;
		}
		else {
			newNode -> _both = (Node *)((uintptr_t)end ^ (uintptr_t)0);
			end -> _both = (Node *)((uintptr_t)(end -> _both) ^ (uintptr_t)newNode);
			end = newNode;
		}
	}

	Node* get(size_t index) {
		if (start == nullptr) {
			throw invalid_argument("Given indexing on empty list");
		}

		Node* prev = start;
		Node* ptr = prev -> _both;
		Node* tmp = nullptr;

		if (index == 0) {
			return prev;
		}

		size_t count = 1;
		while (ptr != nullptr) {
			if (count == index) return ptr;
			else {
				count++;
				tmp = prev;
				prev = ptr;
				if (ptr != end) ptr = (Node *)((uintptr_t)tmp ^ (uintptr_t)(ptr -> _both));
				else ptr = nullptr;
			}
		}

		throw invalid_argument("Index not in list");
	}
};

int main() {
	vector<int> v = {1, 2, 3, 5, 7, 8};
	XORList newList(v);
	cout << newList.get(3) -> _val; // outputs 5, the third element in the list
	cout << newList.get(0) -> _val; // outputs 1, the first element in the list
	newList.addNode(10);
	cout << newList.get(6) -> _val; // outputs 10, the last element in the list
	cout << newList.get(7) -> _val; // throws ndex not in list exception
	return 0;
}