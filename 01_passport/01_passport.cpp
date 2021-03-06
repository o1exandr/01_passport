/*
Завдання 1.
o	Визначити клас Passport (паспорт), який буде містити паспортну інформацію про громадянина України(ПІБ, серія та  номер).
o	За допомогою механізму успадкування реалізувати клас ForeignPassport (закордонний паспорт) як похідний від Passport. Закордонний паспорт містить окрім паспортних даних, також дані про всі видані візи. Видані візи можна зберігати у вигляді масиву(динамічного масиву) чи вектору(vector<Visa> visas). Передбачити можливість додавання нових віз до паспорту.
o	Visa(клас або структура) містить назву країни та дату дії візи.
Протестувати роботу класів.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>
#include <vector>


using namespace std;

class Passport
{
protected:

	string name;
	string id;

public:

	Passport(string name = "unknown", string id = "XX000000") :name(name), id(id)
	{

	}

	void setName(string n)
	{
		name = n;
	}

	string getName() const
	{
		return name;
	}

	void setId(string i)
	{
		id = i;
	}

	string getId() const
	{
		return id;
	}

	void print()
	{
		cout << "\nName:\t" << getName() << "\t\nID_Ukr:\t\t" << getId() << "\n";
	}

};

struct Visa
{
	string country;
	string date;
};

class ForeignPassport : public Passport
{
	vector<Visa> visas;
	string id;

public:


	ForeignPassport(Passport p, string id):Passport(p), id(id)
	{
	}
	

	void addVisa(Visa visa)
	{
		visas.push_back(visa);
	}

	void addVisa(string country, string date)
	{
		Visa tmp;
		tmp.country = country;
		tmp.date = date;
		visas.push_back(tmp);
	}

	void print()
	{
		Passport::print();
		cout << "ID_Foreign:\t" << id << endl;
		if (visas.size() == 0)
			cout << "Don't have visas\n";
		else
		{
			cout << "Visas:\n";
			int count = 1;
			for (Visa& v : visas)
			{
				cout << "(" << count++ << ") " << v.country << "\t" << v.date << endl;
			}
		}
	}
};

int main()
{
	Passport p("Viktor Pavlik", "AB123456");

	Visa v;
	v.country = "Germany";
	v.date = "02.07.2019";

	ForeignPassport fp(p, "SF987654");
	fp.addVisa(v);
	fp.addVisa("France", "02.07.2020");
	fp.print();

	cout << endl;
	system("pause");
	return 0;
}

