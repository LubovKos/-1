#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class node {
private:
	T value;
	node<T>* next;
	node<T>* prev;
	node(T val) { value = val; next = prev = 0; }
public:

	//геттеры
	node<T>* getnext() { return next; }
	node<T>* getprev() { return prev; }
	T getvalue() { return value; }

	//сеттер
	void setvalue(T val) { value = value; }

	template <class T1> friend class list;
};

template <class T>
class list {
private:
	node<T>* first;
	node<T>* last;
	int size;
public:

	//конструктор по умолчанию
	list() {
		first = 0;
		last = 0;
		size = 0;
	}

	//геттеры
	node<T>* getfirst() { return first; }
	node<T>* getlast() { return last; }
	int get_size() { return size; }

	node<T>* create_node(T info);
	void push_front(T value);
	void push_back(T value);
	bool delete_element(int);
	bool pop_back();
	bool pop_front();
	T find_value(int idx);

	//деструктор
	~list();
};

//создание узла
template <class T>
node<T>* list<T>::create_node(T info) {
	node<T>* el = new node<T>{ info };
	el->value = info;
	el->next = 0;
	el->prev = 0;
	return el;
}

//добавление узла в начало списка
template <class T>
void list<T>::push_front(T value) {
	node<T>* new_el = create_node(value);
	if (size == 0) {
		first = new_el;
		last = first;
		size++;
		return;
	}
	if (first != 0) {
		new_el->next = first;
		first->prev = new_el;
		first = new_el;
		size++;
		return;
	}
	if (last == 0)
		last = new_el;
	size++;
}

//добавление узла в конец списка
template <class T>
void list<T>::push_back(T value) {
	node<T>* new_el = create_node(value);
	if (size == 0) {
		first = new_el;
		last = first;
		size++;
		return;
	}
	if (last != 0) {
		new_el->prev = last;
		last->next = new_el;
		last = last->next;
		size++;
		return;
	}
	if (last == 0)
		last = new_el;
	size++;
}

//удалени узла с конца списка
template <class T>
bool list<T>::pop_back() {
	if (size == 0)
		return 0;
	node<T>* new_elem = last;
	last = last->prev;
	delete new_elem;
	size--;
	return 1;
}

//удаление узла из начала списка
template <class T>
bool list<T>::pop_front() {
	if (size == 0)
		return 0;
	node<T>* new_elem = first;
	first = first->next;
	delete new_elem;
	size--;
	return 1;
}

//удаление узла по индексу
template <class T>
bool list<T>::delete_element(int idx) {
	if (idx > size)
		return 0;
	node<T>* elem = first;
	while (idx > 0) {
		elem = elem->next;
		idx--;
	}
	if (elem->prev == 0) {
		if (size > 1)
			elem->next->prev = 0;
		first = elem->next;
	}
	else
		elem->prev->next = elem->next;
	delete elem;
	size--;
	return 1;
}

//поиска узла в списке
template <class T>
T list<T>::find_value(int idx) {
	//если индекс больше размера списка, кидаем исключение
	if (idx > size)
		throw 1;
	node<T>* elem = first;
	while (idx > 0) {
		elem = elem->next;
		idx--;
	}
	return elem->value;
}

//деструктор
template <class T>
list<T>::~list() {
	if (first == 0)
		return;
	node<T>* curr = first;
	node<T>* elem = first->next;
	while (elem != 0) {
		delete curr;
		curr = elem;
		elem = curr->next;
	}
	delete curr;
	first = 0;
}

#endif
