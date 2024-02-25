#ifndef Vector_H
#define Vector_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include <iomanip>
#include <memory>

namespace BSTD
{

	template <class T>
	class Vector
	{
	private:
		int size_;
		std::shared_ptr<T> list_;
	public:
		Vector() = delete;
		Vector(int size, T init_value); // 有参构造函数
		Vector(std::initializer_list<T> values); // 列表初始化函数
		Vector(Vector& other); // 拷贝构造函数
		~Vector();

		T& operator()(int index); // 重载()运算符
		const T& operator()(int index) const;

		Vector<T>& operator=(const Vector<T>& other); // 重载=运算符
		const Vector<T>& operator=(const Vector<T>& other) const;

		void setAll(T const value);
		void print();
		void print() const;
		void deepCopy(const Vector& other); // 拷贝函数
		int& getSize();
		const int& getSize() const;

		std::shared_ptr<T> data();
		const std::shared_ptr<T> data() const;
	};

#include "Vector.inl"

}
#endif