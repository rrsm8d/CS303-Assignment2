#include "ProfessionalEmployee.h"
#include "NonProfessionalEmployee.h"
#include "SingleLinkedList.h"

int main()
{
	cout << "Testing NonProfessionalEmployee class: " << endl << endl;
	NonProfessionalEmployee Jimmy(20, 40, 14.1, 240);
	cout << "calcVacationDays(): " << Jimmy.calcVacationDays() << endl;
	cout << "calcWeeklySalary(): " << Jimmy.calcWeeklySalary() << endl;
	cout << "calcHealthCare(): " << Jimmy.calcHealthcare() << endl << endl;

	cout << "Testing ProfessionalEmployee class: " << endl << endl;
	ProfessionalEmployee John(30, 40, 13500, 15);
	cout << "calcVacationDays(): " << John.calcVacationDays() << endl;
	cout << "calcWeeklySalary(): " << John.calcWeeklySalary() << endl;
	cout << "calcHealthCare(): " << John.calcHealthcare() << endl << endl;

	cout << "Testing SingleLinkedList class: " << endl << endl;
	SingleLinkedList myList;
	Item_Type item;
	// creating a linked list
	for (int i = 5; i > 0; i--)
	{
		item.value = i;
		myList.push_back(item);
	}
	cout << "Initial list: " << endl;
	myList.printSingleLinkedList();

	cout << "After pop_front(): " << endl;
	myList.pop_front();
	myList.printSingleLinkedList();

	cout << "After pop_back(): " << endl;
	myList.pop_back();
	myList.printSingleLinkedList();

	cout << "After push_front() with value 999: " << endl;
	item.value = 999;
	myList.push_front(item);
	myList.printSingleLinkedList();

	cout << "After push_back() with value 888: " << endl;
	item.value = 888;
	myList.push_back(item);
	myList.printSingleLinkedList();

	cout << "After insert() with index 3 and value 404: " << endl;
	item.value = 404;
	myList.insert(3, item);
	myList.printSingleLinkedList();

	cout << "After remove() with index 3: " << endl;
	myList.remove(3);
	myList.printSingleLinkedList();

	cout << "Using find() with value of 4" << endl;
	item.value = 4;
	cout << "Found at index: " << myList.find(item) << endl << endl;

	cout << "Front: " << myList.front()->item.value << endl;
	cout << "Back: " << myList.back()->item.value << endl;
	cout << "Number of items: " << myList.getNumItems() << endl;
}