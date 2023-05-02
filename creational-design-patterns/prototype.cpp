#include<iostream>

class Prototype {
    public: 
        virtual Prototype* clone() const = 0;
        virtual void show() const = 0;
};

class ConcretePrototype: public Prototype {
        int _x;
    public: 
        ConcretePrototype(int x): _x(x) {}
        ConcretePrototype* clone() const override {
            return new ConcretePrototype(*this);
        }
        void show() const override {
            std::cout << "In concrete, " << _x << std::endl;
        }
};

class SubclassPrototype: public ConcretePrototype {
        int _y;
    public: 
        SubclassPrototype(int y, int x): ConcretePrototype(x) {
            _y = y;
        }

        SubclassPrototype* clone() const override {
            return new SubclassPrototype(*this);
        }

        void show() const override {
            ConcretePrototype::show();
            std::cout << "In subclass, " << _y << std::endl;
        }
};

void client(Prototype &prototype) {
    Prototype *prototype2 = prototype.clone();
    prototype2->show();
}

int main() {
    std::cout << "Cloning concrete: " << std::endl;
    ConcretePrototype p1(10);
    client(p1);

    std::cout << "Cloning subclass: " << std::endl;
    SubclassPrototype p2(5, 2);
    client(p2);
}