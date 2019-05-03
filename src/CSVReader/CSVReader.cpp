#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <experimental/filesystem>

#include "CSVReader/CSVReader.h"
#include "StockExchange/StockExchange.h"

#define ROOT_DIRECTORY "../"
#define INPUT_PATH "InputFiles/"

namespace fs = std::experimental::filesystem;

CSVReader::CSVReader() : _checkFlag(false)
{
}

CSVReader::~CSVReader() noexcept
{
    _file.close();
}

void CSVReader::init()
{
    getFileName();
    _file.open(_fileName, std::ios::in);
    std::string line;
    getline(_file, line);
}

bool CSVReader::getDataFromFile(std::list<StockOrder> &orderlist)
{
    while (true)
    {
        try
        {
            orderlist.push_back(getNextOrder());
        }
        catch (std::string &e)
        {
            std::cout << e << std::endl;
            break;
        }
    }
    return true;
}

void CSVReader::getFileName()
{
    std::string path = ROOT_DIRECTORY;
    path.append(INPUT_PATH);
    std::vector<std::string> listOfCSV;
    std::cout << "List of .csv files: " << std::endl;

    for (auto &p : fs::directory_iterator(path))
    {
        std::string fileName = p.path();
        if (fileName.substr(fileName.find_last_of(".") + 1) == "csv")
        {
            listOfCSV.push_back(fileName);
            std::cout << fileName << std::endl;
        }
    }

    std::cout << std::endl;

    if (listOfCSV.size() == 1)
    {
        std::cout << "There is only one csv file: " << listOfCSV[0] << std::endl;
        std::cout << "Selecting it...\n " << std::endl;
        _fileName = listOfCSV[0];
        return;
    }

    else if (listOfCSV.empty())
    {
        std::cout << "There are no csv File." << std::endl;
    }

    else
    {
        std::cout << "Enter the file Name: ";
        std::cin >> _fileName;
    }
}

StockOrder CSVReader::getStockOrder(std::string &line)
{
    std::vector<std::string> vec;
    boost::algorithm::split(vec, line, boost::is_any_of(","));

    StockOrder order(atoi(vec[0].c_str()), vec[2], static_cast<orderSide>(vec[1] == "Buy" ? 0 : 1), atoi(vec[3].c_str()));
    // printOrder(order);
    return order;
}

StockOrder CSVReader::getNextOrder()
{
    std::string line;
    if (getline(_file, line))
    {
        return getStockOrder(line);
    }
    else
    {
        throw std::string("End of File !!!");
    }
}

void CSVReader::printOrder(StockOrder &order)
{
    std::cout << "========================================" << std::endl;
    std::cout << "Stock ID: " << order.getStockID() << std::endl;
    std::cout << "Side: " << (static_cast<int>(order.getSide()) ? "Sell" : "Buy") << std::endl;
    std::cout << "Company Name: " << order.getCompanyName() << std::endl;
    std::cout << "Quantity: " << order.getQuantity() << std::endl;
    std::cout << "========================================" << std::endl;
}
