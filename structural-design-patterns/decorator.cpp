#include<iostream>
#include<list>
#include<memory>
#include<stdexcept>

/****************************************************************************************************/
class Pizza {
    public: 
        virtual int getCost() const = 0;
        virtual ~Pizza() = default;
};

class Margherita: public Pizza {
    private: 
        int price_;
    public: 
        Margherita(int price): price_(price) {}

        int getCost() const override {
            return price_;
        }
};

class Farmhouse: public Pizza {
    private: 
        int price_;
    public: 
        Farmhouse(int price): price_(price) {}

        int getCost() const override {
            return price_;
        }
};

/****************************************************************************************************/
class PizzaDecorator: public Pizza {
    protected: 
        std::shared_ptr<Pizza> pizza_;
    public: 
        PizzaDecorator(std::shared_ptr<Pizza> pizza): pizza_(pizza) {}

        virtual int getCost() const = 0;

        virtual ~PizzaDecorator() = default;
};

class Cheese: public PizzaDecorator {
    public:
        Cheese(std::shared_ptr<Pizza> pizza): PizzaDecorator(pizza) {}

        int getCost() const override {
            if(!pizza_) throw std::runtime_error("Invalid Pizza");

            return pizza_->getCost() + 50;
        }
};

class Mushroom: public PizzaDecorator {
    public: 
        Mushroom(std::shared_ptr<Pizza> pizza): PizzaDecorator(pizza) {}
        
        int getCost() const override {
            if(!pizza_) throw std::runtime_error("Invalid Pizza");

            return pizza_->getCost() + 30;
        }
};

class Pepperoni: public PizzaDecorator {
    public: 
        Pepperoni(std::shared_ptr<Pizza> pizza): PizzaDecorator(pizza) {}
        
        int getCost() const override {
            if(!pizza_) throw std::runtime_error("Invalid Pizza");

            return pizza_->getCost() + 80;
        }
};
/****************************************************************************************************/

int main() {
    std::shared_ptr<Pizza> basePizza = std::make_shared<Margherita>(200);

    std::shared_ptr<Pizza> customizedPizza = std::make_shared<Pepperoni>(std::make_unique<Cheese>(basePizza));

    std::cout << "Cost of base Pizza >> " << basePizza->getCost() << std::endl;
    std::cout << "Cost of customized Pizza >> " << customizedPizza->getCost() << std::endl;
}