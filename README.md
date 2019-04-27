# Stock_Execution

A software for Stock Exchange.

To Build the Project:

    cd build
    cmake ..
    make


**For the following error:**


**fatal error: experimental/filesystem: No such file or directory**

Run the following commands:

    sudo add-apt-repository ppa:ubuntu-toolchain-r/test; sudo apt-get update; sudo apt-get install gcc-8 g++-8
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 800 --slave /usr/bin/g++ g++ /usr/bin/g++-8
    make



**To Run the Project:**

    ./stock

*Input for the project is from InputFiles/Stock_Input.csv*

*You can see the ouput in OutputFiles/OutputFile.csv*

