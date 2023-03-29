#include<iostream>
#include<memory>
#include<list>

/*  OBSERVER  */
class StockObserver {
    public: 
        void onStockPriceChange(int currentPrice) const {
            std::cout << "Stock Price Was Changed!";
        }
};

/*    STOCK   */
class Stock {
    protected: 
        int price_;
    public: 
        Stock(int price): price_(price) {}

        int getCurrentPrice() const {
            return price_;
        }

        virtual void setNewPrice(int price) = 0;

        virtual ~Stock() = default;
};

/* OBSERVABLE */
class StockObservable: public Stock {
    private:
        std::list<std::shared_ptr<StockObserver>> observers_;
    public:
        StockObservable(int price): Stock(price) {}

        void attachObserver(std::shared_ptr<StockObserver> observer) {
            observers_.push_back(observer);
        }

        void removeObserver(std::shared_ptr<StockObserver> observer) {
            observers_.remove(observer);
        }

        void notify() const {
            std::cout << "price >>" << price_;
            for(const auto &observer: observers_) observer->onStockPriceChange(price_);
        }

        void setNewPrice(int price) override {
            price_ = price;
            notify();
        }
};

int main() {
    StockObservable stock(100);
    auto observer1 = std::make_shared<StockObserver>();

    stock.attachObserver(observer1);

    stock.setNewPrice(1000);
}
