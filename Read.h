#ifndef STOCK_READ_H_
#define STOCK_READ_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

enum orderSide {
    BUY,
    SELL
};

struct StockOrder {
    int stockID;
    std::string companyName;
    orderSide side;
    int quantity;
};

class Read{

    private:
        std::string _fileName;
        bool _checkFlag;

    public:
        Read();
        ~Read();
        std::vector<StockOrder> getDataFromFile();

    private:
        void getFileName();
        StockOrder getStockOrder(std::string line);
        void printOrder(const StockOrder& order);
};
#endif 