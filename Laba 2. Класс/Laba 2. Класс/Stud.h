/*Создать класс Student:
id,  Фамилия,  Имя,  Отчество,  Дата  рождения,  Адрес,  Телефон, Факультет, Курс, Группа.
Функции-члены реализуют запись и считывание полей (проверка корректности), расчет возраста студента*/
#include <iostream>
#include <string> 
using namespace std;
class Student
{
	int ID_;
	string name_;
	string familiya_;
	string otchestvo_;
	int day_;
	int month_;
	int year_;
	string adress_;
	string number_;
	string facult_;
	int kurs_;
	int grupp_;
	Student(int);
public:
	const static int max_size = 15;
	static int size;
	bool set_ID(int);
	void set_name(string);
	void set_family(string);
	void set_otch(string);
	bool set_birth(int, int, int);
	void set_adress(string);
	bool set_number(string);
	bool set_facult(string);
	bool set_kurs(int);
	bool set_grupp(int);
	int get_ID();
	string get_name();
	string get_family();
	string get_otch();
	string get_adress();
	string get_facult();
	int get_kurs();
	int get_grupp();
	string get_number();
	void get_birth();
	int age();
	void print();
	Student(const Student&);
	Student(int, string, string, string, int, int, int,
		string, string, string, int, int);
	Student();
	~Student(){ }
	static Student* massiv(int);
};
