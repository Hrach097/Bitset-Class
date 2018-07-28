#include <iostream>
#include <cmath>

class Bitset {
		
public:
		Bitset();
		Bitset(const int);
		~Bitset();
		bool set(const int);
		bool unset(const int);
		void reset();
		void print() const;

private:
		int* m_bitArr;	
		int m_size;	
};


Bitset::Bitset() {

		m_size = 8;
		m_bitArr = new int[m_size];

}

Bitset::Bitset(int n) {
	
		if(n <= 0) {
				std::cout << "N has to be bigger than 0 " << std::endl; 
				return;
		}

		m_size = std::floor( (std::log(n) / std::log(2) ) ) +  1;   
		m_bitArr = new int[m_size];

		for(int ix = 0; ix < m_size; ++ix) {
				if(n & (1 << ix) ) {
						m_bitArr[ix] = 1;
				} else {
						m_bitArr[ix] = 0;
				}
		}
}

Bitset::~Bitset() {
		delete [] m_bitArr;
}

bool Bitset::set(const int index) {
		if(index < m_size && index >= 0) {
			m_bitArr[index] = 1;
			return 1;
		}
		std::cout << "Index " << index << " is out of range " << std::endl;
		return 0;
}

bool Bitset::unset(const int index) {
		if(index < m_size && index >= 0) {
			m_bitArr[index] = 0;
			return 1;
		}
		std::cout << "Index " << index << " is out of range " << std::endl;
		return 0;
}

void Bitset::reset() {
		for(int ix = 0; ix < m_size; ++ix) {
				m_bitArr[ix] = 0;
		}
}

void Bitset::print() const{
		for(int ix = m_size - 1; ix >= 0; --ix) {
				std::cout << "[" << m_bitArr[ix] << "]" <<  " ";
		}
		std::cout << std::endl;
}
