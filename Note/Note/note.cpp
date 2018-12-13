#include "note.h"

Note::Note()
{
	cout << "Вызвался конструктор объекта класса Note - " << this << endl;
	name = "empty";
	telephone = 5553535;
	for (int i = 0; i < 3; i++) date[i] = 0;
	Sleep(970);
}

void Note::set_note()
{
	flush_stdin();

	cout << "Введите фамилию и инициалы человека: ";
	getline(cin, name);

	while (true)
	{
		cout << "Введите номер мобильного телефона (7 цифр): ";
		cin >> telephone;
		if (telephone >= 1000000 && telephone <= 9999999) break;
		else cout << "Некорректный номер телефона!" << endl;
		Sleep(970);
		system("cls");
		flush_stdin();
	}

	flush_stdin();

	while (true)
	{
		cout << "Введите дату рождения (например, 05 04 1998): ";
		for (int i = 0; i < 3; i++) cin >> date[i];
		if (date[0] > 0 && date[0] <= 31)
		{
			if (date[1] > 0 && date[1] <= 12)
			{
				if (date[2] >= 1950) break;
				else cout << "Некорректная дата!" << endl;
			}
			else cout << "Некорректная дата!" << endl;
		}
		else cout << "Некорректная дата!" << endl;

		Sleep(970);
		flush_stdin();
		system("cls");
	}
}

void Note::get_note()
{
	cout << name << "\t\t\t" << "8(812)-" << telephone << "\t\t\t";
	for (int i = 0; i < 3; i++)
	{
		cout << date[i];
		if (i < 2) cout << ".";
	}
	cout << endl;
}

int Note::get_day()
{
	return date[0];
}

int Note::get_month()
{
	return date[1];
}

int Note::get_year()
{
	return date[2];
}

int Note::get_number()
{
	return telephone;
}

void Note::flush_stdin()
{
	cin.clear();
	while (cin.get() != '\n');
}
