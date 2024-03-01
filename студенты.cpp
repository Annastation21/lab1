#include <iostream>
#include <string>

class Student {
protected:
    std::string firstName;
    std::string lastName;
    std::string group;
    double averageMark;
public:
    Student(std::string firstName, std::string lastName, std::string group, double averageMark)
        : firstName(firstName), lastName(lastName), group(group), averageMark(averageMark) {}

    virtual double getScholarship() {
        if (averageMark == 5) {
            return 2000;
        }
        else {
            return 1900;
        }
    }
};

class Aspirant : public Student {
public:
    Aspirant(std::string firstName, std::string lastName, std::string group, double averageMark)
        : Student(firstName, lastName, group, averageMark) {}

    double getScholarship() override {
        if (averageMark == 5) {
            return 2500;
        }
        else {
            return 2200;
        }
    }
};

int main() {
    Student student1("John", "Doe", "Group1", 4.8);
    Aspirant aspirant1("Jane", "Smith", "Group2", 5.0);

    Student students[2] = { student1, aspirant1 };

    for (int i = 0; i < 2; i++) {
        std::cout << "Scholarship for student " << i + 1 << ": " << students[i].getScholarship() << std::endl;
    }

    return 0;
}