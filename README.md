# Stock Execution

A software for Stock Exchange.


## Compilation

To Build the Project:

    cd build
    cmake ..
    make


## Execution

The following command should be run from the home directory of the project:

    ./stock


## Storage

- Input is stored in `InputFiles/Stock_Input.csv`
- Ouput is stired in `OutputFiles/OutputFile.csv`



## Sample input and output

![Screen Shot 2022-04-01 at 8 47 42 AM](https://user-images.githubusercontent.com/26688454/161298063-32b55bf2-1d16-47b9-a06d-bac62d4f2fac.png)


## Handling Errors:

1. No such file or directory

**fatal error: experimental/filesystem: No such file or directory**

Possible Solution:

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test; sudo apt-get update; sudo apt-get install gcc-8 g++-8
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 800 --slave /usr/bin/g++ g++ /usr/bin/g++-8
    make

