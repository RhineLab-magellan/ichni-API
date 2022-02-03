/*
* 创建者：菲露露
* 创建时间：2022.2.3
* 描述：FlexibleColorModifierUnitList类，用于适配List<FlexibleColorModifierUnit>
*/

#pragma once
#include <iostream>
#include <string>
#include "type.hpp"
using std::cout;
using std::endl;
using std::string;
using std::to_string;

class FlexibleColorModifierUnitList {
public:
	FlexibleColorModifierUnitList(){}
	~FlexibleColorModifierUnitList() {}

public:

	void startAdd(FlexibleColorModifierUnit af) {
		_Dat += "new List<FlexibleColorModifierUnit>(){\r\n"
			"new FlexibleColorModifierUnit("
			+ af.start.data() + ","
			+ af.end.data() + ","
			+ af.colorR.data() + ","
			+ af.colorG.data() + ","
			+ af.colorB.data() + ","
			+ af.colorA.data() + ","
			+ af.centerStart.data() + ","
			+ af.centerEnd.data() + ","
			+ af.blend.data() + ","
			+ af.position.data() + ")"
			;
		_Dat += _CRLF;
	}

	void add(FlexibleColorModifierUnit af) {
		_Dat += ",new FlexibleColorModifierUnit("
			+ af.start.data() + ","
			+ af.end.data() + ","
			+ af.colorR.data() + ","
			+ af.colorG.data() + ","
			+ af.colorB.data() + ","
			+ af.colorA.data() + ","
			+ af.centerStart.data() + ","
			+ af.centerEnd.data() + ","
			+ af.blend.data() + ","
			+ af.position.data() + ")";

		_Dat += _CRLF;
	}

	void FlexibleColorModifierUnit() {
		_Dat += "});";
		_Dat += _CRLF;
	}


	string data()const {
		return _Dat;
	}

private:
	string _Dat;
};