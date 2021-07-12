#include<iostream>
#include<cstring>
#include<iomanip>
#pragma warning(disable:4996)
#include"student.h"
#include"interface.h"
using namespace std;

int main()
{
	BaseFun_Interface* pt = NULL;
	StudentList li;
	//测试数据集，取消注释则自动加入到学生成绩管理系统中。
	li.Add(StudentNode("唐昌礼", "1000000000", 147, 128, 137));
	li.Add(StudentNode("黄平",   "1000000001", 147.5, 148, 147));
	li.Add(StudentNode("特朗普", "1000000002", 100, 10, 150));
	li.Add(StudentNode("奥巴马", "1000000003", 107, 121, 107));
	li.Add(StudentNode("邹文明", "1000000004", 150, 148, 97.5));
	li.Add(StudentNode("孙甲松", "1000000005", 127, 132, 102));
	li.Add(StudentNode("公孙离", "1000000006", 107, 123, 87));
	li.Add(StudentNode("小龙女", "1000000007", 97, 126.5, 37));
	li.Add(StudentNode("杨过", "1000000008", 87, 146.5, 137));
	li.Add(StudentNode("皮皮虾", "1000000009", 107, 141.5, 106));
	li.Add(StudentNode("张三丰", "1000000010",131, 100, 112));
	li.Add(StudentNode("盖伦", "1000000011", 131, 100, 122));
	li.Add(StudentNode("戴安娜", "1000000012", 131, 100, 112));
	li.Add(StudentNode("李琦", "1000000013", 131, 100, 162));
	li.Add(StudentNode("邱勇", "1000000014", 131.5, 100, 112));
	li.Add(StudentNode("宋可心", "1000000015", 121, 100, 119));
	li.Add(StudentNode("李逵", "1000000016", 135, 90, 112));
	li.Add(StudentNode("令狐冲", "1000000017", 131, 130, 132));
	li.Add(StudentNode("任盈盈", "1000000018", 131, 100, 112));
	li.Add(StudentNode("岳不群", "1000000019", 11.5, 10.5, 132));
	li.Add(StudentNode("梦婷", "1000000020", 61, 80, 122));
	li.Add(StudentNode("邹鹏列", "1000000021", 131, 100, 116));
	li.Add(StudentNode("德莱文", "1000000022", 131, 100, 117));
	li.Add(StudentNode("普乐安", "1000000023", 131, 109, 116));
	li.Add(StudentNode("德行", "1000000024", 131, 100, 112));
	li.Add(StudentNode("张卫强", "1000000025", 134, 108, 112));
	li.Add(StudentNode("李秋平", "1000000026", 129, 108, 112));
	li.Add(StudentNode("吴川市", "1000000027", 131, 101, 112));
	li.Add(StudentNode("关东升", "1000000028", 132, 90.5, 142));
	li.Add(StudentNode("袁振钊", "1000000029", 131, 100, 112));
	li.Add(StudentNode("李铠峰", "1000000030", 131, 100, 112));
	li.Add(StudentNode("梦琪", "1000000031", 131, 100, 112));
	li.Add(StudentNode("百岁山", "1000000032", 131, 100, 112));
	li.Add(StudentNode("易大师", "1000000033", 131, 100, 112));
	li.Add(StudentNode("秦皇岛", "1000000034", 134, 100, 112));
	li.Add(StudentNode("洛杉矶", "1000000035", 133, 110, 112));
	li.Add(StudentNode("调速器", "1000000036", 131, 120, 82));
	li.Add(StudentNode("窗口", "1000000037", 131, 100, 72));
	li.Add(StudentNode("顾客", "1000000038", 131, 65, 112));
	li.Add(StudentNode("郭凯敏", "1000000039", 13.5, 100, 112));
	li.Add(StudentNode("对偶", "1000000040", 141, 100, 112));
	li.Add(StudentNode("微积分", "1000000041", 121, 100.5, 112));
	li.Add(StudentNode("源文件", "1000000042", 139, 130, 132));
	li.Add(StudentNode("头文件", "1000000043", 132, 150, 112));
	li.Add(StudentNode("韦小宝", "1000000044", 131, 106, 122));
	li.Add(StudentNode("阿珂", "1000000045", 131, 100, 112));
	li.Add(StudentNode("刘海屏", "1000000046", 131, 100, 117));
	li.Add(StudentNode("卢海兵", "1000000047", 138, 107, 119));
	li.Add(StudentNode("关东升", "1000000048", 131, 100, 112));
	li.Add(StudentNode("豆腐脑", "1000000049", 131, 100.5, 112));
	li.Add(StudentNode("菠萝茶", "1000000050", 131, 109, 112));
	li.Add(StudentNode("王春梅", "1000000051", 135, 107, 112));
	li.Add(StudentNode("大梅沙", "1000000052", 138, 100, 142));
	li.Add(StudentNode("秋意", "1000000053", 131, 90, 112));
	li.Add(StudentNode("平儿", "1000000054", 130, 90, 142));
	li.Add(StudentNode("编辑组", "1000000055", 130, 105, 96));
	li.Add(StudentNode("调速器", "1000000056", 131, 100, 92));
	li.Add(StudentNode("张三丰", "1000000057", 130, 110, 112));
	li.Add(StudentNode("及人事", "1000000058", 131, 100, 95));
	li.Add(StudentNode("口水娃", "1000000059", 19, 100, 112));
	li.Add(StudentNode("三门", "1000000060", 131, 100, 112));
	li.Add(StudentNode("三毛", "1000000061", 62, 56, 110));
	li.Add(StudentNode("得票", "1000000062", 136, 90, 72));
	li.Add(StudentNode("张丰三", "1000000063", 131, 100, 112));
	li.Add(StudentNode("五毒教", "1000000064", 134, 150, 119));
	__Start(li, pt);
}