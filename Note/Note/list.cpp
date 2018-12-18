#include "list.h"

List::Node::Node(Note data, Node * ptrNext)
{
	this->data = data;
	this->ptrNext = ptrNext;
}

List::List()
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

List::~List()
{
	while (length != 0)
	{
		tail = head->ptrNext;
		delete head;
		head = tail;
		length--;
	}
}

void List::push()
{
	if (head == nullptr) head = new Node();
	else
	{
		tail = head;
		while (tail->ptrNext != nullptr) tail = tail->ptrNext;
		tail->ptrNext = new Node();
	}
}

void List::create(int length)
{
	if (length < 1) throw "Введена неккоректная длина списка!";
	for (int i = 0; i < length; i++)
	{
		push();
	}
	this->length = length;
}

void List::fill(string name, long long int telephone, int *date, int ID)
{
	check_tail(ID);
	tail->data.set(name, telephone, date);
}

void List::check_tail(int ID)
{
	if (ID == 0) tail = head;
	else tail = tail->ptrNext;
}

void List::show(int ID)
{
	check_tail(ID);
	tail->data.get(ID);
}

void List::sorting()
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

void List::operator+=(Note &object)
{
	push();
	length++;
	tail = head;
	while (tail->ptrNext != nullptr) tail = tail->ptrNext;
	tail->data = object;
}

void List::operator-=(int ID)
{
	if (ID > length || ID <= 0)
	{
		throw "Некорректная длина списка!";
	}
	Node *temp = head;
	Node *temp_prev = 0;
	Node *temp_next = 0;

	if (length != 0)
	{
		if (ID != 1 && ID != length)
		{
			delete_1(ID, temp, temp_prev, temp_next); // удаление элемента, находящегося в середине списка
		}

		else if (ID == 1)
		{
			delete_2(ID, temp); // удаление первого элемента списка
		}

		else if (ID == length && length != 1) // удаление последнего элемента
		{

		}
	}
}

void List::delete_1(int ID, Node * temp, Node * temp_prev, Node * temp_next)
{
	for (int i = 1; i <= length; i++)
	{

		if (i == ID - 1)
		{
			temp_prev = temp;
		}

		if (i == ID + 1)
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

void List::delete_2(int ID, Node * temp)
{
	if (length > 1)
	{
		temp = head->ptrNext;
		delete head;
		head = temp;
		length--;
	}
	else if (length == 1)
	{
		delete head;
		head = 0;
		length--;
	}
}

void List::delete_3(int ID, Node * temp, Node * temp_prev)
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

void List::show_person(long long int telephone)
{
	system("cls");
	if (length > 0)
	{
		tail = head;
		int j = 0;
		for (int i = 0; i < length; i++)
		{
			if (tail->data.get_number() == telephone)
			{
				j++;
				tail->data.get(i);
			}
			tail = tail->ptrNext;
		}
		if (j == 0) cout << "Поиск не увенчался успехом." << endl;

		system("pause");
	}
	else
	{
		system("cls");
		cout << "Сначала введите длину списка!" << endl;
		Sleep(970);
	}
}








