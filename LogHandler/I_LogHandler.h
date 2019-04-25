#ifndef I_LOGHANDLER_H_
#define I_LOGHANDLER_H_

#include "StockOrder/StockOrder.h"

class I_LogHandler{

public:
    I_LogHandler(){}
    virtual ~I_LogHandler(){}

    virtual bool writeTheOrder(const StockOrder& order) = 0;
    virtual bool changeStatus(int orderID) = 0;
    virtual bool updateRemainingQuantity(int orderID, int quantity) = 0;    
};


#endif