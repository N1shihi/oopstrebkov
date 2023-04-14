#include <iostream>
#include <string>
#include <vector>



enum class Type : bool { TecTechnical, Art };

class Book {
public:
	Book(const std::string& name,const std::string& author, const Type& type) : m_name(name), m_author(author), m_type(type) {}//const ref
	Type Get_type() const {
		return m_type;
	}
private:
	const Type m_type;
	const std::string m_name;
	const std::string m_author;
};

class Libr {
public:
	std::vector <Book*> bibl;
	void Add_Book(const std::string& name, const std::string& author, const Type& type) {
		if (name != "" and author != "") {
			bibl.emplace_back(new Book(name, author, type));
		}
	}
	void Type_counter_if() {
		int Tech = 0;
		int Art = 0;
		for (Book* book : bibl) {
			if (book->Get_type() == Type::TecTechnical)
			{
				++Tech;
			}
			else if (book->Get_type() == Type::Art)
				{
					++Art;
				}
			
		}
		std::cout << "Технических книг: " << Tech << "\nХудожественных книг: " << Art << std::endl;

	}
	void Type_counter_sw() {
		int Tech = 0;
		int Art = 0;
		for (Book* book : bibl) {
			switch (book->Get_type()) {
			case Type::TecTechnical:
				++Tech;
				break;
			case Type::Art:
				++Art;
				break;
			}

		}
		std::cout << "Технических книг: " << Tech << "\nХудожественных книг: " << Art << std::endl;

	}
	~Libr(){
		for (int i = 0;i < bibl.size();++i) {
			delete bibl[i];
			bibl[i] = 0;
		}
	}

};

int main()
{
	setlocale(LC_ALL, "ru");

	Libr libr;
	libr.Add_Book("Beba", "sss", Type::TecTechnical);
	libr.Add_Book("Boba", "Dva", Type::TecTechnical);
	libr.Add_Book("Buba", "Tri", Type::Art);
	libr.Add_Book("", "dsss", Type::Art);
	libr.Type_counter_sw();
	libr.Type_counter_if();


}
