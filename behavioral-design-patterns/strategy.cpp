#include<iostream>
#include<list>
#include<memory>
#include<stdexcept>

class DiscountStrategy {
    public: 
        virtual int getDiscountAmount(int totalCost) const = 0;
        virtual ~DiscountStrategy() = default;
};

class LoyaltyProgram: public DiscountStrategy {
    public: 
        int getDiscountAmount(int totalCost) const override {
            // Calculate discounted amount based on years of relationship etc.
            return 100;
        }
};

class PromotionalProgram: public DiscountStrategy {
    public: 
        int getDiscountAmount(int totalCost) const override {
            // Calculate discounted amount based on the promotion used
            return 50;
        }
};

/****************************************************************************************************/

class Product {
    public:     
        virtual int getPrice() const = 0;
        virtual ~Product() = default;
};

class Phone: public Product {
    private: 
        int price_;
    public:     
        Phone(int price): price_(price) {}

        int getPrice() const override {
            return price_;
        }
};

class Blanket: public Product {
    private: 
        int price_;
    public: 
        Blanket(int price): price_(price) {}

        int getPrice() const override {
            return price_;
        }
};

/****************************************************************************************************/

class Cart {
    private: 
        std::list<std::shared_ptr<Product>> items_;
        std::unique_ptr<DiscountStrategy> discountStrategy_;
    public: 
        Cart(std::unique_ptr<DiscountStrategy> discountStrategy): discountStrategy_(std::move(discountStrategy)) {}

        void addItem(std::shared_ptr<Product> item) {
            if(!item) {
                throw std::invalid_argument("Invalid Product");
            }

            items_.push_back(item);
        }

        void removeItem(std::shared_ptr<Product> item) {
            if(!item) {
                throw std::invalid_argument("Invalid Product");
            }

            items_.remove(item);
        }

        int getCost() const {
            int totalCost = 0;
            for(const auto &item: items_) totalCost += item->getPrice();
            return totalCost - discountStrategy_->getDiscountAmount(totalCost);
        }
};

/****************************************************************************************************/

int main() {
    Cart cart(std::make_unique<PromotionalProgram>());

    cart.addItem(std::make_unique<Phone>(500));
    cart.addItem(std::make_unique<Blanket>(250));

    std::cout << "Total Cost >> " << cart.getCost() << std::endl;
}