#include"PhongKS.h"
#include<string>
#include<iomanip>

PhongKS::PhongKS(){
    this->maPhong = "";
    this->soNguoiToiDa = 0;
    this->tinhTrang = true;
}

PhongKS::~PhongKS(){
}

istream& operator>>(istream& i, PhongKS& pKS){
    do{
        cout<<"Ma phong: ";
        fflush(stdin);
        getline(i, pKS.maPhong);
        cout<<"So nguoi toi da (khong qua 4 nguoi): ";
        i>>pKS.soNguoiToiDa;
        cout<<"Tinh trang (1 - Phong trong; 0 - Phong da co nguoi): ";
        int tt;
        i>>tt;
        if(tt==1) {
            pKS.tinhTrang = true;
        }
        if(tt==0)
        {
            pKS.tinhTrang = false;
            cout<<"Ngay nhan phong: ";
            i>>pKS.ngayNhanPhong;
            cout<<"Ngay tra phong: ";
            i>>pKS.ngayTraPhong;
        }
        cout<<"Gia phong: ";
        i>>pKS.giaPhong;
        if(pKS.maPhong[0] - 48 <= 4 && pKS.maPhong[0] - 48 > 0 && pKS.soNguoiToiDa <= 4 && pKS.maPhong.length() == 5) 
            break;
        else
            system("cls");
            cout<<"Nhap thong tin phong khong hop le, xin vui long nhap lai!"<<endl;
    }
    while(true);
    return i;
}

ostream& operator<<(ostream& o, const PhongKS &pKS){
    o<<left<<setw(15)<<pKS.maPhong;
    o<<left<<setw(20)<<pKS.soNguoiToiDa;
    if(pKS.tinhTrang){
        o<<left<<setw(20)<<"Phong trong";
        o<<left<<setw(20)<<"NULL"<<left<<setw(20)<<"NULL";
    }
    else {
        o<<left<<setw(20)<<"Phong da co nguoi";
        o<<left<<setw(20)<<pKS.ngayNhanPhong;
        o<<left<<setw(20)<<pKS.ngayTraPhong;
    }
    o<<right<<setw(10)<<setprecision(0)<<fixed<<pKS.giaPhong;
    return o;
}
