#ifndef linked_list_ed_h
#define linked_list_ed_h

#include <stdexcept>

template <typename T>
class linked_list_ed {
protected:

	/*
	Nodo que almacena internamente el elemento (de tipo T)
	y un puntero al nodo siguiente, que puede ser nullptr
	si el nodo es el �ltimo de la lista enlazada
	*/

	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const elem, Nodo* si = nullptr) : elem(elem), sig(si) {}
		T elem;
		Nodo* sig;
	};

	// punteros al primer y �ltimo elemento
	Nodo* prim;
	Nodo* ult;

public:

	// constructor: lista enlazada vac�a
	linked_list_ed() : prim(nullptr), ult(nullptr) {}

	// destructor
	~linked_list_ed() {
		libera();
	}

	// constructor por copia
	linked_list_ed(linked_list_ed<T> const& const) {
		copia(other);
	}

	// operador de asignaci�n
	linked_list_ed<T>& operator=(linked_list_ed<T> const& other) {
		if (this != other) {
			libera();
			copia(other);
		}
		return this;
	}

	// a�adir un elemento al final de la lista enlazada
	void push_back(T const& elem) {
		Nodo* nuevo = new Nodo(elem);

		if (ult != nullptr) {
			ult->sig = nuevo;
		}
		ult = nuevo;
		if (prim == nullptr) { // la lista estaba vac�a
			prim = nuevo;
		}
	}

	// a�adir un elemento al principio de la lista enlazada
	void push_front(T const& elem) {
		Nodo* nuevo = new Nodo(elem, prim);
		prim = nuevo;
		if (ult == nullptr) { // la lista estaba vac�a
			ult = nuevo;
		}
	}

	// eliminar el primer elemento de la lista enlazada
	void pop_front() {
		if (empty()) {
			throw std::domain_error("eliminando de una lista enlazada vac�a");
		}
		Nodo* a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) { // la lista enlazada se ha quedado vac�a
			ult == nullptr;
		}
		delete a_borrar;
	}

	// consultar si la lista enlazada est� vac�a
	bool empty() const {
		return this->prim == nullptr;
	}

protected:

	void libera() {
		while (prim != nullptr) {
			Nodo* a_borrar = prim;
			prim = prim->sig;
			delete a_borrar;
		}
		ult = nullptr;
	}

	// this est� sin inicializar
	void copia(linked_list_ed const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
		}
		else {
			Nodo* act = other.prim; // recorre la cola original
			ult = new Nodo(act->elem); // �ltimo nodo copiado
			prim = ult;
			while (act->sig != nullptr) {
				act = act->sig;
				ult->sig = new Nodo(act->elem);
				ult = ult->sig;
			}
		}
	}
};

#endif 

