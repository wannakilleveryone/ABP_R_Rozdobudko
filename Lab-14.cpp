#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
class Set {
public:
	// конструкторы
	Set() {}
	Set(const Set& s) {}
	Set(const std::vector<int>& v) {}

	// деструкторы
	virtual ~Set() {}

	// методы
	virtual void addElement(int elem) = 0;   // Adding an element to a set
	virtual void removeElement(int elem) = 0;  // Removing an element from a set
	virtual bool isElement(int elem) = 0;  // Checking that an element is part of a set
	virtual void clear() = 0;  // Clearing the set
};

// второй класс
class ConcreteSet : public Set {
private:
	std::unordered_set<int> set;
public:
	ConcreteSet() : Set() {}
	ConcreteSet(const Set& s) : Set(s) {}
	ConcreteSet(const std::vector<int>& v) : Set(v) {}
	// Destructor
	~ConcreteSet() {}

	void addElement(int elem) override { set.insert(elem); }   // Adding an element to a set
	void removeElement(int elem) override { set.erase(elem); }  // Removing an element from a set
	bool isElement(int elem) override { return set.find(elem) != set.end(); }  // Checking that an element is part of a set
	void clear() override { set.clear(); }  // Clearing the set
};

int main() {
	ConcreteSet set;
	set.addElement(1);
	set.addElement(2);
	set.addElement(3);
	set.removeElement(2);
	cout << set.isElement(1) << endl;
	cout << set.isElement(2) << endl;
	set.clear();
	cout << set.isElement(1) << endl;
	return 0;
}