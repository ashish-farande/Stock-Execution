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

typedef int Quantity;
typedef int StockID; 
typedef std::string CompanyName;

class StockOrder
{
  public:
    StockOrder(Quantity stockID, std::string companyName, orderSide side, Quantity quantity);

    //Getters
    const StockID getStockID() const;
    const CompanyName &getCompanyName() const;
    const orderSide getSide() const;
    const Quantity getQuantity() const;
    const orderStatus getStatus() const;
    const Quantity getRemainingQuantity() const;

    void reduceRemainingQuantity(Quantity quantity);

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
    StockID _stockID;
    CompanyName _companyName;
    orderSide _side;
    Quantity _quantity;
    Quantity _remainingQuantity;
    orderStatus _status;
};
#endif