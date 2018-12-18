#pragma once

#include "note.h"

class List : public Note // класс лист - телефонная книга, класс нод - один элемент этого списка
{
private:

	class Node // вложенный класс, отвечающий за данные
	{
	public:

		Note data; // сами данные
		Node *ptrNext; // указатель на след. элемент

		Node(Note data = Note(), Node *ptrNext = nullptr); // конструктор
		void operator=(Node & object); // перегрузка оператора для того, чтобы можно было все поля одного разом передать в другой 
									   //void operator=(Node & object); // перегрузка оператора, необходимая для обмена данных 2-ух объектов
	};

	int length; // длина телефонной книги
	Node *head; // указатель на 1-ый элемент
	Node *tail; // указатель на последний элемент

public:

	List(); // конструктор
	~List(); // деструктор
	void push(); // добавление элемента
	void create(int length); // создание списка
	void fill(string name, long long int telephone, int *date, int ID); // заполнение списка
	void check_tail(int ID);
	void show(int ID); // показать список
	void sorting(); // сортировка списка
	void swap_elements(Note &object_1, Note &object_2); // функция, меняющая местами элементы
	void operator+=(Note &object); // добавление 1-го элемента в список
	void operator-=(int ID); // удаление одного элемента из списка (по выбору)
	void delete_1(int ID, Node *temp, Node *temp_prev, Node *temp_next); // удаление элемента, находящегося в середине списка
	void delete_2(int ID, Node *temp); // удаление первого элемента списка
	void delete_3(int ID, Node *temp, Node *temp_prev); // удаление последнего элемента
	void show_person(long long int telephone); // найти человека в телефонной книге по номеру телефона
};