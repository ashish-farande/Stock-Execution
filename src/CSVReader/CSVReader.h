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
  virtual ~CSVReader() override;
  virtual void init() override;
  virtual bool getDataFromFile(std::list<StockOrder> &orderlist) override;
  virtual StockOrder getNextOrder() override;

private:
  StockOrder getStockOrder(std::string &line);
  void printOrder(StockOrder &order);

  void getFileName();

private:
  std::string _fileName;
  std::ifstream _file;
  bool _checkFlag;
};
#endif