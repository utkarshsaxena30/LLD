#include <iostream>

class Singleton {
    private:
        static Singleton* instance;
        int value;

        Singleton(int v) : value(v) {}

    public:
        static Singleton* getInstance(int v);

        int getValue() const {
            return value;
        }

        void setValue(int v) {
            value = v;
        }
};

Singleton* Singleton::instance = nullptr;
Singleton* Singleton::getInstance(int v) {
    if (!instance) {
        instance = new Singleton(v);
    }
    return instance;
}

int main() {
    Singleton* s1 = Singleton::getInstance(42);
    Singleton* s2 = Singleton::getInstance(24);

    std::cout << s2->getValue() << std::endl;
    std::cout << s1->getValue() << std::endl;

    return 0;
}
