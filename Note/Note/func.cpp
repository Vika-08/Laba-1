#include "func.h"

int set_length()
{
	int length;
	cout << "������� ������ ������: ";
	cin >> length;
	flush_stdin();
	return length;
}

void flush_stdin()
{
	cin.clear();
	while (cin.get() != '\n');
}

void set_note(string &name, long long int &telephone, int *arr)
{
	cout << "������� ������� � �������� ��������: ";
	getline(cin, name);
	cout << "������� ����� �������� (11 ����): ";
	cin >> telephone;
	flush_stdin();
	cout << "������� ��� �������� (05.04.1998): ";
	for (int i = 0; i < 3; i++) cin >> arr[i];
	flush_stdin();
}

int set_ID()
{
	int ID;
	cout << "������� ID ��������: ";
	cin >> ID;
	return ID;
}


long long int telephone()
{
	long long int telephone = 0;
	cout << "������� �������: ";
	cin >> telephone;
	return telephone;
}
