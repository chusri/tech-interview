// This class defines a node of the singly linked list.

#ifndef SLIST_NODE_H
#define SLIST_NODE_H

template <class T>
class slist_node {
	private:
		T data;
		slist_node<T>* next;

	public:
		slist_node(const T& data) : data(data), next(nullptr) {}
		T get_data(void) const;
		slist_node<T>* get_next(void) const;
		void set_data(const T& data);
		void set_next(slist_node<T>* const next);
};

template <class T>
T slist_node<T>::get_data(void) const {
	return data;
}

template <class T>
slist_node<T>* slist_node<T>::get_next(void) const {
	return next;
}

template <class T>
void slist_node<T>::set_data(const T& data) {
	this->data = data;
}

template <class T>
void slist_node<T>::set_next(slist_node<T>* const next) {
	this->next = next;
}

#endif //SLIST_NODE_H
