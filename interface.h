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
class Interface :public BaseFun_Interface  //��дģʽ�����޸����е�����
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
				"                 ===============================ѧ������ϵͳ====================================" << endl <<
				"                                               1����ӡѧ����Ϣ                                  " << endl <<
				"                                               2�����ѧ����Ϣ                                  " << endl <<
				"                                               3��ɾ��ѧ����Ϣ                                  " << endl <<
				"                                               4������ѧ��                                      " << endl <<
				"                                               5���޸�ѧ����Ϣ                                  " << endl <<
				"                                               6���ɼ����������                                  " << endl <<
				"                                               7������ѧ����Ϣ                                  " << endl <<
				"                                               8����ȡѧ����Ϣ                                  " << endl <<
				"                                               9������                                          " << endl << endl << endl;
			cout << "������ѡ��: ";
			while (cin >> page, cin.ignore(1024, '\n'), page > 9 + '0' || page < 1 + '0')
			{
				cout << "����������ѡ��:";
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
		cout << "                     " << "����" << "              " << "ѧ��" <<
			"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
			"      " << "�ܷ�" << endl;
		li.Display();
		cout << endl << endl << endl << "�밴�س������ء�" << endl;
		cin.get();
	}
	void Add_StuInfo(StudentList& li)override
	{
		char* name;
		char* id;
		double math, chinese, english;
		system("cls");
		cout << "                                               ���ѧ����Ϣ" << endl;
		while (1)
		{
			do
			{
				cout << "������ѧ�������� " << endl;
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
					cout << "���ֹ����������Ƿ��������" << endl;
				}
			} while (1);
			do
			{
				cout << "������ѧ��ѧ�ţ� " << endl;
				try
				{
					id = new char[100]; //��ֹ������bug��
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
					cout << "ѧ�Ź��������������룡" << endl;
				}
			} while (1);
			do
			{
				cout << "���������ĳɼ��� " << endl;
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
					cout << "�������ĳɼ�ʧ�ܣ����������룡" << endl;
				}
			} while (1);
			do
			{
				cout << "��������ѧ�ɼ��� " << endl;
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
					cout << "������ѧ�ɼ�ʧ�ܣ����������룡" << endl;
				}
			} while (1);
			do
			{
				cout << "������Ӣ��ɼ��� " << endl;
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
					cout << "����Ӣ��ɼ�ʧ�ܣ����������룡" << endl;
				}
			} while (1);
			if (li.Add(StudentNode(name, id, chinese, math, english)))
				cout << "��ӳɹ���" << endl << "�Ƿ������y/n" << endl;
			else cout << "ѧ���ظ������ʧ�ܣ�" << endl << "�Ƿ������y/n" << endl;
			delete[]name;
			delete[]id;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "���������룺" << endl << "�Ƿ������y/n" << endl;
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
		cout << "                                               ɾ��ѧ����Ϣ" << endl;
		while (1)
		{
			id = new char[100];
			cout << "������Ҫɾ����ѧ��ѧ��: " << endl;
			cin >> id;
			cin.ignore(1024, '\n');
			if (li.DeleteByID(id))
				cout << "ɾ���ɹ���" << endl;
			else cout << "ѧ��Ϊ" << id << "��ѧ�������ڣ�" << endl;
			delete[]id;
			cout << "�Ƿ������y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "���������룺" << endl << "�Ƿ������y/n" << endl;
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
		cout << "                                                 ����ѧ��" << endl;
		while (1)
		{
			cout << "                                               1����ѧ������" << endl <<
				"                                               2������������" << endl;
			cout << "������ѡ�" << endl;
			char a;
			while (cin >> a, cin.ignore(1024, '\n'), a != '1' && a != '2')
			{
				cout << "����������ѡ�" << endl;
			}
			if (a == '1')
			{
				char* id = new char[100];
				cout << "������Ҫ������ѧ��ѧ�ţ�" << endl;
				cin >> id;
				cin.ignore(1024, '\n');
				Student stu;
				if (li.SearchByID(id, stu))
				{
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << endl;
					cout << stu << endl;
				}
				else cout << "ѧ��Ϊ" << id << "��ѧ�������ڣ�" << endl;
				delete[] id;
			}
			else
			{
				char* name = new char[100];
				cout << "������Ҫ������ѧ�������� " << endl;
				cin >> name;
				cin.ignore(1024, '\n');
				cout << endl;
				Student stu;
				li.SearchByName(name, stu, true);
				delete[]name;
			}
			cout << "�Ƿ������y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "���������룺" << endl << "�Ƿ������y/n" << endl;
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
		cout << "                                               �޸�ѧ����Ϣ" << endl;
		char* id;
		double math, chinese, english;
		while (1)
		{
			do
			{
				cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << endl;
				try
				{
					id = new char[100]; //��ֹ������bug��
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
					cout << "ѧ�Ź��������������룡" << endl;
				}
			} while (1);
			do
			{
				cout << "�������޸ĺ�����ĳɼ��� " << endl;
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
					cout << "�������ĳɼ�ʧ�ܣ����������룡" << endl;
				}
			} while (1);
			do
			{
				cout << "�������޸ĺ����ѧ�ɼ��� " << endl;
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
					cout << "������ѧ�ɼ�ʧ�ܣ����������룡" << endl;
				}
			} while (1);
			do
			{
				cout << "�������޸ĺ��Ӣ��ɼ��� " << endl;
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
					cout << "����Ӣ��ɼ�ʧ�ܣ����������룡" << endl;
				}
			} while (1);
			if (li.ModifyByID(id, chinese, math, english)) cout << "�޸ĳɹ�!" << endl;
			else cout << "ѧ��Ϊ" << id << "��ѧ�������ڣ�" << endl;
			delete[]id;
			cout << "�Ƿ������y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "���������룺" << endl << "�Ƿ������y/n" << endl;
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
		cout << "                                                 �ɼ�����" << endl;
		while (1)
		{
			cout << "                                               1�����ܷ�����" << endl;
			cout << "                                               2������Ŀ����" << endl;
			cout << "                                               3����ƽ����" << endl;
			cout << "������ѡ�" << endl;
			while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2' && x != '3')
			{
				cin.clear();
				cout << "����������ѡ�" << endl;
			}
			if (x == '1')
			{
				cout << "���Ӹߵ���������������1����������2��" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2')
				{
					cin.clear();
					cout << "���������룺" << endl;
				}
				if (x == '1')
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        �ܷ�����" << endl;
					li.Sort(Subject::_Total);
				}
				else
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        �ܷ�����" << endl;
					li.Sort(Subject::_Total, true);
				}
			}
			else if (x == '2')
			{
				char y;
				cout << "                                                 a.����������" << endl;
				cout << "                                                 b.����ѧ����" << endl;
				cout << "                                                 c.��Ӣ������" << endl;
				cout << "������ѡ�" << endl;
				while (cin >> y, cin.ignore(1024, '\n'), y != 'a' && y != 'b' && y != 'c' && y != 'A' && y != 'B' && y != 'C')
				{
					cin.clear();
					cout << "���������룺" << endl;
				}
				cout << "���Ӹߵ���������������1����������2��" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2')
				{
					cin.clear();
					cin.ignore(1024, '\n');
					cout << "���������룺" << endl;
				}
				if (x == '1' && (y == 'a' || y == 'A'))
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        ��������" << endl;
					li.Sort(Subject::_Chinese);
				}
				else if (x == '2' && (y == 'a' || y == 'A'))
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        ��������" << endl;
					li.Sort(Subject::_Chinese, true);
				}
				else if (x == '1' && (y == 'b' || y == 'B'))
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        ��ѧ����" << endl;
					li.Sort(Subject::_Math);
				}
				else if (x == '2' && (y == 'b' || y == 'B'))
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        ��ѧ����" << endl;
					li.Sort(Subject::_Math, true);
				}
				else if (x == '1' && (y == 'c' || y == 'C'))
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        Ӣ������" << endl;
					li.Sort(Subject::_English);
				}
				else if (x == '2' && (y == 'c' || y == 'C'))
				{
					cout << endl;
					cout << "                     " << "����" << "              " << "ѧ��" <<
						"        " << "����" << "      " << "��ѧ" << "      " << "Ӣ��" <<
						"      " << "�ܷ�" << "        Ӣ������" << endl;
					li.Sort(Subject::_English, true);
				}
			}
			else
			{
				cout << "                                                 a.�����ľ���" << endl;
				cout << "                                                 b.����ѧ����" << endl;
				cout << "                                                 c.��Ӣ�����" << endl;
				cout << "                                                 d.���ܷ־���" << endl;
				cout << "������ѡ�" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != 'a' && x != 'b' && x != 'c' && x != 'd' && x != 'A' && x != 'B' && x != 'C' && x != 'D')
				{
					cin.clear();
					cout << "����������ѡ�" << endl;
				}
				Subject sub; char str[15];
				if (x == 'a' || x == 'A')strcpy(str, "���ľ��֣�"), sub = Subject::_Chinese;
				else if (x == 'b' || x == 'B')strcpy(str, "��ѧ���֣�"), sub = Subject::_Math;
				else if (x == 'c' || x == 'C')strcpy(str, "Ӣ����֣�"), sub = Subject::_English;
				else strcpy(str, "�ܷ־��֣�"), sub = Subject::_Total;
				double grade = li.Average(sub);
				cout << "                                                 " << str << grade << endl;
			}
			cout << "�Ƿ������y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "���������룺" << endl << "�Ƿ������y/n" << endl;
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
		cout << "                                               ����ѧ����Ϣ" << endl;
		while (1)
		{
			cout << "                                               1��ֱ�ӱ���" << endl;
			cout << "                                               2�������󱣴�" << endl;
			cout << "������ѡ�" << endl;
			while (cin >> p, cin.ignore(1024, '\n'), p != '1' && p != '2')
			{
				cout << "����������ѡ�" << endl;
			}
			if (p == '1')
			{
				cout << "�����뱣�����ļ���(����س�����Ĭ�Ϸ�ʽ���棬�����´ζ�ȡ)��" << endl;
				if (p = cin.peek() != '\n')
				{
					filename = new char[100];
					cin >> filename;
					cin.ignore(1024, '\n');
					cout << "                                               ���ڱ���......" << endl << endl;
					if (li.Save(filename))
						cout << "                                           " << filename << ".txt����ɹ�!" << endl;
					else cout << "                                            ����ʧ��!" << endl;
					delete[]filename;
				}
				else
				{
					cin.ignore(1024, '\n');
					cout << "                                               ���ڱ���......" << endl << endl;
					if (li.Save())
						cout << "                                           ѧ���ɼ���Ϣ.txt����ɹ�!" << endl;
					else cout << "                                            ����ʧ��!" << endl;
				}
			}
			else
			{
				char x;
				char ascend;
				Subject sub;
				cout << "                                               1�����ܷ�����" << endl;
				cout << "                                               2������Ŀ����" << endl << endl << endl;
				cout << "������ѡ�" << endl;
				while (cin >> x, cin.ignore(1024, '\n'), x != '1' && x != '2')
				{
					cin.clear();
					cout << "����������ѡ�" << endl;
				}
				if (x == '1')
				{
					sub = Subject::_Total;
					cout << "���Ӹߵ���������������1����������2��" << endl;
					while (cin >> ascend, cin.ignore(1024, '\n'), ascend != '1' && ascend != '2')
					{
						cin.clear();
						cout << "���������룺" << endl;
					}
				}
				else
				{
					char y;
					cout << "                                                 a.����������" << endl;
					cout << "                                                 b.����ѧ����" << endl;
					cout << "                                                 c.��Ӣ������" << endl;
					cout << "������ѡ�" << endl;
					while (cin >> y, cin.ignore(1024, '\n'), y != 'a' && y != 'b' && y != 'c' && y != 'A' && y != 'B' && y != 'C')
					{
						cin.clear();
						cout << "���������룺" << endl;
					}
					if (y == 'a') sub = Subject::_Chinese;
					else if (y == 'b') sub = Subject::_Math;
					else sub = Subject::_English;
					cout << "���Ӹߵ���������������1����������2��" << endl;
					while (cin >> ascend, cin.ignore(1024, '\n'), ascend != '1' && ascend != '2')
					{
						cin.clear();
						cout << "���������룺" << endl;
					}
				}
				cout << "�����뱣�����ļ���(����س�����Ĭ�Ϸ�ʽ���棬�����´ζ�ȡ)��" << endl;
				if (p = cin.peek() != '\n')
				{
					filename = new char[100];
					cin >> filename;
					cin.ignore(1024, '\n');
					cout << "                                               ���ڱ���......" << endl << endl;
					if (li.Sort(sub, ascend == '2', false, true, filename))
						cout << "                                           " << filename << ".txt����ɹ�!" << endl;
					else cout << "                                            ����ʧ��!" << endl;
					delete[]filename;
				}
				else
				{
					cin.ignore(1024, '\n');
					cout << "                                               ���ڱ���......" << endl << endl;
					if (li.Sort(sub, ascend == '2', false, true))
						cout << "                                           ѧ���ɼ���Ϣ.txt����ɹ�!" << endl;
					else cout << "                                            ����ʧ��!" << endl;
				}
			}
			cout << "�Ƿ������y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "���������룺" << endl << "�Ƿ������y/n" << endl;
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
		cout << "                                               ��ȡѧ����Ϣ" << endl;
		while (1)
		{
			cout << "������Ҫ��ȡ�Ĳ�����׺���ļ���(����س�����Ĭ�϶�ȡ��ѧ���ɼ���Ϣ.txt)��" << endl;
			if (p = cin.peek() != '\n')
			{
				filename = new char[100];
				cin >> filename;
				cin.ignore(1024, '\n');
				cout << "                                               ���ڶ�ȡ......" << endl << endl;
				if (li.Read(filename))
					cout << "                                           " << filename << ".txt��ȡ�ɹ�!" << endl;
				else cout << "                                            " << filename << ".txt�����ڣ���ȡʧ�ܣ�" << endl;
				delete[]filename;
			}
			else
			{
				cin.ignore(1024, '\n');
				cout << "                                               ���ڶ�ȡ......" << endl << endl;
				if (li.Read())
					cout << "                                           ѧ���ɼ���Ϣ.txt��ȡ�ɹ�!" << endl;
				else cout << "                                            ѧ���ɼ���Ϣ.txt�����ڣ���ȡʧ�ܣ�" << endl;
			}
			cout << "�Ƿ������y/n" << endl;
			char t;
			while (cin >> t, cin.ignore(1024, '\n'), t != 'y' && t != 'Y' && t != 'n' && t != 'N')
			{
				cin.clear();
				cout << "���������룺" << endl << "�Ƿ������y/n" << endl;
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
class Interface_OnlyRead :public Interface //ֻ����ҳ�棬�����޸����е�����
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
				"                 ===============================ѧ������ϵͳ====================================" << endl <<
				"                                               1����ӡѧ����Ϣ                                  " << endl <<
				"                                               2������ѧ��                                      " << endl <<
				"                                               3���ɼ����������                                  " << endl <<
				"                                               4������ѧ������                                  " << endl <<
				"                                               5����ȡѧ������                                  " << endl <<
				"                                               6������                                          " << endl << endl << endl;
			cout << "������ѡ��: ";
			while (cin >> page, cin.ignore(1024, '\n'), page > 6 + '0' || page < 1 + '0')
			{
				cout << "����������ѡ��:";
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
void __Start(StudentList& li, BaseFun_Interface* pt)  //��ʼ���������ڿ���ѧ������ϵͳ
{
	system("color 0E");
	while (1)
	{
		system("cls");
		cout <<
			"                 ===============================ѧ������ϵͳ====================================" << endl <<
			"                                               1��ֻ��ģʽ                                  " << endl <<
			"                                               2����дģʽ                                  " << endl <<
			"                                               3���˳�                                      " << endl << endl << endl;
		char page;
		cout << "������ѡ��: ";
		while (cin >> page, cin.ignore(1024, '\n'), page > 3 + '0' || page < 1 + '0')
		{
			cout << "����������ѡ��:";
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