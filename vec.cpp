// VECTOR
#include <cassert>
#include <algorithm>
#include <iostream>

template <class T>
class Vector {
private:
	int m_size = 0;
	T* m_data = nullptr;

public:
	Vector() = default;
	
	Vector(int n, T v = T{}) : m_size{n}, m_data{new T[m_size]} {
		assert(n > 0);
		std::fill(m_data, m_data + m_size, v);
	}
	
	~Vector() {
		delete [] m_data;
	}
	
	Vector(Vector const &other) : m_size{other.m_size}, m_data{new T[m_size]} {
		std::copy(other.m_data, other.m_data + m_size, m_data);
	}
	
	Vector& operator=(Vector const &other) {
		if(this != other) {
			delete[] m_data;
			m_size = other.m_size;
			m_data = new T[m_size];
			std::copy(other.m_data, other.m_data + m_size, m_data);
		}
		return *this;
	}
	
	T& operator[](int i) {
		assert(i >= 0 && i < m_size);
		return m_data[i];
	}
	
	T const& operator[](int i) const {
		assert(i >= 0 && i < m_size);
		return m_data[i];
	}
};

int main() {
	Vector<int> v1;
	Vector<int> v2 {5, 5};
	
	for (int i = 0; i != 5; ++i) {
		std::cout << v2[i] << ' ';
	}
	std::cout << '\n';
}
