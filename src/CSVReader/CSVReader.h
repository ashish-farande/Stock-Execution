#ifndef CSVREADER_H_
#define CSVREADER_H_

#include <string>
#include <list>
#include <fstream>

#include "CSVReader/I_CSVReader.h"

class CSVReader : public I_CSVReader
{
public:
  CSVReader();
  virtual ~CSVReader() { ; };
  virtual bool getDataFromFile(std::list<StockOrder> &orderlist);
  virtual void printOrder(StockOrder &order);

private:
  void getFileName();
  StockOrder getStockOrder(std::string &line);

private:
  std::string _fileName;
  bool _checkFlag;
};
#endif