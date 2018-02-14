#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <set>
using namespace std;
struct student{
	double S;//S:Score
	string name,id,exam_name;
};
student z;
struct cmp_student{
	bool operator()(const student&x,const student&y)const{
		if(x.exam_name<y.exam_name) return 1;
		if(x.exam_name>y.exam_name) return 0;
		if(x.S>y.S) return 1;
		if(x.S<y.S) return 0;
		if(x.id<y.id) return 1;
		if(x.id>y.id) return 0;
		return 0;
	}
};
set<student,cmp_student> stu;
set<student,cmp_student>::iterator it;
int file_input(bool w){
	system("cls");
	unsigned long long int num,i;
	string version;
	ifstream fin;
	fin.open("StudentScore.dat"); 
	if(!fin&&!w){
		MessageBox(NULL,"文件\"StudentScore.dat\"不存在！","学生成绩管理系统",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	if(!fin&&w) return 1; 
	fin>>version>>num;
	if(version!="16.9.18"&&!w){
		cout<<"文件版本与系统不符，无法录入信息！"<<endl;
		cout<<"文件版本："<<version<<endl; 
		MessageBox(NULL,"文件版本与系统不符，无法录入信息！","学生成绩管理系统",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	for(i=1;i<=num;i++){
		fin>>z.exam_name>>z.id>>z.name>>z.S; 
		for(int i=0;i<=z.exam_name.size();i++)
			z.exam_name[i]=z.exam_name[i]-1;
		for(int i=0;i<=z.name.size();i++)
			z.name[i]=z.name[i]-2;
		for(int i=0;i<=z.id.size();i++)
			z.id[i]=z.id[i]-3;
		z.S=z.S-12397;
		stu.insert(z);
	}
	return 0;
} 
int main(){
	int i,j;
	bool f=0;
	string tmp;
	if(file_input(0)) return 0;
	while(1){
		system("cls");
		cout<<"请输入学生姓名/学号/考试名称：";
		cin>>tmp;
		i=1; j=0; f=0;
		for(it=stu.begin();it!=stu.end();it++,i++){
			if(it->name==tmp||it->id==tmp||it->exam_name==tmp){
				system("cls");
				j++;
				cout<<"找到该条件下的第"<<j<<"个信息"<<endl;
				cout<<"姓名："<<it->name<<endl;
				cout<<"学号："<<it->id<<endl;
				cout<<"考试名称："<<it->exam_name<<endl;
				cout<<"成绩："<<it->S<<endl;
				f=1;
				system("pause");
			}
			if(i==stu.size()&&!f){
				cout<<"未找到该条件下的任何信息！"<<endl; 
				system("pause");
			}
			if(i==stu.size()&&f){
				cout<<"完！"<<endl;
				Sleep(1000);
			}
		}
	}
}
	
