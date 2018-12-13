#pragma once
#include "note.h"

class List : public Note // класс лист - телефонна€ книга, класс нод - один элемент этого списка
{
private:

	class Node // вложенный класс, отвечающий за данные
	{
	public:

		Note data; // сами данные
		Node *ptrNext; // указатель на след. элемент

		Node(Note data = Note(), Node *ptrNext = nullptr); // конструктор
		void operator=(Node & object); // перегрузка оператора дл€ того, чтобы можно было все пол€ одного разом передать в другой 
									   //void operator=(Node & object); // перегрузка оператора, необходима€ дл€ обмена данных 2-ух объектов
	};

	int length; // длина телефонной книги
	Node *head; // указатель на 1-ый элемент
	Node *tail; // указатель на последний элемент

public:

	List(); // конструктор
	~List(); // деструктор
	void set_length(); // заполнение длины массива
	void push_back(); // добавление элемента
	void create_list(); // создание списка
	void fill_list(); // заполнение списка
	void show_list(); // показать список
	void sorting_list(); // сортировка списка
	void swap_elements(Note &object_1, Note &object_2); // функци€, мен€юща€ местами элементы
	bool check(); // проверка на незаполненный список
	void operator++(); // добавление 1-го элемента в список
	void operator--(); // удаление 1-го элемента из списка (по выбору)
	void show_person(); // найти человека в телефонной книге по номеру телефона
};