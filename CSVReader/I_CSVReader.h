#ifndef I_CSVREADER_H_
#define I_CSVREADER_H_

#include <string>
#include <queue>
#include "StockOrder/StockOrder.h"


class I_CSVReader
{
    public:
      I_CSVReader() {}
      virtual ~I_CSVReader() {}
      virtual std::queue<StockOrder> getDataFromFile() = 0;
      virtual void printOrder(StockOrder &order) = 0;

};

#endif