#ifndef STOCK_ORDER_H
#define STOCK_ORDER_H

#include <string>


enum orderSide {
    BUY,
    SELL
};

class StockOrder
{
    public:
        StockOrder(int stockID, std::string companyName, orderSide side, int quantity);
        
        //Setters 
        void closeOrder();

        //Getters
        int getStockID() const;
        const std::string& getCompanyName() const;
        orderSide getSide() const;
        int getQuantity() const;
        bool getStatus() const;
        int getRemainingQuantity() const;

        void reduceRemainingQuantity(int quantity);

        void printOrder();


    private:
        int _stockID;
        std::string _companyName;
        orderSide _side;
        int _quantity;
        int _remainingQuantity;
        bool _status = false;

};
#endif