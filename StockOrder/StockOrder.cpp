#include "StockOrder.h"
#include <assert.h> 
#include <iostream>

StockOrder::StockOrder(int stockID, std::string companyName, orderSide side, int quantity):_stockID(stockID), _companyName(companyName), _side(side), _quantity(quantity), _remainingQuantity(quantity) 
{

}

void StockOrder::setStatus(bool status)
{
    _status = status;
}

int StockOrder::getStockID() const
{
    return _stockID;
}

const std::string& StockOrder::getCompanyName() const
{
    return _companyName;
}

orderSide StockOrder::getSide() const
{
    return _side;
}

int StockOrder::getQuantity() const 
{
    return _quantity;
}

bool StockOrder::getStatus() const
{
    return _status;
}

int StockOrder::getRemainingQuantity() const
{
    return _remainingQuantity;
}

void StockOrder::reduceRemainingQuantity(int quantity)
{
    assert(quantity<=_remainingQuantity);
    _remainingQuantity -= quantity;
}

void StockOrder::printOrder()
{
    std::cout<<"========================================================================"<<std::endl;
    std::cout<<"The StockID is: "<<_stockID<<std::endl;
    std::cout<<"The Order side is: "<<_side<<std::endl;
    std::cout<<"The Company Name is: "<<_companyName<<std::endl;
    std::cout<<"The Quantity is: "<<_quantity<<std::endl;
    std::cout<<"The Remaining is: "<<_remainingQuantity<<std::endl;
    std::cout<<"The Status is: "<<_status<<std::endl;
    std::cout<<"========================================================================"<<std::endl;
}