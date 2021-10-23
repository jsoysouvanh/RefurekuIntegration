#pragma once

#include <vector>

#include "Dir1/Class1.h"

#include "Generated/Class2.rfkh.h"

class CLASS() Class2 : public test::Class1
{
	private:
		FIELD()
		double				someDouble	= 0.0;

		FIELD()
		std::vector<test::Class1>	vec;

	protected:
		FIELD()
		test::Class1*		class1		= nullptr;

	public:
		Class2() = default;

	Class2_GENERATED
};

File_Class2_GENERATED