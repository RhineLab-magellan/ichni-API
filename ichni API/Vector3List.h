/*
* 创建者：菲露露
* 创建时间：2022.2.3
* 描述：Vector3List类，用于适配List<Vector3>
*/

#pragma once
#include <iostream>
#include <string>
#include "type.hpp"
using std::cout;
using std::endl;
using std::string;
using std::to_string;

//new List<Vector3>(){new Vector3(0,0,0),new Vector3(5,0,0),new Vector3(5,5,-2)}
class Vector3List {
public:
	Vector3List() :_Dat("") {}
	~Vector3List(){}
public:

	void startAdd(Vector3 af) {
		_Dat += "new List<Vector3>(){\r\n"
			"new Vector3("
			+ to_string(af.x) + "f,"
			+ to_string(af.y) + "f,"
			+ to_string(af.z) + "f)\r\n"
			;
		_Dat += _CRLF;
	}

	void add(Vector3 af) {
		_Dat += ",new Vector3("
			+ to_string(af.x) + "f,"
			+ to_string(af.y) + "f,"
			+ to_string(af.z) + "f)\r\n";
		_Dat += _CRLF;
	}

	void endAdd() {
		_Dat += "}";
		_Dat += _CRLF;
	}


	string data()const {
		return _Dat;
	}

private:
	string _Dat;
};