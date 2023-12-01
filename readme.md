Both the server file and the clientapp use Boost for c++ so first you would need to download boost which you can get from here https://www.boost.org/

To be able to run the codes you would need to get to include the boost asio in your ide environment or include it with the files when passing it to your compiler

To include Boost libraries in your C++ application using g++, you need to specify the path to the Boost header files and libraries during the compilation and linking process123. Here’s a basic example:

```g++ -I /path/to/boost main.cpp -o main -L /path/to/boost/asio -lboost_system```

If you are using an ide like clion and visual studio , you would just need to include the location of the installation of boost in your system in the project properties.

If you are planning on using cmake you can use this command to include the boost library:

 ```cmake_minimum_required(VERSION 3.12)
project(YourProjectName)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Boost
find_package(Boost REQUIRED COMPONENTS your_boost_libraries)

# Add your source files
add_executable(YourExecutable main.cpp)

# Include Boost headers
target_include_directories(YourExecutable PRIVATE ${Boost_INCLUDE_DIRS})

# Link against Boost libraries
target_link_libraries(YourExecutable PRIVATE ${Boost_LIBRARIES})

# Set compiler options for GCC
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(YourExecutable PRIVATE -Wall -Wextra -Wpedantic)```
