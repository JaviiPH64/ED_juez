#include "linked_list_ed.h"

template <typename T>
class linked_list_ed_plus: public linked_list_ed<T> {
	using Nodo = typename linked_list_ed<T>::Nodo; //renombramiento del Nodo

public:
	void mostrarMultiplos(int n, std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		while (aux != nullptr && aux->elem % n == 0) {
			aux->sig;
		}
		if (aux != nullptr) {
			o << aux->elem;
			aux = aux->sig;
			while (aux != nullptr) {
				if (aux->elem % n == 0) {
					o << ' ' << aux->elem;
				}
				aux = aux->sig;
			}
		}
		o << '\n';
	}

	// recorrer la lista y mostrar los elementos que cumplen una propiedad
	template <typename Predicate>
	void mostrarPropiedad(Predicate pred, std::ostream& o = std::cout) const {
		Nodo* aux = this->prim;
		while (aux != nullptr && !pred(aux->elem)) {
			aux = aux->sig;
		}
		if (aux != nullptr) {
			o << aux->elem;
			aux = aux->sig;
			while (aux != nullptr) {
				if (pred(aux->elem) {
					o << ' ' << aux->elem;
				}
				aux = aux -> sig;
			}
		}
		o << '\n';
	}
};

class EsPar {
public:
	bool operator()(int n) {
		return n % 2 == 0;
	}
};

class Multiplo {
public:
	Multiplo(int num) : n(num){}
	bool operator()(int valor) {
		return valor % n == 0;
	}

private:
	int n;
};