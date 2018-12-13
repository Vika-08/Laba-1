#include "header.h"
#include "list.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	int key;

	List list;

	do
	{
		system("cls");
		cout
			<< "1 - ввести размер телефонной книги;" << endl
			<< "2 - заполнить телефонную книгу;" << endl
			<< "3 - заглянуть в телефонную книгу;" << endl
			<< "4 - добавить заметку;" << endl
			<< "5 - удалить заметку" << endl
			<< "6 - поиск по номеру телефона;" << endl
			<< "0 - выход из программы." << endl << endl << "-> ";
		cin >> key;

		switch (key)
		{
		case 1:
			try
			{
				list.create_list();
			}
			catch (const char *error)
			{
				system("cls");
				cout << error;
				Sleep(970);
			}
			break;
		case 2:
			list.fill_list();
			break;
		case 3:
			list.show_list();
			break;
		case 4:
			list.operator++();
			break;
		case 5:
			list.operator--();
			break;
		case 6:
			try
			{
				list.show_person();
			}
			catch (const char *error)
			{
				system("cls");
				cout << error;
				Sleep(970);
			}
			break;
		case 0:
			break;
		default:
			system("cls");
			cout << "Введен неверный номер действия! Пожалуста, повторите попытку!" << endl;
			Sleep(970);
			break;
		}
	} while (key != 0);

	return 0;
}