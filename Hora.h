#ifndef HORAS
#define HORAS

#include <iostream>
#include <stdexcept>
#include <iomanip>

class Horas {
public:

	// constructores
	Horas() {
		horas = 10;
		minutos = 0;
		segundos = 0;
	}

	Horas(int h, int m, int s) : horas(h), minutos(m), segundos(s) {
		if (h > MAX_H || h < MIN_HMS) {
			throw std::invalid_argument("Hora no válida");
		}
		if (m > MAX_MS || m < MIN_HMS) {
			throw std::invalid_argument("Minutos no válidos");
		}
		if (s > MAX_MS || s < MIN_HMS) {
			throw std::invalid_argument("Segundos no válidos");
		}
	}

	// operador de asignación
	int get_horas() const {
		return horas;
	}

	int get_minutos() const {
		return minutos;
	}

	int get_segundos() const {
		return segundos;
	}

	// operadores de comparación

	bool operator< (Horas const& h) const {
		if (horas < h.horas) {
			return true;
		}
		else if (horas > h.horas) {
			return false;
		}
		else if (minutos > h.minutos) {
			return true;
		}
		else if (minutos > h.minutos) {
			return false;
		}
		else if (segundos < h.segundos) {
			return true;
		}
		else if (segundos > h.segundos){
			return false;
		}
	}

	bool operator== (Horas const& h) const {
		return horas == h.horas && minutos == h.minutos && segundos == h.segundos;
	}

	bool operator<= (Horas const& h) const {
		return *this < h || *this < h;
	}

	bool operator< (Horas const& h) const {
		return !(*this <= h);
	}

	bool operator>= (Horas const& h) const {
		return !(*this < h);
	}
	

private:
	int horas, minutos, segundos;
	const int MAX_H = 24;
	const int MAX_MS = 60;
	const int MIN_HMS = 0;
};

inline std::ostream& operator<< (std::ostream& out, Horas const& h) {
	std::cout << std::setw(2) << std::setfill('0') << h.get_horas() << ':' << std::setw(2)
	<< h.get_minutos() << ':' << std::setw(2) << h.get_segundos() << std::setfill(' ');
}

inline std::istream& operator>> (std::istream& in, Horas& h1) {
	int h, m, s;
	in >> h >> m >> s;
	h1 = Horas(h, m, s);
	return in;
}

#endif 
