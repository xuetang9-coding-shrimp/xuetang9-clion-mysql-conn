#include <iostream>
#include <mysql.h>
#include <windows.h>
using namespace std;
int main() {
    MYSQL *conn = mysql_init(NULL); // 初始化
    if(nullptr != conn){
        MYSQL *pMysql = mysql_real_connect(conn, "127.0.0.1", "root", "xiami", "blog", 3306, nullptr, 0); // 获取数据库链接
        mysql_set_character_set(pMysql,"gb2312"); // 设置编码
        if(nullptr!=pMysql){
            int query_result = mysql_query(pMysql, "select * from article"); // 查询数据库
            MYSQL_RES *pRes = mysql_store_result(pMysql); // 准备接受数据
            MYSQL_ROW row;
            unsigned int len = mysql_num_fields(pRes); // 获取表的字段长度
            while((row = mysql_fetch_row(pRes))){ // 加载一行数据
                for (int i = 0; i < len; ++i) { // 便利所有列的数据
                    char* msg = row[i]; // 获取一条数据
                    if(nullptr!=msg){ // 判断得到数据是否为空
                        cout << row[i]; // 输出数据
                    }
                     cout << "\t" ; // 缩进处理
                }
                cout << endl; // 换行
            }
            mysql_free_result(pRes); // 释放数据存储
        }
    }
    mysql_close(conn); // 关闭数据库连
    cout << "\n\n数据库测试结束." << endl;
    system("pause");
    return 0;
}