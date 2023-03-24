#include<iostream>

using namespace std;

class Pizza {
public: 
    virtual int getCost() = 0;
};

class MargheritaPizza: public Pizza {
public: 
    int getCost() override {
        return 100;
    }
};

class FarmhousePizza: public Pizza {
public: 
    int getCost() override {
        return 200;
    }
};

class ToppingDecorator: public Pizza {
protected: 
    Pizza* pizza_;
public: 
    ToppingDecorator(Pizza* pizza): pizza_(pizza) {}

    int getCost() {
        return pizza_->getCost();
    }
};

class Cheese: public ToppingDecorator {
public: 
    Cheese(Pizza *pizza): ToppingDecorator(pizza) {}

    int getCost() {
        return pizza_->getCost() + 25;
    }
};

class Pepperoni: public ToppingDecorator {
public: 
    Pepperoni(Pizza *pizza): ToppingDecorator(pizza) {}

    int getCost() {
        return pizza_->getCost() + 45;
    }
};

int main() {
    Pizza* pizza = new Pepperoni(new Cheese(new MargheritaPizza()));
    cout << pizza->getCost() << endl;
}