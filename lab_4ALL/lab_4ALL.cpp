#include <iostream>
#include <cstring>

class String
{
	friend std::ostream& operator<<(std::ostream &os, String &s);
public:
	String(const char *init);
	String(const char *init, int m);
	~String();
	String(const String& org);
	String& operator=(const String& rhs);
	// Constructor to initialize *this to string init of length m.
	bool operator == (const String &t);
	// If *this string equals t, return true, else return false.
	bool operator!();
	// If *this string is empty, return true, else return false.
	int Length() const;
	// Return the length of *this string.
	String Concat(String t);
	// Return a string of *this string followed by t.
	String Substr(int i, int j);
	// Return the substring of *this starting from position i to i+j-1.
	int Find(const String &pat);
	int FastFind(const String &pat);
	void FailureFunction();
	// Return the index i where pat resides in *this, -1 if not found.
	int String::CountSubString(const String &pat);
	const char * c_str() const;
	//const char *c_str();
private:
	char *str;
	int length;
	int *f;
};

String::String(const char *init)
{
	length = strlen(init);
	str = new char[length];
	strncpy(str, init, length);
	f = new int[length];
	FailureFunction();
}

String::String(const char *init, int m)
{
	length = m;
	str = new char[length];
	strncpy(str, init, length);
	f = new int[length];
	FailureFunction();
}

String::~String()
{
	delete[] str;
	delete[] f;
}

String::String(const String &org)
{
	this->length = org.length;
	this->str = new char[this->length];
	strncpy(this->str, org.str, this->length);
	f = new int[length];
	FailureFunction();
}

bool String::operator == (const String &t)
{
	if (this->Length() != t.Length())
		return false;
	return strncmp(this->str, t.str, Length()) == 0;
}

bool String::operator!()
{
	return length == 0;
}

int String::Length() const
{
	return length;
}

int String::Find(const String &pat)
{// Return the index where pat resides,
	// -1 if not found.
	for (int start = 0; start <= Length() - pat.Length(); start++) {
		// Check for match beginning at str[start]
		int j;
		for (j = 0; j < pat.Length() && str[start + j] == pat.str[j]; j++);
		if (j == pat.Length())
			return start;
		// no match at position start
	}
	return -1; // pat is empty or not found
}

void String::FailureFunction()
{// failure function for string *this
	int lengthP = Length();
	f[0] = -1;
	for (int j = 1; j < lengthP; j++) { // ­pºâ f[j]
		int i = f[j - 1];
		while ((*(str + j) != *(str + i + 1)) && (i >= 0))
			i = f[i];
		if (*(str + j) == *(str + i + 1))
			f[j] = i + 1;
		else f[j] = -1;
	}
}

int String::FastFind(const String &pat)
{// determine whether pat is a substring of *this¡C
	int posP = 0, posS = 0;
	int lengthP = pat.Length(), lengthS = Length();
	while ((posP < lengthP) && (posS < lengthS))
		if (pat.str[posP] == str[posS]) {// match
			posP++; posS++;
		}
		else if (posP == 0)
			posS++;
		else
			posP = pat.f[posP - 1] + 1;
		if (posP < lengthP)
			return -1;
		else
			return posS - lengthP;
}

int String::CountSubString(const String &pat)
{// Return the number of occurrences.
	int count = 0;
	for (int start = 0; start <= Length() - pat.Length(); start++) {
		// Check for match beginning at str[start]
		int j;
		for (j = 0; j < pat.Length() && str[start + j] == pat.str[j]; j++);
		if (j == pat.Length())
			++count;
		// no match at position start
	}
	return count;
}

const char *String::c_str() const
{
	return str;
}

String & String::operator=(const String & rhs)
{
	this->length = rhs.length;
	this->str = new char[this->length];
	strncpy(this->str, rhs.str, this->length);
	f = new int[length];
	FailureFunction();
	return *this;
}

std::ostream& operator<<(std::ostream &os, String &s)
{
	for (int i = 0; i < s.Length(); ++i)
		os << s.str[i];
	return os;
}

bool is_palindrome(const String &s)
{
	const char *str = s.c_str();
	int l = 0, r = s.Length() - 1;
	while (l <= r)
	{
		if (str[l] != str[r])
			return false;
		++l;
		--r;
	}
	return true;
}


bool is_palindrome(const String &s, bool ignore_cases)
{
	if (!ignore_cases)
		return is_palindrome(s);

	const char *str = s.c_str();
	char *newStr = new char[s.Length()];
	char *tmp = newStr;
	for (int i = 0; i < s.Length(); ++i)
	{
		if (str[i] == ' ')
			continue;
		*(tmp++) = tolower(str[i]);
	}
	*tmp = '\0';
	bool result = is_palindrome(newStr);
	delete[] newStr;
	return result;
}

void replace_str(String &text, const String &from, const String &to, int k)
{
	int delta = to.Length() - from.Length();
	int count = 0;

	const char *orgStr = text.c_str();
	char *newStr = new char[6666];
	char *tmp = newStr;

	int lastPos = 0;
	for (int start = 0; count < k && start <= text.Length() - from.Length(); start++)
	{
		// Check for match beginning at str[start]
		int j;
		for (j = 0; j < from.Length() && text.c_str()[start + j] == from.c_str()[j]; j++);
		if (j == from.Length())
		{
			strncpy(tmp, orgStr + lastPos, start - lastPos);
			tmp += start - lastPos;
			strncpy(tmp, to.c_str(), to.Length());
			tmp += to.Length();
			start += from.Length();
			lastPos = start;
			++count;
		}
		// no match at position start
	}
	int remains = text.Length() - lastPos;
	if (remains != 0)
		strncpy(tmp, orgStr + lastPos, remains);
	*(tmp + remains) = '\0';
	text = String(newStr);
	delete[] newStr;
}

#include <ctime>
using namespace std;

int main()
{
	String a("this is a string");
	cout << a << endl;

	cout << endl << "4a" << endl;
	clock_t start, stop;
	start = clock();
	for (int i = 0; i < 100000; ++i)
		a.Find("string");
	stop = clock();

	cout << "Find: " << double(stop - start) / CLOCKS_PER_SEC << " s" << endl;

	start = clock();
	for (int i = 0; i < 100000; ++i)
		a.FastFind("string");
	stop = clock();

	cout << "FastFind: " << double(stop - start) / CLOCKS_PER_SEC << " s" << endl;

	cout << "'is' occurrences: " << a.CountSubString("is") << endl;

	cout << endl << "4b" << endl;
	String b("madam");
	cout << b << " is" << (is_palindrome(b) ? "" : " not") << " a palindrome." << endl;

	String c("Ra dAr");
	cout << c << " is" << (is_palindrome(c, true) ? "" : " not") << " a palindrome." << endl;

	cout << endl << "4c" << endl;
	replace_str(a, "is", "ISIS", 1);
	cout << a << endl;

	return 0;
}
