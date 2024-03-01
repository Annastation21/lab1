#include <iostream>
#include <string>

class Animal {
protected:
    std::string name;

public:
    Animal(std::string animalName) : name(animalName) {}

    virtual void makeNoise() {
        std::cout << "Animal noise\n";
    }

    virtual void eat() {
        std::cout << "Animal eats\n";
    }

    virtual std::string getDescription() {
        return "Generic animal";
    }

    std::string getName() const {
        return name;
    }
};

class Dog : public Animal {
public:
    Dog(std::string dogName) : Animal(dogName) {}

    void makeNoise() override {
        std::cout << "Woof woof\n";
    }

    void eat() override {
        std::cout << "Dog eats bones\n";
    }

    std::string getDescription() override {
        return "A dog named " + getName();
    }
};

class Cat : public Animal {
public:
    Cat(std::string catName) : Animal(catName) {}

    void makeNoise() override {
        std::cout << "Meow meow\n";
    }

    void eat() override {
        std::cout << "Cat eats fish\n";
    }

    std::string getDescription() override {
        return "A cat named " + getName();
    }
};

class Bear : public Animal {
public:
    Bear(std::string bearName) : Animal(bearName) {}

    void makeNoise() override {
        std::cout << "Roar roar\n";
    }

    void eat() override {
        std::cout << "Bear eats honey\n";
    }

    std::string getDescription() override {
        return "A bear named " + getName();
    }
};

class Veterinarian {
public:
    void treatAnimal(Animal* animal) {
        std::cout << "Treating: " << animal->getName() << std::endl;
        std::cout << "Description: " << animal->getDescription() << std::endl;
        animal->makeNoise();
        animal->eat();
    }
};

int main() {
    Dog dog("Rex");
    Cat cat("Whiskers");
    Bear bear("Grizzly");

    Veterinarian vet;
    vet.treatAnimal(&dog);
    vet.treatAnimal(&cat);
    vet.treatAnimal(&bear);

    return 0;
}
    