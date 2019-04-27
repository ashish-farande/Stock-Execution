# Stock_Execution

A software for Stock Exchange.

To Build the Project:

1. cd build
2. cmake ..
3. make
[
    For the following error:

    ERROR:
    fatal error: experimental/filesystem: No such file or directory

    Run the following commands:

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test; sudo apt-get update; sudo apt-get install gcc-8 g++-8
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 800 --slave /usr/bin/g++ g++ /usr/bin/g++-8
    make
]

To Run the Project:

./stock


You can see the ouput in OutputFiles/OutputFile.csv
