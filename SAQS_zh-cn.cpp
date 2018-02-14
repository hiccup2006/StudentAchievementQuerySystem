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
		MessageBox(NULL,"�ļ�\"StudentScore.dat\"�����ڣ�","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND);
		return 1;
	}
	if(!fin&&w) return 1; 
	fin>>version>>num;
	if(version!="16.9.18"&&!w){
		cout<<"�ļ��汾��ϵͳ�������޷�¼����Ϣ��"<<endl;
		cout<<"�ļ��汾��"<<version<<endl; 
		MessageBox(NULL,"�ļ��汾��ϵͳ�������޷�¼����Ϣ��","ѧ���ɼ�����ϵͳ",MB_ICONERROR|MB_SYSTEMMODAL|MB_SETFOREGROUND);
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
		cout<<"������ѧ������/ѧ��/�������ƣ�";
		cin>>tmp;
		i=1; j=0; f=0;
		for(it=stu.begin();it!=stu.end();it++,i++){
			if(it->name==tmp||it->id==tmp||it->exam_name==tmp){
				system("cls");
				j++;
				cout<<"�ҵ��������µĵ�"<<j<<"����Ϣ"<<endl;
				cout<<"������"<<it->name<<endl;
				cout<<"ѧ�ţ�"<<it->id<<endl;
				cout<<"�������ƣ�"<<it->exam_name<<endl;
				cout<<"�ɼ���"<<it->S<<endl;
				f=1;
				system("pause");
			}
			if(i==stu.size()&&!f){
				cout<<"δ�ҵ��������µ��κ���Ϣ��"<<endl; 
				system("pause");
			}
			if(i==stu.size()&&f){
				cout<<"�꣡"<<endl;
				Sleep(1000);
			}
		}
	}
}
	
