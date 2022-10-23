#include"List.h"
#include<string>

bool asc(const string& a, const string& b){
    return a < b;
}

bool desc(const string& a, const string& b){
    return a > b;
}

int main(){
    int n;
    cout<<"Nhap so luong phong khach san: ";
    cin>>n;
    List l(n);
    int choice;
    while(true){
        system("cls");
        cout<<"\t\t\t\t=========Quan ly khach san========="<<endl;
        cout<<"1. Them phong"<<endl;
        cout<<"2. Cap nhat thong tinh phong"<<endl;
        cout<<"3. Xoa phong"<<endl;
        cout<<"4. Tim kiem phong"<<endl;
        cout<<"5. Sap xep phong theo ma phong"<<endl;
        cout<<"6. Hien thi danh sach phong"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        cin>>choice;
        if(choice == 1){
            while(true){
                int c;
                system("cls");
                cout<<"1. Them phong vao dau"<<endl;
                cout<<"2. Them phong vao cuoi"<<endl;
                cout<<"3. Them phong vao vi tri k"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon: ";
                cin>>c;
                if(c==1){
                    PhongKS pks;
                    cout<<"===Nhap thong tin phong muon them==="<<endl;
                    cin>>pks;
                    l.firstAdd(pks);
                    cout<<"Them thanh cong!"<<endl;
                }
                else if(c==2){
                    PhongKS pks;
                    cout<<"===Nhap thong tin phong muon them==="<<endl;
                    cin>>pks;
                    l.lastAdd(pks);
                    cout<<"Them thanh cong!"<<endl;
                }
                else if(c==3){
                    PhongKS pks;
                    cout<<"===Nhap thong tin phong muon them==="<<endl;
                    cin>>pks;
                    cout<<"Nhap vi tri muon them vao: ";
                    int vt;
                    cin>>vt;
                    l.addAt(pks, vt);
                    cout<<"Them thanh cong!"<<endl;
                }
                else if(c==0) break;
                else {
                    cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
                }
                system("pause");
            }
        }
        else if(choice == 2){
            system("cls");
            cout<<"\t\t\t\t=====Cap nhat thong tin phong====="<<endl;
            l.update();
            system("pause");
        }
        else if(choice == 3){
            while (true)
            {
                int c;
                system("cls");
                cout<<"\t\t=====Xoa phong=====";
                cout<<"1. Xoa phong dau tien"<<endl;
                cout<<"2. Xoa phong cuoi cung"<<endl;
                cout<<"3. Xoa phong o vi tri k"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon: ";
                cin>>c;
                if(c==1){
                    l.firstRemove();
                    cout<<"Xoa thanh cong!"<<endl;
                }
                else if(c==2){
                    l.lastRemove();
                    cout<<"Xoa thanh cong!"<<endl;
                }
                else if(c==3){
                    cout<<"Nhap vi tri phong muon xoa: ";
                    int vt;
                    cin>>vt;
                    l.removeAt(vt);
                    cout<<"Xoa thanh cong!"<<endl;
                }
                else if(c==0) break;
                else {
                    cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
                }
                system("pause");
            }   
        }
        else if(choice == 4){
            system("cls");
            cout<<"\t\t\t=====Tim kiem phong======"<<endl;
            l.quick_Sort(0, l.getSoLuongPhong() - 1, asc);
            l.Show();
            cout<<"Nhap ma phong muon tim: ";
            string mp;
            fflush(stdin);
            getline(cin, mp);
            if(l.interpolation_Search(mp) == -1){
                cout<<"Phong khong ton tai!"<<endl;
            }
            else {
                cout<<"Phong "<<mp<<" la phong thu "<<l.interpolation_Search(mp)<<" trong mang!"<<endl;
            }
            system("pause");
        }
        else if(choice == 5){
            while (true)
            {
                system("cls");
                cout<<"\t\t=====Sap xep phong theo ma phong====="<<endl;
                cout<<"1. Sap xep tang dan"<<endl;
                cout<<"2. Sap xep giam dan"<<endl;
                cout<<"0. Thoat"<<endl;
                int c;
                cout<<"Vui long nhap lua chon: ";
                cin>>c;
                if(c == 1){
                    l.quick_Sort(0, l.getSoLuongPhong() - 1, asc);
                    cout<<"Sap xep thanh cong!"<<endl;
                    system("pause");
                    break;
                }
                else if(c == 2){
                    l.quick_Sort(0, l.getSoLuongPhong() - 1, desc);
                    cout<<"Sap xep thanh cong!"<<endl;
                    system("pause");
                    break;
                }
                else if(c == 0){
                    break;
                }
                else{
                    cout<<"Nhap khong hop le, vui long nhap lai"<<endl;
                    system("pause");
                }
            }
            
        }
        else if(choice == 6){
            system("cls");
            cout<<"\t\t\t\t=====Thong tin cac phong====="<<endl;
            l.Show();
            system("pause");
        }
        else if(choice == 0) break;
        else {
            cout<<"Nhap khong hop le, vui long nhat lai!"<<endl;
            system("pause");
        }
    }
    return 0;
}