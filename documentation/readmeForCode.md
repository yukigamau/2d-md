# 提前声明For All
这本来是一个为作者自己设定的二次元md编辑器，所以基本是按照作者习惯设计的。  
# 工具链Tool Chain
C++23，VS 2026，Windows API。  
- C++23：		一些新的特性作者非常喜欢	Some new features looks great  
- VS 2026：		我希望其对C++23的支持更好	I hope it supports C++23 better  
- Windows API：	考虑软件体积问题			Considering the size of the software  
- sqlite3 amalgamation：用于数据处理		For data handle
# 模块modules
## 键盘input
## 文本显示document
## 数据库database
我这里引入外部包含目录的时候，认定sqlite的数据在C:\code\thirdParty\sqlite-amalgamation-3510100,附加包含的是sqlite项目。
Here, while I include outside directory, I assume the source of sqlite is in C:\code\thirdParty\sqlite-amalgamation-3510100. The project that includes sqlite is sqlite.
## AST