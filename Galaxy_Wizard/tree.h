#pragma once
#include <list>

template<class T>
class tree
{
protected:
	std::list<tree<T>> childen;
public:
	tree();
	~tree();
};

template<class T>
tree<T>::tree()
{
}

template<class T>
tree<T>::~tree()
{
}
