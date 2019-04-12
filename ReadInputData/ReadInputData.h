#ifndef READINPUTDATA_H_
#define READINPUTDATA_H_

#include "I_ReadInputData.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class ReadInputData: public I_ReadInputData
{

    private:
        std::string _fileName;
        bool _checkFlag;

    public:
        ReadInputData();
        virtual ~ReadInputData(){;};
        virtual std::vector<StockOrder> getDataFromFile();
        virtual void printOrder(const StockOrder& order);

    private:
        void getFileName();
        StockOrder getStockOrder(std::string line);
        
};
#endif 