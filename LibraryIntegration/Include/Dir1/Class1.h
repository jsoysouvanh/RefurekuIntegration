#pragma once

#include <iostream>

#include "Generated/Class1.rfkh.h"

namespace test NAMESPACE()
{
	class CLASS() Class1
	{
		private:
			FIELD()
			int	someInt = 2;

			METHOD()
			void method1()	noexcept { std::cout << "Class1::method1();" << std::endl; }

		protected:
			FIELD() 
			float	someFloat = 0.0f;

		public:
			Class1()	= default;

		test_Class1_GENERATED
	};
}

File_Class1_GENERATED