#ifndef API_H
#define API_H
#pragma once
class Student;  //ѧ�����ݴ洢��Ԫ
class StudentNode;  //ѧ�����
class StudentList;  //ѧ������
enum Subject;  //��Ŀö������

//���ԭ�򣺽�ѧ�����ݴ����������ʾ�ֳ��������������ơ�
class BaseFun_Student
{
public:
	//���ѧ����Ϣ��
	virtual bool Add(const StudentNode& s) = 0;
	//ɾ��ѧ����Ϣ������ѧ��������
	virtual bool DeleteByID(const char* id) = 0;
	//����ѧ������ѧ����Ϣ��
	virtual bool SearchByID(const char* id, Student& st) = 0;
	//������������ѧ����Ϣ��ѧ�����ֿ����ظ���Student�����ѵ������һ��ѧ����Print������ʾ�Ƿ�����Ѱ�����д�ӡ�����е�ѧ����Ϣ��
	virtual void SearchByName(const char* name, Student& st, bool Print = false) = 0;
	//����ѧ������ѧ�������޸�ѧ����Ϣ��
	virtual bool ModifyByID(const char* id, double chinese, double math, double english) = 0;
	//��ӡѧ����Ϣ��
	virtual void Display()const = 0;
	//����subѡ�������Ŀ��ascend���������ǽ���print�����Ƿ��ӡ���ݣ�save�����Ƿ񱣴����ݣ�filenameΪ�ļ�����
	virtual bool Sort(Subject sub, bool ascend = false, bool Print = true, bool Save = false, const char* filename = "ѧ���ɼ���Ϣ") = 0;
	//����ѧ����Ϣ��
	virtual bool Save(const char* filename = "ѧ���ɼ���Ϣ") = 0;
	//��ȡѧ����Ϣ��
	virtual bool Read(const char* filename = "ѧ���ɼ���Ϣ") = 0;
	//�����
	virtual double Average(Subject sub) = 0;
	virtual ~BaseFun_Student() {}
};
class BaseFun_Interface  //������صĺ���
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
