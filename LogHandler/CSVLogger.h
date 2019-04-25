#ifndef CSVLOGGER_H_
#define CSVLOGGER_H_


#include "StockOrder/StockOrder.h"
#include "fstream"
#include <memory>

class CSVLogger
{

public:
    static CSVLogger& getInstance();

    virtual ~CSVLogger();

    virtual bool writeTheOrder(const StockOrder& order);
    virtual bool changeStatus(const StockOrder& order);

private:
    const std::string getSideString (int side);
    const std::string getStatusString(int status);
    const std::string getReamQuantityString(int quantity, int remainingQuantity);

private:
    CSVLogger();
    std::fstream _outputFile;
};

#endif