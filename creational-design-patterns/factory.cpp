#include<iostream>

using namespace std;

class Animal {
public:
    virtual void speak() = 0;
};

class Dog: public Animal {
public:
    void speak() override {
        cout << "Woof!";
    }
};

class Cat: public Animal {
public: 
    void speak() override {
        cout << "Meow!";
    }
};

class AnimalFactory {
public: 
    Animal* getAnimal(string input) {
        if(input == "DOG") return new Dog();
        else if(input == "CAT") return new Cat();
        return NULL;
    }
};

int main() {
    AnimalFactory animalFactory;
    Animal* animal = animalFactory.getAnimal("CAT");

    animal->speak();
}