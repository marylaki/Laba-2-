// Laba 2. �����.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "Stud.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string f; int g, k, choise,siz;
	/*������������*/
	{
		Student s1; cout << "constructor without parametrs S1\n";
		s1.print();
		{
			Student s2(111, "Mariya", "Lakevich", "Gennadevna", 23, 8, 1998, "Svisloch", "375297293365", "fit", 2, 1); cout << "constructor with parametrs S2\n";
			s2.print();
			s1 = s2; cout << "constructor copirovaniya iz S2 v S1\nS1:\n";
			s1.print();
			cout << "Destructor S2\n";//�.� ������� �� ������� ���������
		}
		cout << "Destructor S1\n";//�.� ������� �� ������� ���������
	}
	/*������ � ��������*/
	cout << "Massiv size\n"; cin >>siz;
	Student* stud = Student::massiv(siz);//�������� �������
	for (int i = 0; i < siz; i++)//�����
	{
		stud[i].print();
	}
	do
	{
		cout << "1-spisok faculteta, 2-spisok grupp\n";//menu �����-0
		cin >> choise;
		switch (choise)
		{
		case 1://������ ����������
			cout << "Spisok Faculteta? ";
			cin >> f;
			cout << "Spisok Studentov " << f << endl;
			for (int i = 0; i < siz; i++)
			{
				if (f == stud[i].get_facult())
					stud[i].print();
			}break;
		case 2://������ ������
			cout << "Spisok Gruppbl\n";
			cout << "Facultet? ";
			cin >> f;
			cout << "Kurs? ";
			cin >> k;
			cout << "Gruppa? ";
			cin >> g;
			cout << "Spisok Studentov " << f<<" " << k << " " << g << endl;
			for (int i = 0; i < siz; i++)
			{
				if (f == stud[i].get_facult() && stud[i].get_kurs() == k && stud[i].get_grupp() == g)
					stud[i].print();
			}break;
		}
	} while (choise != 0);
	return 0;
}

