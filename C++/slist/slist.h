// This class defines a singly linked list.

#ifndef SLIST_H
#define SLIST_H

#include<new>
#include<vector>
#include<cassert>
#include<iostream>
#include "slist_node.h"

using namespace std;

template <class T>
class slist {
	private:
		int size;
		slist_node<T>* head;
		slist_node<T>* tail;
		vector<int> search(const T& data);
		slist_node<T>* create_node(const T& data);

	public:
		slist() : size(0), head(nullptr), tail(nullptr) {}
		slist(const slist<T>& list);
		slist<T>& operator= (const slist<T>& list);

		T& front(void) const;
		int insert_after(const int pos, const T& data);
		bool erase_after(const int pos);
		void push_front(const T& data);
		bool pop_front(void);
		void remove(const T& data);
		bool empty(void) const;
		void clear(void);

		// Overload the << operator
		friend ostream& operator<< (ostream& out, const slist<T>& list) {
			slist_node<T>* ptr = list.head;
			while (ptr) {
				out << ptr->get_data() << " ";
				ptr = ptr->get_next();
			}
			return out;
		}

		// Perform a deep copy of the list l2 into l1
		friend void deep_copy(slist<T>& l1, const slist<T>& l2) {
			int pos = 0;
			slist_node<T>* ptr = l2.head;
			while (ptr) {
				pos = l1.insert_after(pos, ptr->get_data());
				ptr = ptr->get_next();
			}
		}

		~slist();
};

// Search for 'data' in the list and return the positions
template <class T>
vector<int> slist<T>::search(const T& data) {
	int i = 1;
	vector<int> pos;
	slist_node<T>* ptr = head;

	while (ptr) {
		if (data == ptr->get_data()) {
			pos.push_back(i);
		}
		i++;
		ptr = ptr->get_next();
	}

	return(pos);
}

// Create a new linked list node
template <class T>
slist_node<T>* slist<T>::create_node(const T& data) {
	slist_node<T>* node = new slist_node<T>(data);
	assert(node);
	return(node);
}

// Copy constuctor
template <class T>
slist<T>::slist(const slist<T>& list) : slist() {
	deep_copy(*this, list);
}

// Overload the assignment operator
template <class T>
slist<T>& slist<T>::operator= (const slist<T>& list) {
	clear();
	deep_copy(*this, list);
	return(*this);
}

// Return the data from the front of the list
template <class T>
T& slist<T>::front(void) const {
	assert(head);
	return(head->get_data());
}

// Insert node after pos nodes
template <class T>
int slist<T>::insert_after(const int pos, const T& data) {
	assert(pos >= 0 && pos <= size);

	if (pos == 0) {
		push_front(data);
	} else if (pos == size) {
		slist_node<T>* ptr = tail;
		tail = create_node(data);
		ptr->set_next(tail);
		size++;
	} else {
		slist_node<T>* ptr1 = head;
		slist_node<T>* ptr2 = nullptr;
		slist_node<T>* ptr3 = nullptr;

		for (int i = 1; i < pos; i++) {
			ptr1 = ptr1->get_next();
		}

		ptr2 = ptr1->get_next();
		ptr3 = create_node(data);
		ptr1->set_next(ptr3);
		ptr3->set_next(ptr2);

		size++;
	}

	assert((pos+1) <= size);
	return(pos+1);
}

// Erase the node after pos
template <class T>
bool slist<T>::erase_after(const int pos) {
	assert(pos >= 0 && pos < size);
	assert(head);

	if (pos == 0) {
		assert(pop_front());
	} else if (pos == size-1) {
		slist_node<T>* ptr1 = head;
		slist_node<T>* ptr2 = nullptr;

		for (int i = 1; i < pos; i++) {
			ptr1 = ptr1->get_next();
		}
		ptr2 = ptr1->get_next();
		ptr1->set_next(nullptr);
		tail = ptr1;
		delete ptr2;
		size--;
	} else {
		slist_node<T>* ptr1 = head;
		slist_node<T>* ptr2 = nullptr;

		for (int i = 1; i < pos; i++) {
			ptr1 = ptr1->get_next();
		}
		ptr2 = ptr1->get_next();
		ptr1->set_next(ptr2->get_next());
		delete ptr2;
		size--;
	}

	return(true);
}

// Push a node to the front of the list
template <class T>
void slist<T>::push_front(const T& data) {
	if (!head) {
		head = tail = create_node(data);
	} else {
		slist_node<T>* ptr_old_node = head;
		slist_node<T>* ptr_new_node = create_node(data);
		head = ptr_new_node;
		ptr_new_node->set_next(ptr_old_node);
	}
	size++;
}

// Remove the first node from the list
template <class T>
bool slist<T>::pop_front(void) {
	if (!head) {
		return(false);
	} else {
		slist_node<T>* node = head;
		head = head->get_next();
		delete node;
		size--;
		return(true);
	}
}

// Remove all elements = data
template <class T>
void slist<T>::remove(const T& data) {
	vector<int> pos = search(data);
	for (int i = 0; i < pos.size(); i++) {
		erase_after(pos[i]-1-i);
	}
}

// Is the list empty?
template <class T>
bool slist<T>::empty(void) const {
	assert(size >= 0);
	return(size == 0);
}

// Delete all the nodes in the list
template <class T>
void slist<T>::clear(void) {
	while (head) {
		assert(pop_front());
	}
	assert(size == 0);
}

// Destructor
template <class T>
slist<T>::~slist() {
	// Delete the nodes in the list
	clear();
}

#endif //SLIST_H
