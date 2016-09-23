#include "stdafx.h"
#include "Stud.h"

bool Student::set_ID(int id)
{
	if (id > 0)
		ID_ = id;
	else
		ID_ = 0;
	return id > 0;
}

void Student::set_name(string name)
{
	name_ = name;
}

void Student::set_family(string fam)
{
	familiya_ = fam;
}

void Student::set_otch(string otch)
{
	otchestvo_ = otch;
}

bool Student::set_birth(int d, int m, int y)
{
	if (d > 0 && d<32 && m>0 && m<13 && y>1950 && y<2017)
	{
		day_ = d;
		month_ = m;
		year_ = y;
		return true;
	}
	else
	{
		day_ = 0;
		month_ = 0;
		year_ = 0;
		return false;
	}
}

void Student::set_adress(string adr)
{
	adress_ = adr;
}

bool Student::set_number(string number)
{
	string num = "1234567890-";
	int i,j, lenght;
	bool t=true;
	lenght = number.length();
	for (i = 0; i < lenght && t; i++)
	{
		t = false;
		for (j = 0; j < 11;j++)
		if (number[i] == num[j]) t = true;
	}
	if (t)
		number_ = number;
	else
		number_ = "no";
	return t;
}

bool Student::set_facult(string facl)
{
	if (facl == "fit" || facl == "tov" || facl == "eef" || facl == "xtit" || facl == "lx" )
	{
		facult_ = facl;
		return true;
	}
	else
	{
		facult_ = "no";
		return false;
	}
}

bool Student::set_kurs(int k)
{
	if (k > 0 && k < 6)
		kurs_ = k;
	else
		kurs_ = 0;
	return (k > 0 && k < 6);
}

bool Student::set_grupp(int g)
{
	if (g>0 && g < 15)
		grupp_ = g;
	else
		grupp_ = 0;
	return (g>0 && g < 15);
}

int Student::get_ID()
{
	return ID_;
}

string Student::get_name()
{
	return name_;
}

string Student::get_family()
{
	return familiya_;
}

string Student::get_otch()
{
	return otchestvo_;
}

string Student::get_adress()
{
	return adress_;
}

string Student::get_facult()
{
	return facult_;
}

int Student::get_kurs()
{
	return kurs_;
}

int Student::get_grupp()
{
	return grupp_;
}

string Student::get_number()
{
	return number_;
}

void Student::get_birth()
{
	if (day_ < 10)
		cout << 0;
	cout << day_ << '/';
	if (month_ < 10)
		cout << 0;
	cout << month_ << '/' << year_<<' ';
}

int Student::age()
{
	int d = 24, m = 9, y = 2016, age=0;
	age = y - year_;
	if ((month_ == m && day_>d) || (month_ > m))
		age--;
	return age;
}

void Student::print()
{
	cout << ID_ << ". " << name_ << ' ' << familiya_ << ' ' << otchestvo_ << ' ';
	this->get_birth();
	cout << adress_ << " tel:" << number_ << ' ' << facult_ << ' ' << kurs_ << "k " << grupp_ << "g\n";
}

Student::Student(const Student&A)
{
	ID_ = A.ID_;
	name_ = A.name_;
	familiya_ = A.familiya_;
	otchestvo_ = A.otchestvo_;
	day_ = A.day_;
	month_ = A.month_;
	year_ = A.year_;
	adress_ = A.adress_;
	number_ = A.number_;
	facult_ = A.facult_;
	kurs_ = A.kurs_;
	grupp_ = A.grupp_;
}

Student::Student(int id, string nam, string fam, string otch, int d, int m, int y,
	string ad, string num, string facl, int k, int gr)
{
	this->set_ID(id);
	this->set_name(nam);
	this->set_family(fam);
	this->set_otch(otch);
	this->set_birth(d, m, y);
	this->set_adress(ad);
	this->set_number(num);
	this->set_facult(facl);
	this->set_kurs(k);
	this->set_grupp(gr);
}

Student::Student() :ID_(0), name_("no"), familiya_("no"), otchestvo_("no"),
day_(0), month_(0), year_(0), adress_("no"), number_("no"), facult_("no"), kurs_(0), grupp_(0)
{
}

Student::Student(int i)
{
	string str;
	int m, g;
	cout << "Private constructor\n";
	this->set_ID(i);
	cout << "Name: "; cin >> str; this->set_name(str);
	cout << "Familiya "; cin >> str; this->set_family(str);
	cout << "Otchestvo "; cin >> str; this->set_otch(str);
	cout << "Birthday:\nDay: "; cin >> i; cout << "Month: "; cin >> m; cout << "Year: "; cin >> g; this->set_birth(i, m, g);
	cout << "Adress: "; cin >> str; this->set_adress(str);
	cout << "Tel. number: "; cin >> str; this->set_number(str);
	cout << "Facultet: "; cin >> str; this->set_facult(str);
	cout << "Kurs: "; cin >> i; this->set_kurs(i);
	cout << "Grupp: "; cin >> i; this->set_grupp(i);
}

 Student* Student::massiv(int siz)
{
	Student* m = new Student[Student::max_size];
	for (int i=0; i < siz; i++)
	{
		Student mi(i+1);
		m[i] = mi;
	}
	return m;
}

