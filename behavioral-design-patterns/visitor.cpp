/*
You are developing a system for a zoo, which contains various types of animals, such as lions, elephants, and zebras. 
The zookeepers need to perform different operations on these animals, such as feeding, performing health check-ups, and 
cleaning their living areas.

Implement the Visitor design pattern to create a set of visitor classes that represent different operations that can be 
performed on the animals. Each visitor class should have a method for each type of animal, allowing the zookeepers to 
perform specific actions on the animals without modifying the animal classes themselves.

Your task is to design the classes and implement the logic to handle the operations on the animals using the Visitor pattern.
*/

#include <iostream>
#include <stack>
#include <string>

class Visitor {
public: 
    virtual void operationForLion() {}
    virtual void operationForZebra() {}
};

class FeedingVisitor: public Visitor {
public:
    void operationForLion() override {
        std::cout << "Fed the lion!";
    }
    void operationForZebra() override {
        std::cout << "Fed the Zebra!";
    }
};

class DoctorVisitor: public Visitor {
public:
    void operationForLion() override {
        std::cout << "Nursed the lion!";
    }
    void operationForZebra() override {
        std::cout << "Nursed the Zebra!";
    }
};

class Animal {
public: 
    virtual void move() {}
    virtual void eat() {}
    virtual void acceptVisit(Visitor v) {}
};

class Lion: public Animal {
public:
    void move() override {}
    void eat() override {}
    void acceptVisit(Visitor v) {
        v.operationForLion();
    }
};

class Zebra: public Animal {
public:
    void move() override {}
    void eat() override {}
    void acceptVisit(Visitor v) {
        v.operationForZebra();
    }
};

