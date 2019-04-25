#include "LogHandler/CSVLogger.h"
#include <limits>
#include <iostream>

#define FILE_NAME "Output/OutputFile.csv"

CSVLogger& CSVLogger::getInstance()
{
    static CSVLogger obj;
    return obj;
}

CSVLogger::CSVLogger()
{
    _outputFile.open(FILE_NAME, std::ios::in | std::ios::out);
    _outputFile << "StockID,Side,Company,Quantity,Status\n";
}

CSVLogger::~CSVLogger()
{
    _outputFile.close();
}

bool CSVLogger::writeTheOrder(const StockOrder &order)
{
    std::string str = std::to_string(order.getStockID()) + "," + getSideString(order.getSide()) +  "," + order.getCompanyName() + "," + std::to_string(order.getQuantity()) +";"+std::to_string(order.getRemainingQuantity()) + "," + getStatusString(order.getStatus()) + "\n";
    _outputFile.write(str.c_str(), str.length()) ;
    return true;
}

bool CSVLogger::changeStatus(const StockOrder &order)
{
    int currentLine = 0;
    _outputFile.seekg(0);
    
    while (currentLine < order.getStockID())
    {
        _outputFile.ignore( std::numeric_limits<std::streamsize>::max(), '\n') ;
        ++currentLine ;
    }

    _outputFile.seekg(_outputFile.tellp());
    std::string str = std::to_string(order.getStockID()) + "," + getSideString(order.getSide()) +  "," + order.getCompanyName() + "," + std::to_string(order.getQuantity()) +";" + getReamQuantityString(order.getQuantity(), order.getRemainingQuantity()) + "," + getStatusString(order.getStatus())+ "\n" ;    
    _outputFile.write(str.c_str(), str.length()) ;
    
    return true;
}

const std::string CSVLogger::getSideString(int side)
{
    return side?"Sell":"Buy";
}

const std::string CSVLogger::getStatusString(int status)
{
    return status?"CLOSED":"OPEN  ";

}

const std::string CSVLogger::getReamQuantityString(int quantity, int remainingQuantity)
{
    std::string remainingQuantityStr;
    remainingQuantityStr =  std::to_string(remainingQuantity);
    while(std::to_string(quantity).length() > remainingQuantityStr.length())
        remainingQuantityStr.append(" ");
    return remainingQuantityStr;
}