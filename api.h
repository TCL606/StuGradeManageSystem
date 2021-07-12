#ifndef API_H
#define API_H
#pragma once
class Student;  //学生数据存储单元
class StudentNode;  //学生结点
class StudentList;  //学生链表
enum Subject;  //科目枚举类型

//设计原则：将学生数据储存与界面显示分成两个大类进行设计。
class BaseFun_Student
{
public:
	//添加学生信息。
	virtual bool Add(const StudentNode& s) = 0;
	//删除学生信息，根据学号搜索。
	virtual bool DeleteByID(const char* id) = 0;
	//根据学号搜索学生信息。
	virtual bool SearchByID(const char* id, Student& st) = 0;
	//根据姓名搜索学生信息。学生名字可能重复，Student传回搜到的最后一个学生，Print参数表示是否在搜寻过程中打印出所有的学生信息。
	virtual void SearchByName(const char* name, Student& st, bool Print = false) = 0;
	//根据学号搜索学生，并修改学生信息。
	virtual bool ModifyByID(const char* id, double chinese, double math, double english) = 0;
	//打印学生信息。
	virtual void Display()const = 0;
	//排序：sub选择排序科目，ascend决定升序还是降序，print代表是否打印数据，save代表是否保存数据，filename为文件名。
	virtual bool Sort(Subject sub, bool ascend = false, bool Print = true, bool Save = false, const char* filename = "学生成绩信息") = 0;
	//保存学生信息。
	virtual bool Save(const char* filename = "学生成绩信息") = 0;
	//读取学生信息。
	virtual bool Read(const char* filename = "学生成绩信息") = 0;
	//求均分
	virtual double Average(Subject sub) = 0;
	virtual ~BaseFun_Student() {}
};
class BaseFun_Interface  //界面相关的函数
{
public:  
	virtual void Show_Main(StudentList& li) = 0;
	virtual void Show_StuInfo(const StudentList& li) = 0;
	virtual void Add_StuInfo(StudentList& li) = 0;
	virtual void Delete_StuInfo(StudentList& li) = 0;
	virtual void Search_Stu(StudentList& li) = 0;
	virtual void Modify_Stu(StudentList& li) = 0;
	virtual void Sort_Stu(StudentList& li) = 0;
	virtual void Save_StuInfo(StudentList& li) = 0;
	virtual void Read_StuInfo(StudentList& li) = 0;
};
#endif 
