#include "func.h"

int set_length()
{
	int length;
	cout << "Введите размер списка: ";
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
	cout << "Введите фамилию и инициалы человека: ";
	getline(cin, name);
	cout << "Введите номер телефона (11 цифр): ";
	cin >> telephone;
	flush_stdin();
	cout << "Введите год рождения (05.04.1998): ";
	for (int i = 0; i < 3; i++) cin >> arr[i];
	flush_stdin();
}

int set_ID()
{
	int ID;
	cout << "Введите ID человека: ";
	cin >> ID;
	return ID;
}


long long int telephone()
{
	long long int telephone = 0;
	cout << "Введите телефон: ";
	cin >> telephone;
	return telephone;
}
