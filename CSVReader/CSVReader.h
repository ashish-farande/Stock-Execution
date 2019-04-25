#ifndef CSVREADER_H_
#define CSVREADER_H_

#include "I_CSVReader.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class CSVReader: public I_CSVReader
{
    public:
        CSVReader();
        virtual ~CSVReader(){;};
        virtual std::list<StockOrder> getDataFromFile();
        virtual void printOrder( StockOrder& order);

    private:
        void getFileName();
        StockOrder getStockOrder(std::string line);

    private:
        std::string _fileName;
        bool _checkFlag;
};
#endif 