#ifndef I_READINPUTDATA_H_
#define I_READINPUTDATA_H_

#include <string>
#include <vector>

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

class I_ReadInputData
{
    public:
        I_ReadInputData(){;};
        virtual ~I_ReadInputData(){;};
        virtual std::vector<StockOrder> getDataFromFile()=0;
        virtual void printOrder(const StockOrder& order) = 0;

};

#endif