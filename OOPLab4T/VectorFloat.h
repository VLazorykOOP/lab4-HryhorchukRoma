#pragma once
#include <iostream>
#include <math.h>
using namespace std;

int vector_object_count = 0;

class VectorFloat
{
	float* v;
	int num;
	int state = 0;
public:
	VectorFloat() : VectorFloat(1) { vector_object_count++; }
	VectorFloat(size_t n) {
		if (n <= 0) n = 1;
		num = n;
		v = new float[n];
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		for (int i = 0; i < n; i++) {
			v[i] = 0;
		}
	}
	VectorFloat(size_t n, float b) : VectorFloat(n) {
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		for (int i = 0; i < num; i++) v[i] = b;
	};
	VectorFloat(size_t n, float* p) : VectorFloat(n) {
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		if (p != nullptr) for (int i = 0; i < num; i++) v[i] = p[i];
	};
	VectorFloat(const VectorFloat& s) {
		num = s.num;
		v = new float[num];
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		state = s.state;
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
	};
	VectorFloat operator+(VectorFloat s) const {
		if (num != s.num) {
			VectorFloat result;
			result.state = 1;
			return result;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
			return result;
		}
	}
	VectorFloat operator-(const VectorFloat s) const {
		if (num != s.num) {
			VectorFloat result;
			result.state = 1;
			return result;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
			return result;
		}
	};
	VectorFloat operator*(unsigned char scalar) const {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}
		return result;
	};
	bool operator!=(const VectorFloat s) const {
		if (num != s.num) {
			return true;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return true;
				}
			}
			return false;
		}
	};
	bool operator==(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	VectorFloat operator=(VectorFloat s) {
		if (num != s.num)
		{
			delete[] v;
			num = s.num;
			v = new float[num];
			state = s.state;
		}
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
		return *this;
	};
	~VectorFloat() {
		delete[] v;
		vector_object_count--;
	}
	void set(int index, float x = 0) { if (index >= 0 && index <= num) v[index] = x; else state = 1; }
	float get(int index) { if (index >= 0 && index <= num) return v[index]; else state = 1; }
	void Output() {
		if (state == 1) {
			cout << "Index error";
			return;
		}
		if (state == 2)
		{
			cout << "Memory error";
			return;
		}
		if (num != 0) {
			for (int i = 0; i < num; i++) {
				cout << " v [ " << i << " ]   " << v[i] << '\t';
				cout << endl;
			}
		}
		else
		{
			cout << "Vector is empty";
		}
	};
	void Input() {
		int in_num = 0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
		} while (in_num <= 0);
		if (num != in_num) {
			num = in_num;
			if (v) delete[] v;
			v = new float[num];
		}
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]= "; cin >> v[i];
		}
	};
	VectorFloat operator++() const {
		for (int i = 0; i < num; i++)
		{
			v[i]++;
		}
		return *this;
	}
	VectorFloat operator--() {
		for (int i = 0; i < num; i++)
		{
			v[i]--;
		}
		return *this;
	}
	bool operator!() {
		return num ? true : false;
	}
	VectorFloat operator-() {
		for (int i = 0; i < num; i++)
		{
			v[i] = -v[i];
		}
		return *this;
	}
	VectorFloat operator+=(VectorFloat s) {
		VectorFloat result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator-=(VectorFloat s) {
		VectorFloat result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator*=(float scalar) {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator/=(float scalar) {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] / scalar;
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator/(unsigned char scalar) const {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] / scalar;
		}
		return result;
	};
	friend istream& operator>>(istream& is, VectorFloat& sv);
	friend ostream& operator<<(ostream& os, const VectorFloat& sv);
	float& operator[](size_t ind) {
		if (ind >= num) state = 1;
		return (ind < num) ? v[ind] : v[num - 1];
	}
	void* operator new(size_t size) {
		VectorFloat temp();
		return &temp;
	}
	void operator delete(void* ptr) {
		ptr = nullptr;
	}
	VectorFloat operator()(int value) {
		for (int i = 0; i < num; i++)
		{
			v[i] = value;
		}
		return *this;
	}
	bool operator>(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] <= s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator>=(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] < s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator<(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] < s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	void init(int n) {
		if (num != n) {
			if (v != nullptr) delete[] v;
			num = n;
			v = new float[n];
		}
		for (int i = 0; i < num; i++) 	v[i] = 0;
	}
	void init(int n, float b) {
		if (num != n) {
			if (v != nullptr) delete[] v;
			num = n;
			v = new float[n];
		}
		for (int i = 0; i < num; i++) 	v[i] = b;
	}
	int length() {
		return num;
	}
};
istream& operator>>(istream& is, VectorFloat& sv)
{
	for (int i = 0; i < sv.num; i++)
	{
		is >> sv.v[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const VectorFloat& sv)
{
	for (int i = 0; i < sv.num; i++)
	{
		os << sv.v[i] << ' ';
	}
	return os;
}
#pragma once
#include <iostream>
#include <math.h>
using namespace std;

int vector_object_count = 0;

class VectorFloat
{
	float* v;
	int num;
	int state = 0;
public:
	VectorFloat() : VectorFloat(1) { vector_object_count++; }
	VectorFloat(size_t n) {
		if (n <= 0) n = 1;
		num = n;
		v = new float[n];
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		for (int i = 0; i < n; i++) {
			v[i] = 0;
		}
	}
	VectorFloat(size_t n, float b) : VectorFloat(n) {
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		for (int i = 0; i < num; i++) v[i] = b;
	};
	VectorFloat(size_t n, float* p) : VectorFloat(n) {
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		if (p != nullptr) for (int i = 0; i < num; i++) v[i] = p[i];
	};
	VectorFloat(const VectorFloat& s) {
		num = s.num;
		v = new float[num];
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		state = s.state;
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
	};
	VectorFloat operator+(VectorFloat s) const {
		if (num != s.num) {
			VectorFloat result;
			result.state = 1;
			return result;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
			return result;
		}
	}
	VectorFloat operator-(const VectorFloat s) const {
		if (num != s.num) {
			VectorFloat result;
			result.state = 1;
			return result;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
			return result;
		}
	};
	VectorFloat operator*(unsigned char scalar) const {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}
		return result;
	};
	bool operator!=(const VectorFloat s) const {
		if (num != s.num) {
			return true;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return true;
				}
			}
			return false;
		}
	};
	bool operator==(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	VectorFloat operator=(VectorFloat s) {
		if (num != s.num)
		{
			delete[] v;
			num = s.num;
			v = new float[num];
			state = s.state;
		}
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
		return *this;
	};
	~VectorFloat() {
		delete[] v;
		vector_object_count--;
	}
	void set(int index, float x = 0) { if (index >= 0 && index <= num) v[index] = x; else state = 1; }
	float get(int index) { if (index >= 0 && index <= num) return v[index]; else state = 1; }
	void Output() {
		if (state == 1) {
			cout << "Index error";
			return;
		}
		if (state == 2)
		{
			cout << "Memory error";
			return;
		}
		if (num != 0) {
			for (int i = 0; i < num; i++) {
				cout << " v [ " << i << " ]   " << v[i] << '\t';
				cout << endl;
			}
		}
		else
		{
			cout << "Vector is empty";
		}
	};
	void Input() {
		int in_num = 0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
		} while (in_num <= 0);
		if (num != in_num) {
			num = in_num;
			if (v) delete[] v;
			v = new float[num];
		}
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]= "; cin >> v[i];
		}
	};
	VectorFloat operator++() const {
		for (int i = 0; i < num; i++)
		{
			v[i]++;
		}
		return *this;
	}
	VectorFloat operator--() {
		for (int i = 0; i < num; i++)
		{
			v[i]--;
		}
		return *this;
	}
	bool operator!() {
		return num ? true : false;
	}
	VectorFloat operator-() {
		for (int i = 0; i < num; i++)
		{
			v[i] = -v[i];
		}
		return *this;
	}
	VectorFloat operator+=(VectorFloat s) {
		VectorFloat result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator-=(VectorFloat s) {
		VectorFloat result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			VectorFloat result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator*=(float scalar) {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator/=(float scalar) {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] / scalar;
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new float[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	VectorFloat operator/(unsigned char scalar) const {
		VectorFloat result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] / scalar;
		}
		return result;
	};
	friend istream& operator>>(istream& is, VectorFloat& sv);
	friend ostream& operator<<(ostream& os, const VectorFloat& sv);
	float& operator[](size_t ind) {
		if (ind >= num) state = 1;
		return (ind < num) ? v[ind] : v[num - 1];
	}
	void* operator new(size_t size) {
		VectorFloat temp();
		return &temp;
	}
	void operator delete(void* ptr) {
		ptr = nullptr;
	}
	VectorFloat operator()(int value) {
		for (int i = 0; i < num; i++)
		{
			v[i] = value;
		}
		return *this;
	}
	bool operator>(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] <= s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator>=(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] < s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator<(const VectorFloat s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] < s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	void init(int n) {
		if (num != n) {
			if (v != nullptr) delete[] v;
			num = n;
			v = new float[n];
		}
		for (int i = 0; i < num; i++) 	v[i] = 0;
	}
	void init(int n, float b) {
		if (num != n) {
			if (v != nullptr) delete[] v;
			num = n;
			v = new float[n];
		}
		for (int i = 0; i < num; i++) 	v[i] = b;
	}
	int length() {
		return num;
	}
};
istream& operator>>(istream& is, VectorFloat& sv)
{
	for (int i = 0; i < sv.num; i++)
	{
		is >> sv.v[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const VectorFloat& sv)
{
	for (int i = 0; i < sv.num; i++)
	{
		os << sv.v[i] << ' ';
	}
	return os;
}
