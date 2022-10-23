#include"PhongKS.h"

class List{
    private:
        PhongKS *list;
        int soLuongPhong;
    public:
        List(int);
        ~List();
        PhongKS& operator[](const int&);
        int getSoLuongPhong();
        void copy(PhongKS*, PhongKS*);
        void firstAdd(const PhongKS&);
        void lastAdd(const PhongKS&);
        void addAt(const PhongKS&, int);
        void update();
        void removeAt(const int&);
        void firstRemove();
        void lastRemove();
        void swap(PhongKS&, PhongKS&);
        void quick_Sort(int, int, bool (*cmp)(const string&, const string&));
        int interpolation_Search(const string&);
        void Show();
};