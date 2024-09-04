#include<iostream>
#include<Windows.h>
using namespace std;

class Animal
{
protected:
	char* name;
	int age;
public:
	Animal() = default;
	Animal(const char* Name, int Age)
	{
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
		age = Age;
	}

	void Print() const
	{
		cout << "Name: " << name << endl
			<< "Age: " << age << endl;
	}

	~Animal()
	{
		delete[] name;
	}
};

class Cat : public Animal
{
private:
	char* spec;
public:
	Cat() = default;
	Cat(const char* name, int age, const char* s) : Animal::Animal(name, age)
	{
		spec = new char[strlen(s) + 1];
		strcpy_s(spec, strlen(s) + 1, s);
	}
	~Cat()
	{
			delete[] spec;
	}
	void Print() const
	{
		Animal::Print();
		cout << "Species: " << spec << endl << endl;
	}
};
class Dog : public Animal
{
private:
	char* hairCol;
public:
	Dog() = default;
	Dog(const char* name, int age, const char* c) : Animal::Animal(name, age)
	{
		hairCol = new char[strlen(c) + 1];
		strcpy_s(hairCol, strlen(c) + 1, c);
	}
	~Dog()
	{
		delete[] hairCol;
	}
	void Print() const
	{
		Animal::Print();
		cout << "Wool color: " << hairCol << endl << endl;
	}
};

class Parrot : public Animal
{
private:
	char* favS;
public:
	Parrot() = default;
	Parrot(const char* name, int age, const char* s) : Animal::Animal(name, age)
	{
		favS = new char[strlen(s) + 1];
		strcpy_s(favS, strlen(s) + 1, s);
	}
	~Parrot()
	{
		delete[] favS;
	}
	void Print() const
	{
		Animal::Print();
		cout << "Favourite snack: " << favS << endl << endl;
	}
};

int main()
{
	Cat a("Barsic", 4, "British fold cat");
	Dog b("Persic", 3, "Orange");
	Parrot c("Kesha", 1, "Nuts");
	a.Print();
	b.Print();
	c.Print();

}