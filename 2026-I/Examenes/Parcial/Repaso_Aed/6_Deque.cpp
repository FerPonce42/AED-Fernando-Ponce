/*
 * ╔══════════════════════════════╗
 * ║      Double Ended Queue     ║
 * ╚══════════════════════════════╝
 */

 #include <iostream>
using namespace std;

struct Deque {

	int** mapa;

	int** m_ini;
	int** m_fin;

	int* v_ini;
	int* v_fin;

	int n_elementos;

	Deque();

	void push_front(int x);
	void pop_front();

	void push_back(int x);
	void pop_back();

	int& operator[](int x);

	void print();
};


Deque::Deque() {

	mapa = new int*[5];

	m_ini = mapa + 2;
	m_fin = m_ini;

	v_ini = nullptr;
	v_fin = v_ini;

	n_elementos = 0;

}


void Deque::push_front(int x) {
	if (n_elementos == 0) {

		*m_ini = new int[5];

		v_ini = (*m_ini) + 2;
		v_fin = v_ini;


		*v_ini = x;

		n_elementos++;
	}
	else if (v_ini == *m_ini && mapa == m_ini) {
		cout << "Deque lleno para PushFronts" << endl;
		return;
	}
	else if (v_ini == *m_ini) {

		m_ini--;

		*m_ini = new int[5];

		v_ini = (*m_ini) + 4;

		*v_ini = x;

		n_elementos++;
	}
	else {

		v_ini--;
		*v_ini = x;

		n_elementos++;
	}
}


void Deque::pop_front() {

	if (n_elementos == 0) {

		cout << "No hay elementos cual retirar" << endl;

		return;
	}
	else if (v_ini == v_fin) {

		v_ini = nullptr;
		v_fin = nullptr;
		
		n_elementos--;
		delete* m_ini;
		
	}
	else if (v_ini == *m_ini + 4) {

		int** tmp = m_ini;

		m_ini++;

		v_ini = *m_ini;

		n_elementos--;

		delete* tmp;
	}
	else {

		v_ini++;

		n_elementos--;
	}

}




void Deque::push_back(int x) {
	if (n_elementos == 0) {

		*m_fin = new int[5];

		v_fin = (*m_fin) + 2;
		v_ini = v_fin;


		*v_fin = x;

		n_elementos++;
	}
	else if (v_fin == *m_fin && mapa + 4 == m_fin) {
		cout << "Deque lleno para PushBacks" << endl;
		return;
	}
	else if (v_fin == *m_fin + 4) {

		m_fin++;

		*m_fin = new int[5];

		v_fin = *m_fin;

		*v_fin = x;

		n_elementos++;
	}
	else {

		v_fin++;
		*v_fin = x;

		n_elementos++;
	}
}


void Deque::pop_back() {

	if (n_elementos == 0) {

		cout << "No hay elementos cual retirar" << endl;

		return;
	}
	else if (v_fin == v_ini) {

		v_fin = nullptr;
		v_ini = nullptr;

		n_elementos--;
		delete* m_fin;

	}
	else if (v_fin == *m_fin) {

		int** tmp = m_fin;

		m_fin--;

		v_fin = (*m_fin) + 4;

		n_elementos--;

		delete* tmp;
	}
	else {

		v_fin--;

		n_elementos--;
	}

}


int& Deque::operator[](int x){
	
	int m = m_fin - m_ini;

	int v = v_ini - *m_ini;

	int id = v + x;

	int bloque = id / 5;
	int vector = id % 5;


	int** mapa_actual = m_ini + bloque;
	int* elemento_actual = (*mapa_actual) + vector;


	return *elemento_actual;
}


void Deque::print() {

	int** inicio_mapa = m_ini;
	int* lugar_valor = v_ini;

	while (true) {
		if (n_elementos == 0) {
			cout << "No hay elementos que mostrar" << endl;
			return;
		}
		else if (lugar_valor == v_fin) {
			cout << *lugar_valor << " ";
			return;
		}
		else if (lugar_valor == *inicio_mapa + 4) {
			cout << *lugar_valor << " ";
			inicio_mapa++;
			lugar_valor = *inicio_mapa;
		}
		else {
			
			cout << *lugar_valor << " ";
			lugar_valor++;
		}
	}

	


}


int main() {
	Deque d;

	d.push_front(3);
	d.push_front(2);
	d.push_front(1);
	d.push_back(4);
	d.push_back(5);
	d.push_back(6);
	d.print(); cout << endl;

	cout << d[0] << endl;
	cout << d[2] << endl;
	cout << d[5] << endl;

	d[2] = 999;
	d.print(); cout << endl;
}