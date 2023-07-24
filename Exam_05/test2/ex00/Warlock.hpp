#pragma once

#include <iostream>

using std::cout;
using std::string;
using std::endl;



class Warlock{
	private:
		string _name;
		string _title;
		Warlock(){}
		Warlock &operator=(const Warlock& rhs) {
			_name = rhs._name;
			_title = rhs._title;
			return *this;
		}
		Warlock(const Warlock& src):_name(src._name), _title(src._title){
		}

	public:
		Warlock(string name, string title):_name(name), _title(title) {
			cout << name << ": This looks like another boring day." << endl;
		}
		virtual ~Warlock(){
			cout << _name << ": My job here is done!" << endl;
		}
		string getName() const { return _name;}
		string getTitle() const {return _title;}
		void setTitle(const string& title) {_title = title;};
		void introduce() const {
			cout << _name << ": I am " << _name << ", " << _title << "!" << endl;
		}
};