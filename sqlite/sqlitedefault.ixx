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
	const wstring DATABASE_NAME = L"database.db";
	/*
	* theme参数说明：	default跟随系统
	*					dark深色
	*					light浅色
	*/
	const wstring SKIN_DB_INI = L"CREATE TABLE IF NOT EXISTS skindb("
		L"name TEXT PRIMARY KEY, "
		L"data TEXT);"
		L"INSERT INTO skindb (name, data) "
		L"VALUES ('theme', 'default');";
}