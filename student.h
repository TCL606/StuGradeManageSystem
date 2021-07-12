#ifndef STUDENT_H
#define STUDENT_H
#pragma once
#include<iostream>
#include<cstring>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include"api.h"
#pragma warning(disable:4996)
#define ID_Length 10  //学号最长的长度。
using namespace std;
class StudentNode;
class StudentList;
class Compare;
class Student
{
	friend class StudentNode;
	friend class StudentList;
	friend class Compare;
	friend class vector<Student>;
public:
	Student(const char* str = "NULL", const char* id = "0", double Chinese = 0, double Math = 0, double English = 0) :Chinese(Chinese), Math(Math), English(English)
	{
		Name = new char[strlen(str) + 1];
		strcpy(Name, str);
		ID = new char[strlen(id) + 1];
		strcpy(ID, id);
		Total = Math + Chinese + English;
	}
	Student(const Student& stu) :Math(stu.Math), Chinese(stu.Chinese), English(stu.English), Total(stu.Total)
	{
		Name = new char[strlen(stu.Name) + 1];
		strcpy(Name, stu.Name);
		ID = new char[strlen(stu.ID) + 1];
		strcpy(ID, stu.ID);
	}
	void Modify(double chinese = 0, double math = 0, double english = 0) //修改成绩
	{
		this->Chinese = chinese; this->Math = math; this->English = english;
		this->Total = math + chinese + english;
	}
	~Student()
	{
		delete[]Name;
		delete[]ID;
	}
	friend ostream& operator << (ostream& output, const Student& st)
	{
		output << "                     " << setw(10) << setiosflags(ios_base::left) << st.Name << "     " <<
			setw(10) << setiosflags(ios_base::left) << st.ID << "     " <<
			setw(5) << st.Chinese << "     " <<
			setw(5) << st.Math << "     " <<
			setw(5) << st.English << "     " <<
			setw(5) << st.Total;
		return output;
	}
	friend ofstream& operator << (ofstream& output, const Student& st)
	{//改用width是因为文件的宽度和cout的宽度可能不一致，不能直接复制ostream的<<函数。
	 //但是还是对不齐，我也不知道为什么。。。
		output << "                     ";
		output.width(10);
		output << setiosflags(ios_base::left) << st.Name << "     ";
		output.width(2 * ID_Length);
		output << setiosflags(ios_base::left) << st.ID << "     ";
		output.width(10);
		output << st.Chinese << "     ";
		output.width(10);
		output << st.Math << "     ";
		output.width(10);
		output << st.English << "     ";
		output.width(10);
		output << st.Total;
		return output;
	}
	Student& operator =(const Student& st)
	{
		Math = st.Math; Chinese = st.Chinese; English = st.English; Total = st.Total;
		char* newname = new char[strlen(st.Name) + 1];
		strcpy(newname, st.Name);
		delete[]Name;
		Name = newname;
		char* newid = new char[ID_Length + 1];
		strcpy(newid, st.ID);
		delete[]ID;
		ID = newid;
		return *this;
	}
protected:
	char* Name;
	char* ID;
	double Chinese;
	double Math;
	double English;
	double Total;
};

