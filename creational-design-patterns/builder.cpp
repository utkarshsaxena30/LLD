/* 
Imagine you are developing a system for a coffee shop that offers various types of coffee drinks. 
Each drink has a different set of properties, such as the type of coffee bean, the amount of milk, 
the size of the cup, and any additional flavors or toppings. To create a coffee drink object, 
you need to set these properties, but the properties may vary depending on the type of drink.
*/
#include<iostream>
#include<string>

class CoffeeBuilder {
    public: 
        virtual void reset() = 0;
        virtual void addMilk(int amount) const = 0;
        virtual void addCoffeeBean(std::string beanType) const = 0;
        virtual void selectSize(std::string size) const = 0;
        virtual void addTopping(std::vector<std::string> toppings) const = 0;
        virtual ~CoffeeBuilder() = default;
};

class CoffeeDirector {
    public: 
        void makeMocha(CoffeeBuilder &builder) {
            builder.addMilk(30);
            builder.addCoffeeBean("Colombian");
            builder.selectSize("M");

            std::vector<std::string> v;
            v.push_back("CoffeePowder");
            v.push_back("ToppingA");
            builder.addTopping(v);
        }

        void makeAmericano(CoffeeBuilder &builder) {
            builder.addCoffeeBean("American");
            builder.selectSize("S");

            std::vector<std::string> v;
            v.push_back("Chocolate");
            v.push_back("ToppingB");
            builder.addTopping(v);
        }
};

class Coffee {
    public: 
        int milkInMl = 0;
        std::string beanType = "";
        std::string size = "";
        std::vector<std::string> toppings;
        std::string printToppings() {
            std::string s = "";
            for(auto topping: toppings) s += topping + ", ";
            return s;
        }
        void printCoffee() {
            std::cout << "Milk: " << milkInMl << "ml, Beans: " << beanType << ", Size: " << size << ", Toppings: " << printToppings();
        }
};

class StarBucksBuilder: public CoffeeBuilder {
        Coffee *coffee;
    public: 
        StarBucksBuilder() {
            coffee = new Coffee();
        }

        void reset() override {
            delete coffee;
            coffee = new Coffee();
        }

        void addMilk(int amount) const override {
            coffee->milkInMl = amount;
        }

        void addCoffeeBean(std::string beanType) const override {
            coffee->beanType = beanType;
        }

        void selectSize(std::string size) const override {
            coffee->size = size;
        }

        void addTopping(std::vector<std::string> toppings) const override {
            coffee->toppings = toppings;
        }

        Coffee getCoffee() const {
            return *coffee;
        }

        ~StarBucksBuilder() {
            delete coffee;
        }
};

int main() {
    StarBucksBuilder *builder = new StarBucksBuilder();
    CoffeeDirector *director = new CoffeeDirector();
    
    director->makeAmericano(*builder);
    Coffee coffee = builder->getCoffee();
    coffee.printCoffee();
    std::cout << std::endl;
    
    builder->reset();
    director->makeMocha(*builder);
    coffee = builder->getCoffee();
    coffee.printCoffee();
    std::cout << std::endl;
}