/*
You are developing a software system for a coffee shop. The coffee shop serves various types of beverages, such as 
"Espresso," "Cappuccino," and "Latte." Each beverage has a common preparation process, but there are variations in the 
ingredients and certain steps.

Implement the Template design pattern to create a base class for the beverage and define a template method that represents 
the common preparation process. The template method should call specific methods for the variations in ingredients and 
steps, which will be implemented in the subclasses for each type of beverage.

Your task is to design the classes and implement the logic to prepare beverages using the Template pattern
*/

#include <iostream>
#include <stack>
#include <string>

class Coffee {
public: 
    virtual void make() final {
        commonStep1();
        commonStep2();
        uniqueStep3();
        commonStep4();
    }

    void commonStep1() {}
    void commonStep2() {}
    virtual void uniqueStep3() const = 0;
    void commonStep4() {}
};

class Espresso: public Coffee {
public: 
    void uniqueStep3() const override {
        std::cout << "Unique Espresso step!";
    }
};

class Cappucino: public Coffee {
public: 
    void uniqueStep3() const override {
        std::cout << "Unique Cappucino step!";
    }
};

class Latte: public Coffee {
public: 
    void uniqueStep3() const override {
        std::cout << "Unique Latte step!";
    }
};