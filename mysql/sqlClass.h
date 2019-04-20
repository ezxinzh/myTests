/*
 * sqlClass.h
 *
 *  Created on: Apr 14, 2019
 *      Author: root
 */

#ifndef MYSQL_SQLCLASS_H_
#define MYSQL_SQLCLASS_H_

#include <mysql/mysql.h>
#include <memory>
#include <boost/shared_ptr.hpp>

using namespace std;

// 定义MySQL连接信息
typedef struct
{
        char* server;
        char* user;
        char* password;
        char* database;
        int port;
}MySQLConInfo;

typedef boost::shared_ptr<MySQLConInfo> ConInfoPtr;

class sqlClass
{
public:
    sqlClass();
    virtual ~sqlClass();

    void SetMySQLConInfo(char* server, char* username, char* password, char* database, int port);// 设置连接信息
    bool Open();  // 打开连接
    void Close(); // 关闭连接

private:
    MYSQL* mysql_;
    ConInfoPtr ConInfo_;
};



#endif /* MYSQL_SQLCLASS_H_ */
