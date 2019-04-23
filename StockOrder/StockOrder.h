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
        
        int getStockID();
        std::string getCompanyName();
        orderSide getSide();
        int getQuantity();
        bool getStatus();

    private:
        int _stockID;
        std::string _companyName;
        orderSide _side;
        int _quantity;
        bool _status = false;
};
#endif