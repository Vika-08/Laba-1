#include "list.h"

List::Node::Node(Note data, Node * ptrNext)
{
	cout << "Вызвался конструктор объекта класса Node - " << this << endl;
	this->data = data;
	this->ptrNext = ptrNext;
	Sleep(970);
}

List::List()
{
	cout << "Вызвался конструктор объекта класса List - " << this << endl;
	length = 0;
	head = nullptr;
	tail = nullptr;
	Sleep(970);
}

List::~List()
{
	cout << "Вызвался деструктор объекта класса List - " << this << endl;
	while (length != 0)
	{
		tail = head->ptrNext;
		delete head;
		head = tail;
		length--;
	}
	Sleep(970);
}

void List::set_length()
{
	flush_stdin();
	system("cls");
	cout << "Введите размер телефонной книги: ";
	cin >> length;
	if (length < 1 || length >= 20) throw "Введена неккоректная длина списка!";
}

void List::push_back()
{
	if (head == nullptr) head = new Node();
	else
	{
		tail = head;
		while (tail->ptrNext != nullptr) tail = tail->ptrNext;
		tail->ptrNext = new Node();
	}
}

void List::create_list()
{
	set_length();
	for (int i = 0; i < length; i++)
	{
		push_back();
	}
}

void List::fill_list()
{
	if (length > 0)
	{
		int counter = length;
		tail = head;

		for (int i = 0; i < length; i++)
		{
			system("cls");
			cout << "Осталось - " << counter-- << endl;
			tail->data.set_note();
			tail = tail->ptrNext;
		}
	}
	else
	{
		system("cls");
		cout << "Сначала введите длину списка!" << endl;
		Sleep(970);
	}
}

void List::show_list()
{
	sorting_list();
	if (length > 0)
	{
		tail = head;
		system("cls");

		cout << "Телефонная книга" << endl
			<< "-----------------" << endl << endl
			<< "ID" << "\t\t\t" << "Ф.И.О." << "\t\t\t\t" << "Номер телефона" << "\t\t\t" << "Дата рождения" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << i + 1 << "\t\t\t";
			tail->data.get_note();
			tail = tail->ptrNext;
		}
		system("pause");
	}
	else
	{
		system("cls");
		cout << "Сначала введите длину списка!" << endl;
		Sleep(970);
	}
}

void List::sorting_list()
{
	for (int i = 0; i < length - 1; i++)
	{
		tail = head;

		for (int j = 0; j < length - i - 1; j++)
		{
			if (tail->data.get_year() > tail->ptrNext->data.get_year()) // проверяем ГОД рождения соседних элементов
			{
				swap_elements(tail->data, tail->ptrNext->data);
			}

			else if (tail->data.get_year() == tail->ptrNext->data.get_year()) // если ГОДЫ равны, то проверяем МЕСЯЦА
			{
				if (tail->data.get_month() > tail->ptrNext->data.get_month())
				{
					swap_elements(tail->data, tail->ptrNext->data);
				}

				else if (tail->data.get_month() == tail->ptrNext->data.get_month()) //  если МЕСЯЦА равны, то проверяем ДНИ
				{
					if (tail->data.get_day() > tail->ptrNext->data.get_day())
					{
						swap_elements(tail->data, tail->ptrNext->data);
					}
				}
			}
			tail = tail->ptrNext;
		}
	}
}

void List::swap_elements(Note & object_1, Note & object_2)
{
	Note temp;

	temp = object_1;
	object_1 = object_2;
	object_2 = temp;
}

void List::Node::operator=(Node &object)
{
	this->data = object.data;
}

bool List::check()
{
	tail = head;

	for (int i = 0; i < length; i++)
	{
		if (tail->data.get_year() == 0) return false;
	}

	return true;
}

void List::operator++()
{
	if (check())
	{
		push_back();
		tail = head;
		while (tail->ptrNext != nullptr) tail = tail->ptrNext;
		tail->data.set_note();
		length++;
	}
	else
	{
		system("cls");
		cout << "Сначала заполните список!" << endl;
		Sleep(970);
	}
}

void List::operator--()
{
	Node *temp = head;
	Node *temp_prev = 0;
	Node *temp_next = 0;
	if (length > 0)
	{
		int index = 0;
		cout << "Введите ID (1 - " << length << ") человека, которого нужно вычеркнуть из телефонной книги: ";
		cin >> index;
		if (index > 0 && index <= length)
		{
			if (index != 1 && index != length)
			{
				for (int i = 1; i <= length; i++)
				{

					if (i == index - 1)
					{
						temp_prev = temp;
					}

					if (i == index + 1)
					{
						temp_next = temp;
					}

					if (i != length)
					{
						temp = temp->ptrNext;
					}
				}
				length--;
				delete temp_prev->ptrNext;
				temp_prev->ptrNext = temp_next;
			}

			else if (index == 1)
			{
				if (length > 1)
				{
					temp = head->ptrNext;
					delete head;
					head = temp;
				}
				else
				{
					delete head;
					head = nullptr;
				}
				length--;
			}

			else if (index == length && length != 1)
			{
				for (int i = 1; i < length; i++)
				{
					temp_prev = temp;
					temp = temp->ptrNext;
				}
				length--;
				delete tail;
				tail = temp_prev;
			}
		}
		else
		{
			cout << "Неверный ID!" << endl;
			Sleep(970);
		}
	}
	else
	{
		system("cls");
		cout << "Сначала введите длину списка!" << endl;
		Sleep(970);
	}
}

void List::show_person()
{
	system("cls");
	if (length > 0)
	{
		if (check())
		{
			tail = head;
			int j = 0;
			int requirements_telephone;
			cout << "Введите номер телефона (7 цифр): ";
			cin >> requirements_telephone;
			if (requirements_telephone < 1000000 || requirements_telephone > 9999999) throw "Некорректный номер телефона!";
			else
			{
				for (int i = 0; i < length; i++)
				{
					if (tail->data.get_number() == requirements_telephone)
					{
						cout << ++j << "\t\t\t";
						tail->data.get_note();
					}
					tail = tail->ptrNext;
				}
				if (j == 0) cout << "Поиск не увенчался успехом." << endl;
			}
			system("pause");
		}
		else
		{
			system("cls");
			cout << "Сначала заполните массив!" << endl;
			Sleep(970);
		}
	}
	else
	{
		system("cls");
		cout << "Сначала введите длину списка!" << endl;
		Sleep(970);
	}
}







