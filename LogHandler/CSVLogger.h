#ifndef CSVLOGGER_H_
#define CSVLOGGER_H_


#include "LogHandler/I_LogHandler.h"
#include "StockOrder/StockOrder.h"
#include "fstream"
#include <memory>

class CSVLogger
{

public:
    static CSVLogger& getInstance();

    virtual ~CSVLogger();

    virtual bool writeTheOrder(const StockOrder& order);
    virtual bool changeStatus(const StockOrder &order);
    virtual bool updateRemainingQuantity(const StockOrder &order);    

private:
    const std::string getSideString (int side);
    const std::string getStatusString(int status);

private:
    CSVLogger();
    std::fstream _outputFile;
    //static std::shared_ptr<CSVLogger> s_instance;

};



#endif