cmake_minimum_required(VERSION 3.7)
project(dbconn)

# 加载include 文件
include_directories("D:/Program Files/MariaDB 10.1/include/mysql")
# 加载外部链接文件
link_directories("D:/Program Files/MariaDB 10.1/lib")

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(dbconn ${SOURCE_FILES})

# 使用库文件
target_link_libraries(dbconn libmysql)
