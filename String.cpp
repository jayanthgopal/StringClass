#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <iostream>

#define MAX_STRING_LEN		2000

using namespace std;

class String {
private:
	char str[MAX_STRING_LEN];
	int len;

public:
	String():len(0){
		for(int i =0;i<MAX_STRING_LEN;i++)
			str[i] = '\0';
	}	
	~String(){};

	int length(){
		return len;
	}
	void push_back(char c){
		str[len++] = c;
	}
	char* get_str(){
		return str;
	}

	friend ostream & operator << (ostream &out, const String &c);
	friend istream & operator >> (istream &in, String &c);
	
	void operator = (String &S ) {
		char* t = S.get_str();
    	for(int i = 0; i < MAX_STRING_LEN;i++)
    		str[i] = t[i];
	}
      
    void operator = (char arr[] ) { 
    	for(int i = 0; i < MAX_STRING_LEN;i++)
    		str[i] = arr[i];
    }

	void operator + (String &S ) {
		int l = S.length();
		char* t = S.get_str();
    	for(int i = 0; i < l;i++)
    		str[len+i] = t[i];
		len = len + l;
	}
      
    void operator + (char arr[] ) { 
		int l = 0;
		
		while(arr[l] != '\0'){
			l++;	
		}
		
    	for(int i = 0; i < l;i++)
    		str[len+i] = arr[i];
		len = len + l;
    }	 
};

ostream & operator << (ostream &out, const String &str)
{
	out << str.str;
	return out;
}

istream & operator >> (istream &in, String &str)
{
	char temp[MAX_STRING_LEN] = {0};
	in >> temp;
	str = temp;
	return in;
}

int main()
{
	String S1;
	S1.push_back('a');
	S1.push_back('b');
	S1.push_back('c');
	std::cout << S1 << std::endl;
	
	String name;
	std::cout << "Enter a string:";
	cin >> name;
	std::cout << name << std::endl;
	
	String test1,test2;
	
	test1 = "Test1";
	test2 = test1;
	
	std::cout << test1 << " " << test2 << endl;
}
