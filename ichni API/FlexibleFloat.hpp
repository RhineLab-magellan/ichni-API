/*
* 创建者：菲露露
* 创建时间：2022.2.3
* 描述：FlexibleFloat类，用于适配FlexibleFloat
* FlexibleColorModifierUnit类，用于适配FlexibleColorModifierUnit
*/

#pragma once
#include <iostream>
#include <string>
#include "type.hpp"
using std::cout;
using std::endl;
using std::string;
using std::to_string;

class FlexibleFloat {
public:
	FlexibleFloat(AnimatedFloat af):_Dat("") {
		_Dat += "new FlexibleFloat("
			"new List<AnimatedFloat>(){"
			"\r\nnew AnimatedFloat("
			+ to_string(af.startValue)
			+ "f, "
			+ to_string(af.endValue)
			+ "f, "
			+ to_string(af.startTime)
			+ "f, "
			+ to_string(af.endTime)
			+ "f, "
			+ af.animationCurve
			+ ")";
		_Dat += _CRLF;
	}
	~FlexibleFloat(){}
public:
	void add(AnimatedFloat af) {
		_Dat += ",new AnimatedFloat("
			+ to_string(af.startValue)
			+ "f, "
			+ to_string(af.endValue)
			+ "f, "
			+ to_string(af.startTime)
			+ "f, "
			+ to_string(af.endTime)
			+ "f, "
			+ af.animationCurve
			+ ")";
		_Dat += _CRLF;
	}

	void endAdd() {
		_Dat += "})";
		_Dat += _CRLF;
	}

	string data()const {
		return _Dat;
	}
private:
	string _Dat;
};

struct FlexibleColorModifierUnit
{
	FlexibleFloat start;
	FlexibleFloat end;
	FlexibleFloat colorR;
	FlexibleFloat colorG;
	FlexibleFloat colorB;
	FlexibleFloat colorA;
	FlexibleFloat centerStart;
	FlexibleFloat centerEnd;
	FlexibleFloat blend;
	FlexibleFloat position;
};

using FF = FlexibleFloat;
using FCMU =FlexibleColorModifierUnit;