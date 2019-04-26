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

class StockOrder
{
  public:
    StockOrder(int stockID, std::string companyName, orderSide side, int quantity);

    //Getters
    int getStockID() const;
    const std::string &getCompanyName() const;
    orderSide getSide() const;
    int getQuantity() const;
    orderStatus getStatus() const;
    int getRemainingQuantity() const;

    void reduceRemainingQuantity(int quantity);

    void printOrder();

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
    int _stockID;
    std::string _companyName;
    orderSide _side;
    int _quantity;
    int _remainingQuantity;
    orderStatus _status;
};
#endif