#pragma once
#include "header.h"

class Note // класс нот - класс, содержащий данные
{
private:
	string name; // фамилия и инициалы
	long long int telephone; // номер мобильного телефона
	int date[3]; // дата рождения - массив из 3-х чисел
public:
	Note(); // конструктор
	void set(string name, long long int telephone, int *date); // заполнить информацию о человеке
	void get(int ID); // получить информацию о человеке
	int get_day(); // получить ДЕНЬ рождения
	int get_month(); // получить МЕСЯЦ рождения
	int get_year(); // получить ГОД рождения
	long long int get_number(); // получить номер телефона
};