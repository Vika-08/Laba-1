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
			<< "1 - ������ ������ ���������� �����;" << endl
			<< "2 - ��������� ���������� �����;" << endl
			<< "3 - ��������� � ���������� �����;" << endl
			<< "4 - �������� �������;" << endl
			<< "5 - ������� �������" << endl
			<< "6 - ����� �� ������ ��������;" << endl
			<< "0 - ����� �� ���������." << endl << endl << "-> ";
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
			cout << "������ �������� ����� ��������! ���������, ��������� �������!" << endl;
			Sleep(970);
			break;
		}
	} while (key != 0);

	return 0;
}