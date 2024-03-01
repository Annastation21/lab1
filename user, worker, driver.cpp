#include <iostream>
#include <string>

class User {
private:
    std::string name;
    int age;
public:
    void setName(std::string n) {
        name = n;
    }
    std::string getName() {
        return name;
    }
    void setAge(int a) {
        age = a;
    }
    int getAge() {
        return age;
    }
};

class Worker : public User {
private:
    int salary;
public:
    void setSalary(int s) {
        salary = s;
    }
    int getSalary() {
        return salary;
    }
};

class Driver : public Worker {
private:
    int drivingExperience;
    std::string drivingCategory;
public:
    // constructor for Driver class
    Driver(int exp, std::string cat) {
        drivingExperience = exp;
        drivingCategory = cat;
    }
};

int main() {
    // creating objects of Worker class
    Worker Ivan;
    Ivan.setName("Иван");
    Ivan.setAge(25);
    Ivan.setSalary(1000);

    Worker Vasya;
    Vasya.setName("Вася");
    Vasya.setAge(26);
    Vasya.setSalary(2000);

    // calculating average salary between Ivan and Vasya
    int averageSalary = (Ivan.getSalary() + Vasya.getSalary()) / 2;

    std::cout << "Average salary between Ivan and Vasya: " << averageSalary << std::endl;

    return 0;
}