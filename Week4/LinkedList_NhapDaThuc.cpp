#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

void Nhap(DATHUC &a, double heso, int mu){
    DONTHUC* dt = new DONTHUC(heso, mu);
    Node* p = new Node(dt);

    if (a.head == NULL){
        a.head = p;
        a.tail = p;
    } else {
        a.tail -> next = p;
        a.tail = p;
    }
}

void Xuat(DATHUC a){
    Node* p = a.head;
    bool daIn = false;
    while (p != NULL){
        if (p->data->heso != 0){

        if (daIn)
        {
            if (p->data->heso > 0)
                cout << "+";
        }
        else
        {
            daIn = true;
        }

        if (p->data->somu == 0)
        {
            cout << p->data->heso;
        }
        else if (p->data->somu == 1)
        {
            if (p->data->heso == 1)
                cout << "x";
            else if (p->data->heso == -1)
                cout << "-x";
            else
                cout << p->data->heso << "x";
        }
        else
        {
            if (p->data->heso == 1)
                cout << "x^" << p->data->somu;
            else if (p->data->heso == -1)
                cout << "-x^" << p->data->somu;
            else
                cout << p->data->heso << "x^" << p->data->somu;
        }
    }
        p = p->next;
    }
    if (!daIn)
        cout << "0";
    cout << endl;
}

double TinhDaThuc(DATHUC a, double x){
    Node* p = a.head;
    double sum = 0;
    while (p != NULL){
        sum += p->data->heso * pow(x, p->data->somu);
        p = p->next;
    }
    return sum;
}


int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    
    system("pause");
    return 0;
}
