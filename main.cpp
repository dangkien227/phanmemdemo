/*
	Phonebook program
	hoten : nguyen dang kien
	lop : 59k1-cntt
	gvhd : Le Van Minh
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;
class danhba{
	private:
		string name;
		string phone;
	public:
		danhba(){
		}
		danhba(string ten,string sdt){
			name= ten;
			phone = sdt;
		}
		void nhap(){
			cout<<"Nhap ten: ";cin.ignore();getline(cin,name);
			cout<<"Nhap so dien thoai: ";cin>>phone;
		}
		void xuat(){
			cout<<"Ten : "<<name <<"\tSDT : "<<phone<<endl;
		}
		string getname(){
			return name;
		}
		string getphone(){
			return phone;
		}
		void setname(string name){
			this->name=name;
		}
		void setphone(string phone){
			this->phone=phone;
		}
		
};
class qldb{
	private:
		int soluong;
		danhba db[100];
	public:
		qldb(){
		}
		qldb(int n,danhba aa[]){
			soluong =n;
			for(int i=0;i<n;i++){
				db[i]=aa[i];
			}
		}
		void nhap(){
			cout<<"Nhap so luong danh ba can quan ly : ";cin>>soluong;
			for(int i=0;i<soluong;i++){
				db[i].nhap();
			}
		}
		void xuat(){
			for(int i=0;i<soluong;i++){
				db[i].xuat();
			}
		}
		//nhap du lieu bang file
		void infile(){
			ifstream in("data.txt",ios::in);
			in>>soluong;
			char name[15],phone[11];
			char ss[5];
			in.getline(ss,3);
			for(int i=0; i<soluong;i++){
				in.getline(name,30);
				in.getline(phone,11);
				db[i].setname(name);
				db[i].setphone(phone);
			}
			in.close();
		}
		//xuat du lieu ra file
		void outfile(){
			ofstream out("data.txt",ios::out);
			out<<soluong<<endl;
			for(int i=0;i<soluong;i++){
				out<<db[i].getname()<<endl;
				out<<db[i].getphone()<<endl;	
			}
			out.close();
		}
		//tim kiem
		void find(string ns){
			int temp = 0;
			for(int i=0;i<soluong;i++){
				if(db[i].getname()==ns){
					db[i].xuat();
					temp = 1;
				}
				if(db[i].getphone()==ns){
					db[i].xuat();
					temp = 1;
				}
			}
			if (temp==0){
				cout << "khong ton tai danh ba!" << endl;
			}
		}
		//them moi
		void insert(){
			soluong++;
			db[soluong-1].nhap();
		}
		//sua
		void update(string ns){
			for(int i=0;i<soluong;i++){
				if(db[i].getname()==ns){
					db[i].xuat();
					cout<<"moi sua : "<<endl;
					db[i].nhap();
				}
				if(db[i].getphone()==ns){
					db[i].xuat();
					cout<<"moi sua : "<<endl;
					db[i].nhap();
				}
			}
		}
		//xoa
		void del(string ns){
			int temp=0;
			for(int i=0;i<soluong;i++){
				if(db[i].getname()==ns){
					temp=i;
				}
				if(db[i].getphone()==ns){
					temp=i;
				}
			}
			if(temp!=0){
				for(int i =temp;i<soluong;i++){
					for(int j =i+1;j<soluong;j++){
						db[i]=db[j];
					}
				}
				cout<<"Xoa thanh cong!"<<endl;
				soluong--;
			}
			else 
				cout<<"Khong tim thay ten hoac so dien thoai"<< endl ;
		}
};
void menu(){
	cout<<"+------------------>>> MENU <<<------------------+"<<endl;
	cout<<"|"<<setw(49)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"1"<<setw(27)<<"NHAP FILE TEXT"<<setw(10)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"2"<<setw(29)<<"NHAP TU BAN PHIM"<<setw(8)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"3"<<setw(27)<<"XUAT FILE TEXT"<<setw(10)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"4"<<setw(29)<<"HIEN THI DANH BA"<<setw(8)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"5"<<setw(24)<<"TIM DANH BA"<<setw(13)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"6"<<setw(25)<<"THEM DANH BA"<<setw(12)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"7"<<setw(24)<<"SUA DANH BA"<<setw(13)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"8"<<setw(24)<<"XOA DANH BA"<<setw(13)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"9"<<setw(24)<<"abc"<<setw(13)<<"|"<<endl;
	cout<<"|"<<setw(49)<<"|"<<endl;
	cout<<"|"<<setw(12)<<"0"<<setw(24)<<"THOAT CT !!"<<setw(13)<<"|"<<endl;
	cout<<"|"<<setw(49)<<"|"<<endl;
	cout<<"+------------------>>> ---- <<<------------------+"<<endl;
}


int main(){
	qldb db;
	while(true){
		menu();
		int menu;
		cout<<"Moi chon MENU : ";cin>>menu;
		system("cls");
		cout<<"\n===================>>> ---- <<<==================="<<endl<<endl;
		string ns;
		switch(menu){
			case 1:
				db.infile();
				cout<<"Nhap du lieu tu FILE thanh cong !!!";
				break;
			case 2:
				db.nhap();
				cout<<"Nhap du lieu tu BAN PHIM thanh cong !!!";
				break;
			case 3:
				db.outfile();
				cout<<"Xuat du lieu ra FILE thanh cong !!!";
				break;
			case 4:
				db.xuat();
				cout<<"\nXuat du lieu ra man hinh done !!!";
				break;
			case 5:
				cout<<"Nhap TEN hoac SDT can TIM : ";
				cin.ignore();getline(cin,ns);
				db.find(ns);
				cout<<"Tim du lieu thanh cong !!!";
				break;
			case 6:
				db.insert();
				db.outfile();
				cout<<"Them du lieu thanh cong !!!";
				break;
			case 7:
				cout<<"Nhap TEN hoac SDT can SUA : ";
				cin.ignore();getline(cin,ns);
				db.update(ns);
				db.outfile();
				cout<<"Sua du lieu thanh cong !!!";
				break;
			case 8:
				cout<<"Nhap TEN hoac SDT can XOA : ";
				cin.ignore();getline(cin,ns);
				db.del(ns);
				db.outfile();
				cout<<"Xoa du lieu thanh cong !!!";
				break;
		}
		cout<<"\n\n===================>>> ---- <<<==================="<<endl;
		if(menu==0||menu!=1&&menu!=2&&menu!=3&&menu!=4&&menu!=5&&menu!=6&&menu!=7&&menu!=8)
			break;
	}
	

return 0;
}

