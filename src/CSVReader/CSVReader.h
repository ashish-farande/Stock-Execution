#ifndef CSVREADER_H_
#define CSVREADER_H_

#include "I_CSVReader.h"
#include <string>
#include <list>
#include <fstream>

class CSVReader : public I_CSVReader
{
public:
  CSVReader();
  virtual ~CSVReader();
  virtual void init();
  virtual bool getDataFromFile(std::list<StockOrder> &orderlist);
  virtual void printOrder(StockOrder &order);
  virtual StockOrder getStockOrder(std::string &line);


private:
  StockOrder getNextOrder();
  void getFileName();

private:
  std::string _fileName;
  std::ifstream _file;
  bool _checkFlag;
};
#endif