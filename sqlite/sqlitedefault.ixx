export module sqlitedefault;

import sqlite;
import std;

using std::string, std::wstring;

/*
* 命名空间名：	sqlitedefault
* 作用：		包含了本解决方案中的默认数据库设定
* 修改时间：	20251227
* 修改内容：	创建
*/
export namespace sqlitedefault
{
#if UNICODE
	const wstring DATABASE_NAME = L"database.db";
#elif
	const string DATABASE_NAME = "database.db";
#endif
}