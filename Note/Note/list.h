#pragma once
#include "note.h"

class List : public Note // ����� ���� - ���������� �����, ����� ��� - ���� ������� ����� ������
{
private:

	class Node // ��������� �����, ���������� �� ������
	{
	public:

		Note data; // ���� ������
		Node *ptrNext; // ��������� �� ����. �������

		Node(Note data = Note(), Node *ptrNext = nullptr); // �����������
		void operator=(Node & object); // ���������� ��������� ��� ����, ����� ����� ���� ��� ���� ������ ����� �������� � ������ 
									   //void operator=(Node & object); // ���������� ���������, ����������� ��� ������ ������ 2-�� ��������
	};

	int length; // ����� ���������� �����
	Node *head; // ��������� �� 1-�� �������
	Node *tail; // ��������� �� ��������� �������

public:

	List(); // �����������
	~List(); // ����������
	void set_length(); // ���������� ����� �������
	void push_back(); // ���������� ��������
	void create_list(); // �������� ������
	void fill_list(); // ���������� ������
	void show_list(); // �������� ������
	void sorting_list(); // ���������� ������
	void swap_elements(Note &object_1, Note &object_2); // �������, �������� ������� ��������
	bool check(); // �������� �� ������������� ������
	void operator++(); // ���������� 1-�� �������� � ������
	void operator--(); // �������� 1-�� �������� �� ������ (�� ������)
	void show_person(); // ����� �������� � ���������� ����� �� ������ ��������
};