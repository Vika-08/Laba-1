#pragma once
#include "header.h"

class Note // ����� ��� - �����, ���������� ������
{
private:
	string name; // ������� � ��������
	int telephone; // ����� ���������� ��������
	int date[3]; // ���� �������� - ������ �� 3-� �����
public:
	Note(); // �����������
	void set_note(); // ��������� ���������� � ��������
	void get_note(); // �������� ���������� � ��������
	int get_day(); // �������� ���� ��������
	int get_month(); // �������� ����� ��������
	int get_year(); // �������� ��� ��������
	int get_number(); // �������� ����� ��������
	void flush_stdin(); // ������� ������ �����
};