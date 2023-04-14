#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class Car {
public:
	Car(const std::string& model) : m_model(model) {}//const ref
	virtual ~Car() {}
	virtual void Print() = 0;
protected:
	const std::string m_model;
};

class Mercedes : public Car {
public:
	Mercedes(const std::string& model) : Car(model) {}
	virtual void Print() {
		std::cout << "Mercedes" << " : " << m_model<< std::endl;
	}
	virtual ~Mercedes() {
		std::cout << m_model << std::endl;
	}
};

class Honda : public Car {
public:
	Honda(const std::string& model) : Car( model) {}
	virtual void Print() {
		std::cout << "Honda" << " : " << m_model<< std::endl;
	}
	virtual ~Honda() {
		std::cout << m_model << std::endl;
	}
};

class Toyota : public Car {
public:
	Toyota(const std::string& model) : Car( model) {}
	virtual void Print() {
		std::cout << "Toyota" << " : "<<m_model  << std::endl;
	}
	virtual ~Toyota() {
		std::cout << m_model << std::endl;
	}
};

int main()
{
	std::ifstream file;
	std::vector <Car*> garage;
	file.open("Cars.txt");
	std::string mark;
	std::string model;
	for (;;) {
		if (file.eof()) break;
		file>> mark;
		file>> model;
		if (mark == "Mercedes") {
			garage.emplace_back(new Mercedes(model));
		}
		if (mark == "Honda") {
			garage.emplace_back(new Honda(model));
		}
		if (mark == "Toyota") {
			garage.emplace_back(new Toyota(model));
		}
	}
	for (Car* car: garage) {
		car->Print();
		delete car;
	}
}