class StudentNode
{
	friend class StudentList;
public:
	StudentNode(const char* str = "NULL", const char* Id = "0", double c = 0, double m = 0, double e = 0, StudentNode* next = NULL) :stu(str, Id, c, m, e), next(next) {}
protected:
	StudentNode* next;
	Student stu;
};
enum Subject
{
	_Math, _Chinese, _English, _Total
};
class Compare //成绩比较的仿函数类
{
public:
	static bool CompareBy_Math(const Student& s1, const Student& s2) { return s1.Math > s2.Math; }
	static bool CompareBy_Chinese(const Student& s1, const Student& s2) { return s1.Chinese > s2.Chinese; }
	static bool CompareBy_English(const Student& s1, const Student& s2) { return s1.English > s2.English; }
	static bool CompareBy_Total(const Student& s1, const Student& s2) { return s1.Total > s2.Total; }
};
class AddedFun_Student //可能会新增api，先写一个类放在这做准备
{
public:
	bool SaveStuVector(Subject sub, vector<Student>& stu, bool ascend = false, const char* filename = "学生成绩信息")
	{
		string file(filename);
		file = ".\\" + file; file += ".txt";
		ofstream of(file, ios_base::out);
		of << "                     " << "姓名" << "                  " << "学号" <<
			"                      " << "语文" << "            " << "数学" << "           "
			<< "英语" << "           " << "总分";
		if (sub == Subject::_Total) of << "           " << "总分排名";
		else if (sub == Subject::_Chinese) of << "           " << "语文排名";
		else if (sub == Subject::_Math) of << "           " << "数学排名";
		else if (sub == Subject::_English) of << "           " << "英语排名";
		of << endl;
		of.flush();
		if (!ascend)
		{
			vector<Student>::iterator it = stu.begin();
			int i = 1;
			while (it != stu.end())
			{
				of << *it << "            " << i++ << endl;
				of.flush();
				if (of.fail())
				{
					of.clear();
					of.close();
					return 0;
				}
				it++;
			}
		}
		else
		{
			vector<Student>::iterator it = stu.end();
			int i = stu.size();
			while (it != stu.begin())
			{
				it--;
				of << *it << "            " << i-- << endl;
				of.flush();
				if (of.fail())
				{
					of.clear();
					of.close();
					return 0;
				}
			}
		}
		of.close();
		return 1;
	}
};
class StudentList :public BaseFun_Student, public AddedFun_Student
{
public:
	virtual bool Add(const StudentNode& s)override
	{
		Student stest;
		if (SearchByID(s.stu.ID, stest))  //ID唯一，重复则报错
		{	//输出信息应放在interface中去调用。
			//cout << "ID为" << s.stu.ID << "的学生已经存在!" << endl;
			return false;
		}
		StudentNode* newnode = new StudentNode(s);
		if (first == NULL)
		{
			newnode->next = first;
			first = current = newnode;
		}
		else
		{
			newnode->next = current->next;
			current = current->next = newnode;
		}
		StudentNum++;
		return true;
	}
	virtual bool DeleteByID(const char* id)override
	{
		StudentNode st;
		StudentNode* p = current; current = first;
		if (current == NULL)
		{
			current = p; //保持current在末尾
			return false;
		}
		else
		{
			if (!strcmp(id, first->stu.ID)) //考虑删除第一个指针的特殊情况
			{
				StudentNode* q = first;
				first = q->next;
				delete q;
				StudentNum--;
				current = p; //保持current在末尾
				return true;
			}
			else while (strcmp(id, current->next->stu.ID))
			{
				if (current->next->next == NULL)
				{
					current = p; //保持current在末尾
					return false;
				}
				current = current->next;
			}
		}
		StudentNode* q = current->next;
		current->next = q->next;
		delete q;
		StudentNum--;
		current = p; //保持current在末尾
		return true;
	}
	virtual bool SearchByID(const char* id, Student& st)override //id是唯一的
	{
		StudentNode* p = current; current = first;
		if (current == NULL)
		{
			current = p; //保持current在末尾
			return 0;
		}
		else
		{
			while (strcmp(id, current->stu.ID))
			{
				if (current->next == NULL)
				{
					current = p; //保持current在末尾
					return 0;
				}
				current = current->next;
			}
		}
		st = current->stu;
		current = p; //保持current在末尾
		return 1;
	}
	virtual void SearchByName(const char* name, Student& st, bool Print = false)override //学生名字可能重复
	{
		int n = 0;
		bool search = false; //搜到了吗？
		StudentNode* p = current; current = first;
		if (Print)
			cout << "                     " << "姓名" << "              " << "学号" <<
			"        " << "语文" << "      " << "数学" << "      " << "英语" <<
			"      " << "总分" << endl;
		while (current != NULL)
		{
			if (!strcmp(name, current->stu.Name))
			{
				st = current->stu;
				if (Print)
				{
					cout << st << endl;
					search = true;
				}
			}
			current = current->next;
		}
		current = p; //保持current在末尾
		if (Print && !search)
			cout << "                                             没有姓名为" << name << "的学生！" << endl;
	}
	virtual bool ModifyByID(const char* id, double chinese, double math, double english)override
	{
		StudentNode* p = current; current = first;
		if (current == NULL)
		{
			current = p; //保持current在末尾
			return 0;
		}
		else
		{
			while (strcmp(id, current->stu.ID))
			{
				if (current->next == NULL)
				{
					current = p; //保持current在末尾
					return 0;
				}
				current = current->next;
			}
		}
		current->stu.Modify(chinese, math, english);
		current = p; //保持current在末尾
		return 1;
	}
	virtual void Display()const override
	{
		StudentNode* p = first;
		while (p)
		{
			cout << p->stu << endl;
			p = p->next;
		}
		cout << endl;
	}
	virtual bool Sort(Subject sub, bool ascend = false, bool Print = true, bool save = false, const char* filename = "学生成绩信息")override
	{
		vector<Student> st;
		StudentNode* p = first;
		StudentNode* q = first;
		while (p)
		{
			st.push_back(p->stu);
			p = p->next;
		}
		if (sub == _Math)
			sort(st.begin(), st.end(), Compare::CompareBy_Math);
		else if (sub == _Chinese)
			sort(st.begin(), st.end(), Compare::CompareBy_Chinese);
		else if (sub == _English)
			sort(st.begin(), st.end(), Compare::CompareBy_English);
		else
			sort(st.begin(), st.end(), Compare::CompareBy_Total);
		if (Print == true)
		{
			for (uint32_t i = 0; i < st.size(); i++)
				if (ascend)
					cout << st[StudentNum - 1 - i] << "          " << StudentNum - i << endl;
				else cout << st[i] << "          " << i + 1 << endl;
		}
		if (save)
		{
			return SaveStuVector(sub, st, ascend, filename);
		}
		return 1;
	}
	virtual bool Save(const char* filename = "学生成绩信息")override
	{
		string file(filename);
		file = ".\\" + file; file += ".txt";
		ofstream of(file, ios_base::out);
		StudentNode* p = first;
		of << "                     " << "姓名" << "                  " << "学号" <<
			"                      " << "语文" << "            " << "数学" << "           "
			<< "英语" << "           " << "总分" << endl;
		of.flush();
		while (p)
		{
			of << p->stu << endl;
			of.flush();
			if (of.fail())
			{
				of.clear();
				of.close();
				return 0;
			}
			p = p->next;
		}
		of.close();
		return 1;
	}
	virtual bool Read(const char* filename = "学生成绩信息")override
	{
		string file(filename);
		file = ".\\" + file; file += ".txt";
		ifstream in;
		in.open(file, ios_base::in | ios_base::_Nocreate);
		char* _name, * _id;
		double _chinese, _math, _english;
		if (in.fail())
		{
			in.clear();
			in.close();
			return 0;
		}
		else
		{
			in.ignore(1024, '\n');
			do {
				_name = new char[100];
				in >> _name;
				_id = new char[100];
				in >> _id;
				in >> _chinese;
				in >> _math;
				in >> _english;
				if (in.fail())
				{
					delete[]_name;
					delete[]_id;
					break;
				}
				Add(StudentNode(_name, _id, _chinese, _math, _english));
				delete[]_name;
				delete[]_id;
				in.ignore(1024, '\n');
			} while (1);
		}
		in.clear();
		in.close();
		return 1;
	}
	virtual double Average(Subject sub)override
	{
		StudentNode* p = first;
		double grade = 0;
		if (sub == Subject::_Chinese)
			while (p)
			{
				grade += p->stu.Chinese;
				p = p->next;
			}
		else if (sub == Subject::_Math)
			while (p)
			{
				grade += p->stu.Math;
				p = p->next;
			}
		else if (sub == Subject::_English)
			while (p)
			{
				grade += p->stu.English;
				p = p->next;
			}
		else
			while (p)
			{
				grade += p->stu.Total;
				p = p->next;
			}
		if (StudentNum == 0) return -1;
		return grade / StudentNum;
	}
	StudentList() { current = first = NULL; StudentNum = 0; }
	virtual ~StudentList()
	{
		StudentNode* p = first;
		StudentNode* q = p;
		while (q)
		{
			q = p->next;
			delete p;
			StudentNum--;
			p = q;
		}
	}
protected:
	StudentNode* first;
	StudentNode* current;
	int StudentNum;
};
#endif