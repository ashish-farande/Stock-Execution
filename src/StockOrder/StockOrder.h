#ifndef STOCK_ORDER_H
#define STOCK_ORDER_H

#include <string>

enum orderStatus
{
  OPEN = false,
  CLOSED = true
};

enum orderSide
{
    BUY,
    SELL
};

typedef int units_t ;
typedef int stockID_t; 
typedef std::string companyName_t;

class StockOrder
{
  public:
    StockOrder(units_t stockID, std::string companyName, orderSide side, units_t quantity);

    //Getters
    const stockID_t getStockID() const;
    const companyName_t &getCompanyName() const;
    const orderSide getSide() const;
    const units_t getQuantity() const;
    const orderStatus getStatus() const;
    const units_t getRemainingQuantity() const;

    void reduceRemainingQuantity(units_t quantity);

    void printOrder() const;

    void closeOrder();

    bool operator==(const StockOrder *order) const
    {
      return this->_stockID == order->_stockID;
    }

    bool operator==(const StockOrder &order) const
    {
      return this->_stockID == order._stockID;
    }

  private:
    stockID_t _stockID;
    companyName_t _companyName;
    orderSide _side;
    units_t _quantity;
    units_t _remainingQuantity;
    orderStatus _status;
};
#endif