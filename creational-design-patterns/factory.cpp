#include<iostream>

using namespace std;

class Animal {
public:
    virtual string speak() const = 0;
};

class Dog: public Animal {
public:
    string speak() const override {
        return "Woof!";
    }
};

class Cat: public Animal {
public: 
    string speak() const override {
        return "Meow!";
    }
};

class AnimalFactory {
public:
    virtual Animal* getAnimal() const = 0;

    void makeSound() {
        cout << "Inside AnimalFactory, sound: " << getAnimal()->speak() << endl;
    }
};

class GoodBoyFactory: public AnimalFactory {
public: 
    Animal* getAnimal() const override {
        return new Dog();
    }
};

class BadBoyFactory: public AnimalFactory {
public: 
    Animal* getAnimal() const override {
        return new Cat();
    }
};

void clientCode(AnimalFactory &animalFactory) {
    Animal *animal = animalFactory.getAnimal();
    cout << animal->speak() << endl; 
    animalFactory.makeSound();
}

int main() {
    AnimalFactory *animalFactory = NULL;
    cout << "Testing GoodBoyFactory" << endl;
    animalFactory = new GoodBoyFactory();
    clientCode(*animalFactory);

    cout << "Testing BadBoyFactory" << endl;
    animalFactory = new BadBoyFactory();
    clientCode(*animalFactory);
}