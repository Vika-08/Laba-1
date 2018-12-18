#include "header.h"
#include "list.h"
#include "func.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	int key;
	List list;

	string temp_name = " ";
	long long int temp_telephone = 0;
	int temp_date[3]{ 0 };
	int temp_length = 0;
	Note temp;

	do
	{
		system("cls");
		cout
			<< "1 - ввести размер телефонной книги и заполнить ее;" << endl
			<< "2 - заглянуть в телефонную книгу;" << endl
			<< "3 - добавить заметку;" << endl
			<< "4 - удалить заметку" << endl
			<< "5 - поиск по номеру телефона;" << endl
			<< "0 - выход из программы." << endl << endl << "-> ";
		cin >> key;

		switch (key)
		{
		case 1:
			try
			{
				system("cls");
				list.create(temp_length = set_length());
				for (int i = 0; i < temp_length; i++)
				{
					system("cls");
					cout << "Осталось - " << temp_length - i << endl;
					set_note(temp_name, temp_telephone, temp_date);
					list.fill(temp_name, temp_telephone, temp_date, i);
				}
			}
			catch (const char *error)
			{
				system("cls");
				cout << error;
				Sleep(970);
			}
			break;
		case 2:
			system("cls");
			cout << "ID" << "\t\t\t" << "Ф.И.О." << "\t\t\t" << "\tТелефон" << "\t\t" << "Год рождения" << endl;
			list.sorting();
			for (int i = 0; i < temp_length; i++)
			{
				list.show(i);
			}
			system("pause");
			break;
		case 3:
			flush_stdin();
			temp_length++;
			set_note(temp_name, temp_telephone, temp_date);
			temp.set(temp_name, temp_telephone, temp_date);
			list.operator+=(temp);
			break;
		case 4:
			flush_stdin();
			temp_length--;
			list.operator-=(set_ID());
			break;
		case 5:
			flush_stdin();
			list.show_person(telephone());
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