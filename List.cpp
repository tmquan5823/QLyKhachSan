#include"List.h"
#include<iomanip>
#include<stdlib.h>

List::List(int n){
    this->soLuongPhong = n;
    this->list = new PhongKS[this->soLuongPhong];
    for(int i = 0;i<this->soLuongPhong;i++){
        cout<<"=====Phong thu "<<i+1<<"====="<<endl;
        cin>>*(list + i);
    }
}

List::~List(){
    delete[] list;
}

PhongKS& List::operator [](const int &index){
    static PhongKS t;
    if(index >= 0 && index < this->soLuongPhong){
        return *(this->list + index);
    }
    else 
        return t;
}

int List::getSoLuongPhong(){
    return this->soLuongPhong;
}

void List::addAt(const PhongKS& pks,int index){
    this->soLuongPhong++;
    PhongKS *list2 = new PhongKS[this->soLuongPhong];
    for(int i = 0; i<soLuongPhong - 1; i++){
        list2[i] = list[i];
    }
    for (int i = this->soLuongPhong - 1; i > index ; i--)
    {
        list2[i] = list2[i-1];
    }
    list2[index] = pks;
    delete[] list;
    list = new PhongKS[this->soLuongPhong];
    for(int i = 0; i<soLuongPhong; i++){
        list[i] = list2[i];
    }
    delete[] list2;
}

void List::firstAdd(const PhongKS& pks){
    addAt(pks, 0);
}

void List::lastAdd(const PhongKS& pks){
    addAt(pks, soLuongPhong);
}

void List::update(){
    this->Show();
    cout<<"Chon phong muon cap nhat thong tin: ";
    int stt;
    cin>>stt;
    cin>>list[stt];
    cout<<"Cap nhat thanh cong!"<<endl;
}

void List::removeAt(const int& index){
    PhongKS *list2 = new PhongKS[soLuongPhong];
    for(int i = 0 ;i< soLuongPhong;i++){
        list2[i] = list[i];
    }
    for(int i = index; i<soLuongPhong - 1;i++){
        list2[i] = list2[i+1];
    }
    delete[] list;
    this->soLuongPhong--;
    list = new PhongKS[soLuongPhong];
    for(int i = 0;i<soLuongPhong;i++){
        list[i] = list2[i];
    }
    delete[] list2;
}

void List::firstRemove(){
    this->removeAt(0);
}

void List::lastRemove(){
    this->removeAt(soLuongPhong - 1);
}

void List::swap(PhongKS& a, PhongKS& b){
    PhongKS tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void List::quick_Sort(int l, int r, bool(*cmp)(const string&, const string&)){
    if(l>=r) return;
    else if(l + 1 == r){
        if(!cmp(list[l].maPhong, list[r].maPhong)) swap(list[l], list[r]);
    }
    else{
        PhongKS p = list[r];
        int L = l - 1; 
        for(int i = l; i < r ; i++){
            if(cmp(list[i].maPhong, p.maPhong)){
                L++;
                swap(list[i], list[L]);
            }
        }
        swap(list[L+1], list[r]);
        quick_Sort(l, L, cmp);
        quick_Sort(L + 2, r,cmp);
    }
}

int List::interpolation_Search(const string& mp){
    int m, l = 0, h = soLuongPhong - 1;
    while (list[l].maPhong != list[h].maPhong && mp >= list[l].maPhong && mp <= list[h].maPhong)
    {
        m = l + ((atoi(mp.c_str()) - atoi(list[l].maPhong.c_str())) * (h - l) / (atoi(list[h].maPhong.c_str() - atoi(list[l].maPhong.c_str()))));
        if(list[m].maPhong < mp) 
            l = m + 1;
        else if(list[m].maPhong > mp) 
            h = m - 1;
        else return m;
    }
    if(mp == list[l].maPhong) return l;
    else return -1;
    
}

void List::Show(){
    cout<<left<<setw(5)<<"STT"<<left<<setw(15)<<"Ma phong"<<left<<setw(20)<<"So nguoi toi da"<<left<<setw(20)<<"Tinh trang"<<left<<setw(20)<<"Ngay nhan phong"<<left<<setw(20)<<"Ngay tra phong"<<right<<setw(10)<<"Gia phong"<<endl;
    cout<<setfill('-')<<setw(110)<<"-"<<endl;
	cout<<setfill(' ');
    for(int i = 0;i<this->soLuongPhong;i++){
        cout<<left<<setw(5)<<i;
        cout<<list[i]<<endl;
    }
    cout<<setfill('-')<<setw(110)<<"-"<<endl;
	cout<<setfill(' ');
}