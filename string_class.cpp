#include<iostream>
#include<list>
#include<string>
#include<string.h>
using namespace std;

template<typename T>
void DisplayContents(const T& Input)
{
	for (auto iElement = Input.begin()
		; iElement != Input.end()
		; ++iElement)
		cout << *iElement << endl;
	cout << endl;
}

struct ContactItem
{
	string strContactsName;
	string strPhoneNumber;
	string strDisplayRepresentation;

	ContactItem(const string& strName, const string& strNumber)
	{
		strContactsName = strName;
		strPhoneNumber = strNumber;
		strDisplayRepresentation = strContactsName + ": " +
			strPhoneNumber;
	}

	bool operator==(const ContactItem& ItemToCompare) const
	{
		return(this->strContactsName == ItemToCompare.strContactsName);
	}

	bool operator<(const ContactItem& ItemToCompare) const
	{
		return(this->strContactsName < ItemToCompare.strContactsName);
	}

	operator const char* ()const
	{
		return strDisplayRepresentation.c_str();
	}

};

bool SornOnPhoneNumber(const ContactItem& item1,
					   const ContactItem& item2)
{
	return (item1.strPhoneNumber < item2.strPhoneNumber);
}

int main()
{
	list <ContactItem> Contacts;
	Contacts.push_back(ContactItem("Jack",
								   "+1 7889 879 879"));
	Contacts.push_back(ContactItem("Bill",
								  "+1 97 7897 8799 8"));
	Contacts.push_back(ContactItem("Angela",
								   "+49 23456 5466"));
	Contacts.push_back(ContactItem("Vladimir",
								   "+7 6645 4564 797"));
	Contacts.push_back(ContactItem("Manhoman",
								   "+91 234 4564 789"));

	DisplayContents(Contacts);
	Contacts.sort();
	DisplayContents(Contacts);
	Contacts.sort(SornOnPhoneNumber);
	DisplayContents(Contacts);
	Contacts.remove(ContactItem("Vladimir", ""));
	DisplayContents(Contacts);
	return 0;
}