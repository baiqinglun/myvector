#include "Vector.h"

using namespace BSTD;

// 使用数组大小和初始值初始化数组
template<class T>
Vector<T>::Vector(int size, T init_value) :size_(size)
{
	list_ = std::shared_ptr<T>(new T[size_], [](T* p) {
		//std::cout << "删除智能指针[初始化]" << std::endl;
		delete p;
		});

	for (int i = 0; i < size_; ++i)
	{
		list_.get()[i] = init_value;
	}
}

// 拷贝构造函数
template<class T>
Vector<T>::Vector(Vector& other)
{
	if (&other != nullptr && this != &other)
	{
		list_ = std::shared_ptr<T>(new T[size_], [](T* p) {
			//std::cout << "删除智能指针[构造函数]" << std::endl;
			delete[] p;
			});
		for (int i = 0; i < other.size_; ++i)
		{
			list_.get()[i] = other.list_.get()[i];
		}
		size_ = other.size_;
	}
}

// 构造函数，支持列表初始化
template<class T>
Vector<T>::Vector(std::initializer_list<T> values) : size_(values.size()) {

	list_ = std::shared_ptr<T>(new T[size_], [](T* p) {
		//std::cout << "删除智能指针[initializer_list]" << std::endl;
		delete[] p;
		});
	// 将列表中的值复制到数组中
	int index = 0;
	for (T value : values) {
		list_.get()[index++] = value;
	}
}

// 析构函数
template<class T>
Vector<T>::~Vector()
{
}

// 重载()运算符
template<class T>
inline T& Vector<T>::operator()(int index)
{
	if (index < 0 || index >= size_)
	{
		throw std::out_of_range("Index out of range.");
	}
	return list_.get()[index];
}

template<class T>
inline const T& Vector<T>::operator()(int index) const
{
	if (index < 0 || index >= size_)
	{
		throw std::out_of_range("Index out of range.");
	}
	return list_.get()[index];
}

// 重载=运算符
template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (&other != nullptr && this != &other)
	{
		size_ = other.size_;
		list_ = other.list_;
	}
	return *this;
}

template<class T>
inline const Vector<T>& Vector<T>::operator=(const Vector<T>& other) const
{
	if (&other != nullptr && this != &other)
	{
		size_ = other.size_;
		list_ = other.list_;
	}
	return *this;
}

// 这里根据模板类型分别打印，double类型保留四位小数
template<class T>
inline void printElement(const T& element) {
	std::cout << element;
}

template<>
inline void printElement<double>(const double& element) {
	std::cout << std::fixed << std::setprecision(4) << element;
}

template<class T>
inline void Vector<T>::print()
{
	for (int i = 0; i < size_; ++i)
	{
		printElement(list_.get()[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

template<class T>
inline void Vector<T>::print() const
{
	for (int i = 0; i < size_; ++i)
	{
		printElement(list_.get()[i]);
		std::cout << " ";
	}
	std::cout << std::endl;
}

// 设置全部值
template<class T>
inline void Vector<T>::setAll(const T value)
{
	for (int i = 0; i < size_; ++i)
	{
		list_.get()[i] = value;
	}
}

// 深拷贝
template<class T>
inline void Vector<T>::deepCopy(const Vector& other)
{
	if (&other != nullptr && this != &other)
	{
		list_ = std::shared_ptr<T>(new T[size_], [](T* p) {
			delete[] p;
			});
		for (int i = 0; i < other.size_; ++i)
		{
			list_.get()[i] = other.list_.get()[i];
		}
		size_ = other.size_;
	}
}

// 获取列表大小
template<class T>
inline int& Vector<T>::getSize()
{
	return size_;
}

template<class T>
inline const int& Vector<T>::getSize() const
{
	return size_;
}

template<class T>
inline std::shared_ptr<T> BSTD::Vector<T>::data()
{
	return list_;
}

template<class T>
inline const std::shared_ptr<T> BSTD::Vector<T>::data() const
{
	return list_;
}