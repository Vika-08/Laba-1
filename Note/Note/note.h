#pragma once
#include "header.h"

class Note // класс нот - класс, содержащий данные
{
private:
	string name; // фамилия и инициалы
	int telephone; // номер мобильного телефона
	int date[3]; // дата рождения - массив из 3-х чисел
public:
	Note(); // конструктор
	void set_note(); // заполнить информацию о человеке
	void get_note(); // получить информацию о человеке
	int get_day(); // получить ДЕНЬ рождения
	int get_month(); // получить МЕСЯЦ рождения
	int get_year(); // получить ГОД рождения
	int get_number(); // получить номер телефона
	void flush_stdin(); // очистка потока ввода
};