#ifndef I_CSVREADER_H_
#define I_CSVREADER_H_

#include "StockOrder/StockOrder.h"
#include <string>
#include <list>

class I_CSVReader
{
public:
  I_CSVReader() {}
  virtual ~I_CSVReader() {;}
  virtual bool getDataFromFile(std::list<StockOrder> &orderlist) = 0;
  virtual void printOrder(StockOrder &order) = 0;
};

#endif