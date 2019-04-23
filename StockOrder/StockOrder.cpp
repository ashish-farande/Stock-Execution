#include "StockOrder.h"

StockOrder::StockOrder(int stockID, std::string companyName, orderSide side, int quantity):_stockID(stockID), _companyName(companyName), _side(side), _quantity(quantity) 
{

}

int StockOrder::getStockID()
{
    return _stockID;
}

std::__cxx11::string StockOrder::getCompanyName()
{
    return _companyName;
}

orderSide StockOrder::getSide()
{
    return _side;
}

int StockOrder::getQuantity()
{
    return _quantity;
}

bool StockOrder::getStatus()
{
    return _status;
}