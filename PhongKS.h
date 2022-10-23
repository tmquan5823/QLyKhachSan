#include"Date.h"

class PhongKS{
    private: 
        string maPhong;
        int soNguoiToiDa;
        bool tinhTrang;
        Date ngayNhanPhong;
        Date ngayTraPhong;
        double giaPhong;
    public:
        friend class List;
        PhongKS();
        ~PhongKS();
        friend istream& operator>>(istream&, PhongKS&);
        friend ostream& operator<<(ostream&, const PhongKS&);
};