#ifndef CSVLOGGER_H_
#define CSVLOGGER_H_

#include "fstream"

#include "StockOrder/StockOrder.h"

class CSVLogger
{

public:
    static CSVLogger &getInstance();

    virtual ~CSVLogger();

    virtual bool writeTheOrder(const StockOrder &order);
    virtual bool changeStatus(const StockOrder &order);

private:
    const std::string getSideString(const orderSide side);
    const std::string getStatusString(const orderStatus status);
    const std::string getReamQuantityString(const units_t quantity, const units_t remainingQuantity);

private:
    CSVLogger();
    std::fstream _outputFile;
};

#endif