#include <iostream>
#include <string>

using namespace std;

class Course{

};

class Teacher : public Course{
private:
	string firstName, secondName, address, city;
	int age, phone;
public:
	Teacher(string firstName, string secondName, string address, string city, int age, int phone) {
		this->firstName = firstName;
		this->secondName = secondName;
		this->address = address;
		this->city = city;
		this->age = age;
		this->phone = phone;
	}

};
class Student: public Course {
private:
	string firstName, secondName, address, city;
	int age, phone;
public:
	Student(string firstName, string secondName, string address, string city, int age, int phone) {
		this->firstName = firstName;
		this->secondName = secondName;
		this->address = address;
		this->city = city;
		this->age = age;
		this->phone = phone;
	}

};
int main() {

	Course Intermediate[4];

	

	Student Student1 = Student("Jane", "Doe", "America", "New York", 18, 1234);
	Student Student2 = Student("Joseph", "Doe", "America", "New York", 18, 1234);
	Student Student3 = Student("Jose", "Doe", "America", "New York", 18, 1234);

	Teacher Teacher1 = Teacher("Jefferson", "Doe", "America", "New York", 18, 1234);

	Intermediate[0] = Student1;
	Intermediate[1] = Student2;
	Intermediate[2] = Student3;
	Intermediate[3] = Teacher1;

	return 0;
}
