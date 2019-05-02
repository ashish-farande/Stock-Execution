#ifndef I_CSVREADER_H_
#define I_CSVREADER_H_


#include <string>
#include <list>

#include "StockOrder/StockOrder.h"

class I_CSVReader
{
public:
  I_CSVReader() {}
  virtual ~I_CSVReader() { ; }
  virtual void init() = 0;
  virtual bool getDataFromFile(std::list<StockOrder> &orderlist) = 0;
  virtual StockOrder getNextOrder() = 0;
};

#endif