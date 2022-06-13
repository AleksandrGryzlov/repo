#pragma once
template < class C >
class Iterator {
public:
	virtual C* next() = 0;
}
