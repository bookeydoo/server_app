Both the server file and the clientapp use Boost for c++ so first you would need to download boost which you can get from here https://www.boost.org/

To be able to run the codes you would need to get to include the boost asio in your ide environment or include it with the files when passing it to your compiler

To include Boost libraries in your C++ application using g++, you need to specify the path to the Boost header files and libraries during the compilation and linking process123. Here’s a basic example:

g++ -I /path/to/boost main.cpp -o main -L /path/to/boost/asio -lboost_system

If you are using an ide like clion and visual studio , you would just need to include the location of the installation of boost in your system in the project properties.

