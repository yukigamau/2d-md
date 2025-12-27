export module sqlite;

import <sqlite3.h>;

import std;

using std::function, std::runtime_error, std::wstring;

/*
* 命名空间名：	sqlite
* 作用：		封装数据库操作
* 修改时间：	20251227
* 修改内容：	创建
*/
export namespace sqlite
{
	class Sql
	{
	private:
		sqlite3* db;

	public:
		Sql(const wstring& s);
		Sql(const wstring& s, const wstring& ini);

	public:
		void exec(const wstring& s);

	private:
		void open(const wstring& s);
	};
}

sqlite::Sql::Sql(const wstring& s)
{
	open(s);
}
sqlite::Sql::Sql(const wstring& s, const wstring& ini)
{
	open(s);
}

void sqlite::Sql::exec(const wstring& s)
{
	sqlite3_stmt* _stmt;

	int rc = sqlite3_prepare16_v2(db, s.c_str(), -1, &_stmt, nullptr);
	if (rc != SQLITE_OK)
		throw runtime_error("sql语法错误。");

	rc=sqlite3_step(_stmt);
	if (rc != SQLITE_DONE && rc != SQLITE_ROW)
		throw runtime_error("sql语句执行失败。");

	sqlite3_finalize(_stmt);
}

void sqlite::Sql::open(const wstring& s)
{
	int rc = sqlite3_open16(s.c_str(), &db);
	if (rc)
		throw runtime_error("sql语法错误。");
}