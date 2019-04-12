#include "Read.h"
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <experimental/filesystem>
// #include<conio.h>
// #include<dirent.h>
// #include <boost/filesystem>

namespace fs = std::experimental::filesystem;

Read::Read(){
    _checkFlag = false;
}

std::vector<StockOrder> Read::getDataFromFile()
{
    getFileName();
    std::vector<StockOrder> orderlist;
    std::ifstream file(_fileName);
    std::string line;
    while (getline(file, line)){
        if(_checkFlag)
        {
            orderlist.push_back(getStockOrder(line));
        }
        _checkFlag = true;
    }
    file.close();
    for(StockOrder order: orderlist)
        printOrder(order);
}

void Read::getFileName()
{
    std::string path = "./";
    std::vector<std::string> listOfCSV;
    std::cout<<"List of .csv files: "<<std::endl;

    for(auto& p: fs::directory_iterator("./"))
    {
        std::string fileName = p.path();
        if(fileName.substr(fileName.find_last_of(".")+1) == "csv")
        {
            listOfCSV.push_back(fileName);
            std::cout<<fileName<<std::endl;
        }
    }

    std::cout<<std::endl;

    if(listOfCSV.size() ==1 )
    {
        std::cout<<"There is only one csv file: "<<listOfCSV[0]<<std::endl;
        std::cout<<"Selecting it..."<<std::endl;
        _fileName = listOfCSV[0];
        return;
    }

    else if(listOfCSV.empty())
    {
        std::cout<<"There are no csv File."<<std::endl;
    }
    
    else
    {
        std::cout<<"Enter the file Name: ";
        std::cin>>_fileName;
    }
}

StockOrder Read::getStockOrder(std::string line)
{
    StockOrder order;
    std::vector<std::string> vec;
    boost::algorithm::split(vec, line, boost::is_any_of(","));
    order.stockID = atoi(vec[0].c_str());
    order.side = static_cast<orderSide>(vec[1]=="Buy"?0:1);
    order.companyName = vec[2];
    order.quantity = atoi(vec[3].c_str());
    return order;
}


void Read::printOrder(const StockOrder& order)
{
    std::cout<<"========================================"<<std::endl;
    std::cout<<"Stock ID: "<<order.stockID<<std::endl;
    std::cout<<"Side: "<<order.side<<std::endl;
    std::cout<<"Company Name: "<<order.companyName<<std::endl;
    std::cout<<"Quantity: "<<order.quantity<<std::endl;
    std::cout<<"========================================"<<std::endl;
}
