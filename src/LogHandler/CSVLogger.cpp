#include <iostream>
#include <limits>

#include "LogHandler/CSVLogger.h"

#define FILE_NAME "../OutputFiles/OutputFile.csv"

CSVLogger &CSVLogger::getInstance()
{
    static CSVLogger s_instance;
    return s_instance;
}

CSVLogger::CSVLogger()
{
    _outputFile.open(FILE_NAME, std::ios::in | std::ios::out | std::ios::trunc);
    _outputFile << "StockID,Side,Company,Quantity,Status\n";
}

CSVLogger::~CSVLogger()
{
    _outputFile.close();
}

bool CSVLogger::writeTheOrder(const StockOrder &order)
{
    std::string str = std::to_string(order.getStockID()) + "," + getSideString(order.getSide()) + "," + order.getCompanyName() + "," + std::to_string(order.getQuantity()) + ";" + std::to_string(order.getRemainingQuantity()) + "," + getStatusString(order.getStatus()) + "\n";
    _outputFile.write(str.c_str(), str.length());
    return true;
}

bool CSVLogger::changeStatus(const StockOrder &order)
{
    int currentLine = 0;
    _outputFile.seekg(0);

    while (currentLine < order.getStockID())
    {
        _outputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ++currentLine;
    }

    _outputFile.seekg(_outputFile.tellp());
    std::string str = std::to_string(order.getStockID()) + "," + getSideString(order.getSide()) + "," + order.getCompanyName() + "," + std::to_string(order.getQuantity()) + ";" + getReamQuantityString(order.getQuantity(), order.getRemainingQuantity()) + "," + getStatusString(order.getStatus()) + "\n";
    _outputFile.write(str.c_str(), str.length());
    return true;
}

const std::string CSVLogger::getSideString(const orderSide side)
{
    return static_cast<bool>(side) ? "Sell" : "Buy";
}

const std::string CSVLogger::getStatusString(const orderStatus status)
{
    return static_cast<bool>(status) ? "CLOSED" : "OPEN  ";
}

const std::string CSVLogger::getReamQuantityString(const units_t quantity, const units_t remainingQuantity)
{
    std::string remainingQuantityStr;
    remainingQuantityStr = std::to_string(remainingQuantity);
    while (std::to_string(quantity).length() > remainingQuantityStr.length())
        remainingQuantityStr.append(" ");
    return remainingQuantityStr;
}