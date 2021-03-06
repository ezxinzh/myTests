/*
 * sqlClass.cpp
 *
 *  Created on: Apr 14, 2019
 *      Author: root
 */
#include "sqlClass.h"

sqlClass::sqlClass()
:mysql_(new(MYSQL)),
 ConInfo_(new(MySQLConInfo)),
 result_(NULL)
{
    mysql_library_init(0, NULL, NULL);
    mysql_init(mysql_);
}

sqlClass::~sqlClass()
{
    delete(mysql_);
}

// set info of connection
void sqlClass::SetMySQLConInfo(char* server, char* username, char* password, char* database, int port)
{
    ConInfo_->server = server;
    ConInfo_->user = username;
    ConInfo_->password = password;
    ConInfo_->database = database;
    ConInfo_->port = port;
}

bool sqlClass::Open()
{
    if (mysql_real_connect(mysql_, ConInfo_->server, ConInfo_->user, \
            ConInfo_->password, ConInfo_->database, ConInfo_->port, 0, 0) != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// shutdown the connection
void sqlClass::Close()
{
    mysql_close(mysql_);
}

bool sqlClass::select(const string& queryStr, vector<vector<string>>& data)
{
    if(mysql_query(mysql_, queryStr.c_str()) != 0)
    {
        return false;
    }
    result_ = mysql_store_result(mysql_);
    // TO DO
    return true;
}





