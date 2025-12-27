export module sqlite;

import <sqlite3.h>;

import std;

using std::function, std::runtime_error, std::vector, std::wstring;

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
		sqlite3* pdb = nullptr;
		sqlite3_stmt* stmt = nullptr;

	public:
		Sql(const wstring& s);
		Sql(const wstring& s, const wstring& ini);
		~Sql();

	private:
		void exec(const wstring& s, bool ifSave);
		void open(const wstring& s);

	public:
		
		void select(const wstring& table, const vector<wstring>& list);
	};
}

sqlite::Sql::Sql(const wstring& s)
{
	open(s);
}
sqlite::Sql::Sql(const wstring& s, const wstring& ini)
{
	open(s);
	exec(ini, false);
}
sqlite::Sql::~Sql()
{
	if (stmt)
		sqlite3_finalize(stmt);
	if (pdb)
		sqlite3_close(pdb);
}

void sqlite::Sql::exec(const wstring& s, bool ifSave)
{
	int rc = sqlite3_prepare16_v2(pdb, s.c_str(), -1, &stmt, nullptr);
	if (rc != SQLITE_OK)
		throw runtime_error("sql语法错误。");

	rc=sqlite3_step(stmt);
	if (rc != SQLITE_DONE && rc != SQLITE_ROW)
		throw runtime_error("sql语句执行失败。");

	if (ifSave)
		sqlite3_finalize(stmt);
}

void sqlite::Sql::open(const wstring& s)
{
	int rc = sqlite3_open16(s.c_str(), &pdb);
	if (rc)
		throw runtime_error("sql语法错误。");
}

void sqlite::Sql::select(const wstring& table, const vector<wstring>& list)
{
	wstring sql = L"SELECT ";
	for (const auto& s : list)
		sql += s + L" ";

	sql += table;
	exec(sql, true);
}