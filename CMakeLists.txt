cmake_minimum_required(VERSION 3.10) # Specify the minimum version of CMake required

# Project name and version
project(NovaCrypt VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(NovaCrypt main.cpp novacrypt.cpp)

# If you have additional libraries or dependencies, you can link them here
# target_link_libraries(NovaCrypt <your_libraries>)
