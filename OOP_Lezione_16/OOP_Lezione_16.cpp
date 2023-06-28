#include<iostream>
#include<array>

template<typename Type,int size>
class MyClass {
private:
	Type _data[size];
	const int _size{ size };
public:
	//MyClass():_data(nullptr),_size(0){}
	const Type& operator[](int i) const {  // это всё одинаковое
		return _data[i];
	}
	Type& operator[](int i) {
		return _data[i];
	}
	auto at(int i)->Type& {
		return _data[i];
	}	
	auto at(int i)const ->const Type& {
		return _data[i];
	}
	///....
	int Size()const {
		return _size;
	}
	class iterator {  // вложенный класс
	private:
		Type* _data;
	public:
		iterator() = delete;
		iterator(Type*data):_data(data){}
		iterator& operator++() {
			_data++;
			return *this;
		}
		iterator& operator++(int) {
			iterator tmp(*this);
			_data++; return tmp;
		}
		Type& operator*() {
			return *_data;
		}
		bool operator==(const iterator&ob)const {
			return this->_data == ob._data;
		}
		bool operator!=(const iterator& ob)const {
			return !this->operator == (ob);
		}
		// если сложные условия
	};
	iterator begin() {
		return iterator(_data);
	}
	iterator end() {
		return iterator(_data + _size);
	}
};

void foo(MyClass<int, 10>a) {
	for (size_t i = 0; i < a.Size(); i++) {
		std::cout << a[i] << ' ';
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	MyClass<int, 10>a;
	for (size_t i = 0; i < a.Size(); i++) {
  		a[i] = i + 1;
	}
	foo(a);
	std::cout << "\n\n";
	int arr[10];
	for (size_t i = 0; i < std::size(arr); i++) {
		arr[i] = i + 1;
	}
	for (int &it : arr) {
		std::cout << it << ' ';
	}
	std::cout << "\n\n";

	std::array<int,10> arrOb;
	for (size_t i = 0; i < std::size(arrOb); i++) {
		arrOb[i] = i + 10;
	}
	for (const auto& it : arrOb) {
		std::cout << it << ' ';
	}
	std::cout << "\nМассив: \n";
	for (std::array<int,10>::iterator it = arrOb.begin(); it != arrOb.end();++it) {
		const auto& tr = *it;
		std::cout << tr << ' ';
	}
	std::cout << "\n\n";
	for (const auto& it : a) {
		std::cout << it << ' ';
	}

	return 0;
}