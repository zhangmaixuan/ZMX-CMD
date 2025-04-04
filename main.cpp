#include <bits/stdc++.h>
#include <io.h>
#include <stdlib.h>

/*
2025 (C)张麦轩 Copyright

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

using namespace std;
#define MAX_PATH 260
//版本
int version_year=25;
int month_ver=03;
int update=01;
// command -- 命令输入

string command;


//初始化目录
string path="\\";
//文件遍历
vector<string> file;
char buffer[MAX_PATH];//获取当前目录

//涉及函数
void getFiles(string path, vector<string>& files){  
	//文件句柄  
	long hFile=0;  
	//文件信息  
	struct _finddata_t fileinfo;  
	string p;  
	if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1) {  
		do {  
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if((fileinfo.attrib &  _A_SUBDIR)) {  
				//if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)  
				//	getFiles( p.assign(path).append("\\").append(fileinfo.name), files );  
				files.push_back(p.assign(path).append("\\").append(fileinfo.name)+"\t（目录）"); 
			}else  {  
				files.push_back(p.assign(path).append("\\").append(fileinfo.name) );  
			}  
		}while(_findnext(hFile, &fileinfo)  == 0);  
		_findclose(hFile);  
	}  
}

int main(){
	
	getcwd(buffer, MAX_PATH);
	
	cout<<"欢迎来到ZMX-CMD命令行程序"<<version_year<<"年"<<month_ver<<"月"<<"第"<<update<<"次更新"<<endl;
	cout<<"键入‘Help’查看帮助"<<"\n\n";
	
	cout<<path<<">";
	while(getline(cin,command)){
		
		
		int ret_space=command.find(" ");
		string command1=command.substr(0,ret_space);
		
		if(command1=="Help"){
			cout<<"Help查看帮助\nmkdir创建文件夹\ntouch创建文件\nls查看文件";
		}else if(command1=="ls"){
			//获取当前文件路径
			char * filePath = buffer;
			getFiles(filePath, file);  
			//遍历当前文件
			for(int i=0;i<file.size();i++){
				cout<<file[i]<<endl;
			}
			cout<<"\n当前目录总共"<<file.size()<<"个文件或者资料夹\n";
		}else if(command1=="mkdir"){
			string dir_name;
			dir_name=command.substr(ret_space+1,command.size()-1);
			system(("md "+dir_name).c_str());
		}else if(command1=="rm"){
			string rm_file_name;
			rm_file_name=command.substr(ret_space+1,command.size()-1);
			system(("del /f /q /s "+rm_file_name).c_str());
		}
		
		cout<<"\n";
		cout<<path<<">";
	}
	
	//
	return 0;
}
