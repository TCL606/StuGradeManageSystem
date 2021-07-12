#ifndef INTERFACE_H
#define INTERFACE_H
#pragma once
#include<Windows.h>
#include"api.h"
#include"student.h"
using namespace std;
enum Error
{
	OverFlow, InputError
};
struct ErrorType
{
	Error err;
	ErrorType(Error x) :err(x) {}
};
class Interface :public BaseFun_Interface  //读写模式，可修改其中的数据
{
public:
	void Show_Main(StudentList& li)override
	{
		system("color 0E");
		while (1)
		{
			system("cls");
			char page;
			cout <<
				"                 ===============================学生管理系统====================================" << endl <<
				"                                               1、打印学生信息                                  " << endl <<
				"                                               2、添加学生信息                                  " << endl <<
				"                                               3、删除学生信息                                  " << endl <<
				"                                               4、搜索学生                                      " << endl <<
				"                                               5、修改学生信息                                  " << endl <<
				"                                               6、成绩排名与均分                                  " << endl <<
				"                                               7、保存学生信息                                  " << endl <<
				"                                               8、读取学生信息                                  " << endl <<
				"                                               9、返回                                          " << endl << endl << endl;
			cout << "请输入选项: ";
			while (cin >> page, cin.ignore(1024, '\n'), page > 9 + '0' || page < 1 + '0')
			{
				cout << "请重新输入选项:";
			}
			switch (page)
			{
			case '1': Show_StuInfo(li); break;
			case '2': Add_StuInfo(li);  break;
			case '3': Delete_StuInfo(li); break;
			case '4': Search_Stu(li);  break;
			case '5': Modify_Stu(li); break;
			case '6': Sort_Stu(li); break;
			case '7': Save_StuInfo(li); break;
			case '8': Read_StuInfo(li); break;
			case '9': return;
			}
		}
	}
	void Show_StuInfo(const StudentList& li)override
	{
		system("cls");
		cout << "                     " << "姓名" << "              " << "学号" <<
			"        " << "语文" << "      " << "数学" << "      " << "英语" <<
			"      " << "总分" << endl;
		li.Display();
		cout << endl << endl << endl << "请按回车键返回。" << endl;
		cin.get();
	}
	void Add_StuInfo(StudentList& li)override
	{
		char* name;
		char* id;
		double math, chinese, english;
		system("cls");
		cout << "                                               添加学生信息" << endl;
		while (1)
		{
			do
			{
				cout << "请输入学生姓名： " << endl;
				try
				{
					name = new char[31];
					cin >> name;
					if (strlen(name) >= 30)
					{
						cin.clear();
						cin.ignore(1024, '\n');
						delete[]name;
						throw(ErrorType(OverFlow));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "名字过长！请检查是否输入错误！" << endl;
				}
			} while (1);
			do
			{
				cout << "请输入学生学号： " << endl;
				try
				{
					id = new char[100]; //防止溢出造成bug。
					cin >> id;
					if (cin.fail() || strlen(id) > ID_Length)
					{
						cin.clear();
						cin.ignore(1024, '\n');
						delete[]id;
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "学号过长！请重新输入！" << endl;
				}
			} while (1);
			do
			{
				cout << "请输入语文成绩： " << endl;
				try
				{
					cin >> chinese;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "输入语文成绩失败，请重新输入！" << endl;
				}
			} while (1);
			do
			{
				cout << "请输入数学成绩： " << endl;
				try
				{
					cin >> math;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "输入数学成绩失败，请重新输入！" << endl;
				}
			} while (1);
			do
			{
				cout << "请输入英语成绩： " << endl;
				try
				{
					cin >> english;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "输入英语成绩失败，请重新输入！" << endl;
				}
			} while (1);
			if (li.Add(StudentNode(name, id, chinese, math, english)))
				cout << "添加成功！" << endl << "是否继续？y/n" << endl;
			else cout << "学号重复！添加失败！" << endl << "是否继续？y/n" << endl;
			delete[]name;
			delete[]id;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "请重新输入：" << endl << "是否继续？y/n" << endl;
			}
			if (t == 'y' || t == 'Y')
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
	void Delete_StuInfo(StudentList& li)override
	{
		system("cls");
		char* id;
		cout << "                                               删除学生信息" << endl;
		while (1)
		{
			id = new char[100];
			cout << "请输入要删除的学生学号: " << endl;
			cin >> id;
			cin.ignore(1024, '\n');
			if (li.DeleteByID(id))
				cout << "删除成功！" << endl;
			else cout << "学号为" << id << "的学生不存在！" << endl;
			delete[]id;
			cout << "是否继续？y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "请重新输入：" << endl << "是否继续？y/n" << endl;
			}
			if (t == 'y' || t == 'Y')
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
	void Search_Stu(StudentList& li)override
	{
		system("cls");
		cout << "                                                 搜索学生" << endl;
		while (1)
		{
			cout << "                                               1、按学号搜索" << endl <<
				"                                               2、按姓名搜索" << endl;
			cout << "请输入选项：" << endl;
			char a;
			while (cin >> a, cin.ignore(1024, '\n'), a != '1' && a != '2')
			{
				cout << "请重新输入选项：" << endl;
			}
			if (a == '1')
			{
				char* id = new char[100];
				cout << "请输入要搜索的学生学号：" << endl;
				cin >> id;
				cin.ignore(1024, '\n');
				Student stu;
				if (li.SearchByID(id, stu))
				{
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << endl;
					cout << stu << endl;
				}
				else cout << "学号为" << id << "的学生不存在！" << endl;
				delete[] id;
			}
			else
			{
				char* name = new char[100];
				cout << "请输入要搜索的学生姓名： " << endl;
				cin >> name;
				cin.ignore(1024, '\n');
				cout << endl;
				Student stu;
				li.SearchByName(name, stu, true);
				delete[]name;
			}
			cout << "是否继续？y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "请重新输入：" << endl << "是否继续？y/n" << endl;
			}
			if (t == 'y' || t == 'Y')
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
	void Modify_Stu(StudentList& li)override
	{
		system("cls");
		cout << "                                               修改学生信息" << endl;
		char* id;
		double math, chinese, english;
		while (1)
		{
			do
			{
				cout << "请输入要修改的学生学号：" << endl;
				try
				{
					id = new char[100]; //防止溢出造成bug。
					cin >> id;
					if (cin.fail() || strlen(id) > ID_Length)
					{
						cin.clear();
						cin.ignore(1024, '\n');
						delete[]id;
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "学号过长！请重新输入！" << endl;
				}
			} while (1);
			do
			{
				cout << "请输入修改后的语文成绩： " << endl;
				try
				{
					cin >> chinese;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "输入语文成绩失败，请重新输入！" << endl;
				}
			} while (1);
			do
			{
				cout << "请输入修改后的数学成绩： " << endl;
				try
				{
					cin >> math;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "输入数学成绩失败，请重新输入！" << endl;
				}
			} while (1);
			do
			{
				cout << "请输入修改后的英语成绩： " << endl;
				try
				{
					cin >> english;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						throw(ErrorType(InputError));
					}
					break;
				}
				catch (ErrorType)
				{
					cout << "输入英语成绩失败，请重新输入！" << endl;
				}
			} while (1);
			if (li.ModifyByID(id, chinese, math, english)) cout << "修改成功!" << endl;
			else cout << "学号为" << id << "的学生不存在！" << endl;
			delete[]id;
			cout << "是否继续？y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "请重新输入：" << endl << "是否继续？y/n" << endl;
			}
			if (t == 'y' || t == 'Y')
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
	void Sort_Stu(StudentList& li)override
	{
		system("cls");
		cin.clear();
		vector<Student> st;
		char x;
		cout << "                                                 成绩排序" << endl;
		while (1)
		{
			cout << "                                               1、按总分排序" << endl;
			cout << "                                               2、按科目排序" << endl;
			cout << "                                               3、求平均分" << endl;
			cout << "请输入选项：" << endl;
			while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2' && x != '3')
			{
				cin.clear();
				cout << "请重新输入选项：" << endl;
			}
			if (x == '1')
			{
				cout << "若从高到低排名，请输入1；否则输入2：" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2')
				{
					cin.clear();
					cout << "请重新输入：" << endl;
				}
				if (x == '1')
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        总分排名" << endl;
					li.Sort(Subject::_Total);
				}
				else
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        总分排名" << endl;
					li.Sort(Subject::_Total, true);
				}
			}
			else if (x == '2')
			{
				char y;
				cout << "                                                 a.按语文排序" << endl;
				cout << "                                                 b.按数学排序" << endl;
				cout << "                                                 c.按英语排序" << endl;
				cout << "请输入选项：" << endl;
				while (cin >> y, cin.ignore(1024, '\n'), y != 'a' && y != 'b' && y != 'c' && y != 'A' && y != 'B' && y != 'C')
				{
					cin.clear();
					cout << "请重新输入：" << endl;
				}
				cout << "若从高到低排名，请输入1；否则输入2：" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2')
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "请重新输入：" << endl;
				}
				if (x == '1' && (y == 'a' || y == 'A'))
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        语文排名" << endl;
					li.Sort(Subject::_Chinese);
				}
				else if (x == '2' && (y == 'a' || y == 'A'))
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        语文排名" << endl;
					li.Sort(Subject::_Chinese, true);
				}
				else if (x == '1' && (y == 'b' || y == 'B'))
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        数学排名" << endl;
					li.Sort(Subject::_Math);
				}
				else if (x == '2' && (y == 'b' || y == 'B'))
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        数学排名" << endl;
					li.Sort(Subject::_Math, true);
				}
				else if (x == '1' && (y == 'c' || y == 'C'))
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        英语排名" << endl;
					li.Sort(Subject::_English);
				}
				else if (x == '2' && (y == 'c' || y == 'C'))
				{
					cout << endl;
					cout << "                     " << "姓名" << "              " << "学号" <<
						"        " << "语文" << "      " << "数学" << "      " << "英语" <<
						"      " << "总分" << "        英语排名" << endl;
					li.Sort(Subject::_English, true);
				}
			}
			else
			{
				cout << "                                                 a.求语文均分" << endl;
				cout << "                                                 b.求数学均分" << endl;
				cout << "                                                 c.求英语均分" << endl;
				cout << "                                                 d.求总分均分" << endl;
				cout << "请输入选项：" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != 'a' && x != 'b' && x != 'c' && x != 'd' && x != 'A' && x != 'B' && x != 'C' && x != 'D')
				{
					cin.clear();
					cout << "请重新输入选项：" << endl;
				}
				Subject sub; char str[15];
				if (x == 'a' || x == 'A')strcpy(str, "语文均分："), sub = Subject::_Chinese;
				else if (x == 'b' || x == 'B')strcpy(str, "数学均分："), sub = Subject::_Math;
				else if (x == 'c' || x == 'C')strcpy(str, "英语均分："), sub = Subject::_English;
				else strcpy(str, "总分均分："), sub = Subject::_Total;
				double grade = li.Average(sub);
				cout << "                                                 " << str << grade << endl;
			}
			cout << "是否继续？y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "请重新输入：" << endl << "是否继续？y/n" << endl;
			}
			if (t == 'y' || t == 'Y')
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
	void Save_StuInfo(StudentList& li)override
	{
		system("cls");
		char* filename;
		char p;
		cout << "                                               保存学生信息" << endl;
		while (1)
		{
			cout << "                                               1、直接保存" << endl;
			cout << "                                               2、排名后保存" << endl;
			cout << "请输入选项：" << endl;
			while (cin >> p, cin.ignore(1024, '\n'), p != '1' && p != '2')
			{
				cout << "请重新输入选项：" << endl;
			}
			if (p == '1')
			{
				cout << "请输入保存后的文件名(输入回车则以默认方式保存，便于下次读取)：" << endl;
				if (p = cin.peek() != '\n')
				{
					filename = new char[100];
					cin >> filename;
					cin.ignore(1024, '\n');
					cout << "                                               正在保存......" << endl << endl;
					if (li.Save(filename))
						cout << "                                           " << filename << ".txt保存成功!" << endl;
					else cout << "                                            保存失败!" << endl;
					delete[]filename;
				}
				else
				{
					cin.ignore(1024, '\n');
					cout << "                                               正在保存......" << endl << endl;
					if (li.Save())
						cout << "                                           学生成绩信息.txt保存成功!" << endl;
					else cout << "                                            保存失败!" << endl;
				}
			}
			else
			{
				char x;
				char ascend;
				Subject sub;
				cout << "                                               1、按总分排序" << endl;
				cout << "                                               2、按科目排序" << endl << endl << endl;
				cout << "请输入选项：" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2')
				{
					cin.clear();
					cout << "请重新输入选项：" << endl;
				}
				if (x == '1')
				{
					sub = Subject::_Total;
					cout << "若从高到低排名，请输入1；否则输入2：" << endl;
					while (cin >> ascend, cin.ignore(1024, '\n'), ascend != '1' && ascend != '2')
					{
						cin.clear();
						cout << "请重新输入：" << endl;
					}
				}
				else
				{
					char y;
					cout << "                                                 a.按语文排序" << endl;
					cout << "                                                 b.按数学排序" << endl;
					cout << "                                                 c.按英语排序" << endl;
					cout << "请输入选项：" << endl;
					while (cin >> y, cin.ignore(1024, '\n'), y != 'a' && y != 'b' && y != 'c' && y != 'A' && y != 'B' && y != 'C')
					{
						cin.clear();
						cout << "请重新输入：" << endl;
					}
					if (y == 'a') sub = Subject::_Chinese;
					else if (y == 'b') sub = Subject::_Math;
					else sub = Subject::_English;
					cout << "若从高到低排名，请输入1；否则输入2：" << endl;
					while (cin >> ascend, cin.ignore(1024, '\n'), ascend != '1' && ascend != '2')
					{
						cin.clear();
						cout << "请重新输入：" << endl;
					}
				}
				cout << "请输入保存后的文件名(输入回车则以默认方式保存，便于下次读取)：" << endl;
				if (p = cin.peek() != '\n')
				{
					filename = new char[100];
					cin >> filename;
					cin.ignore(1024, '\n');
					cout << "                                               正在保存......" << endl << endl;
					if (li.Sort(sub, ascend == '2', false, true, filename))
						cout << "                                           " << filename << ".txt保存成功!" << endl;
					else cout << "                                            保存失败!" << endl;
					delete[]filename;
				}
				else
				{
					cin.ignore(1024, '\n');
					cout << "                                               正在保存......" << endl << endl;
					if (li.Sort(sub, ascend == '2', false, true))
						cout << "                                           学生成绩信息.txt保存成功!" << endl;
					else cout << "                                            保存失败!" << endl;
				}
			}
			cout << "是否继续？y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "请重新输入：" << endl << "是否继续？y/n" << endl;
			}
			if (t == 'y' || t == 'Y')
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
	void Read_StuInfo(StudentList& li)override
	{
		system("cls");
		char* filename;
		char p;
		cout << "                                               读取学生信息" << endl;
		while (1)
		{
			cout << "请输入要读取的不带后缀的文件名(输入回车则以默认读取：学生成绩信息.txt)：" << endl;
			if (p = cin.peek() != '\n')
			{
				filename = new char[100];
				cin >> filename;
				cin.ignore(1024, '\n');
				cout << "                                               正在读取......" << endl << endl;
				if (li.Read(filename))
					cout << "                                           " << filename << ".txt读取成功!" << endl;
				else cout << "                                            " << filename << ".txt不存在！读取失败！" << endl;
				delete[]filename;
			}
			else
			{
				cin.ignore(1024, '\n');
				cout << "                                               正在读取......" << endl << endl;
				if (li.Read())
					cout << "                                           学生成绩信息.txt读取成功!" << endl;
				else cout << "                                            学生成绩信息.txt不存在！读取失败！" << endl;
			}
			cout << "是否继续？y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "请重新输入：" << endl << "是否继续？y/n" << endl;
			}
			if (t == 'y' || t == 'Y')
			{
				continue;
			}
			else
			{
				return;
			}
		}
	}
};
class Interface_OnlyRead :public Interface //只读的页面，不可修改其中的数据
{
public:
	void Show_Main(StudentList& li)override
	{
		system("color 0E");
		while (1)
		{
			system("cls");
			char page;
			cout <<
				"                 ===============================学生管理系统====================================" << endl <<
				"                                               1、打印学生信息                                  " << endl <<
				"                                               2、搜索学生                                      " << endl <<
				"                                               3、成绩排名与均分                                  " << endl <<
				"                                               4、保存学生数据                                  " << endl <<
				"                                               5、读取学生数据                                  " << endl <<
				"                                               6、返回                                          " << endl << endl << endl;
			cout << "请输入选项: ";
			while (cin >> page, cin.ignore(1024, '\n'), page > 6 + '0' || page < 1 + '0')
			{
				cout << "请重新输入选项:";
			}
			switch (page)
			{
			case '1': Show_StuInfo(li); break;
			case '2': Search_Stu(li);  break;
			case '3': Sort_Stu(li); break;
			case '4': Save_StuInfo(li); break;
			case '5': Read_StuInfo(li); break;
			case '6': return;
			}
		}
	}
};
void __Start(StudentList& li, BaseFun_Interface* pt)  //开始函数，用于开启学生管理系统
{
	system("color 0E");
	while (1)
	{
		system("cls");
		cout <<
			"                 ===============================学生管理系统====================================" << endl <<
			"                                               1、只读模式                                  " << endl <<
			"                                               2、读写模式                                  " << endl <<
			"                                               3、退出                                      " << endl << endl << endl;
		char page;
		cout << "请输入选项: ";
		while (cin >> page, cin.ignore(1024, '\n'), page > 3 + '0' || page < 1 + '0')
		{
			cout << "请重新输入选项:";
		}
		switch (page)
		{
		case '1': {Interface_OnlyRead in; pt = &in; pt->Show_Main(li); break; }
		case '2': {Interface in; pt = &in; pt->Show_Main(li); break; }
		case '3': return;
		}
	}
}
#endif