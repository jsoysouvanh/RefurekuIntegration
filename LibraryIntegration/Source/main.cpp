#include <iostream>
#include <cassert>

#include <Refureku/Refureku.h>

//For the example simplicity all generated source files are included in the main
//The only requirement is that each generated source file is included in a single translation unit within the program
#include "Generated/Class1.rfks.h"
#include "Generated/Class2.rfks.h"
#include "Generated/Enum1.rfks.h"
#include "Generated/Struct1.rfks.h"

int main()
{
	test::Class1	c1;
	Class2			c2;

	rfk::Class const* arch = rfk::getDatabase().getNamespaceByName("test")->getClassByName("Class1");

	std::cout << arch->getName() << std::endl;

	rfk::Method const* m = arch->getMethodByName("method1");
	m->invoke(c1);

	Class2::staticGetArchetype().foreachDirectParent([](rfk::ParentStruct const& parent, void* data)
													 {
														 std::cout << "Parent: " << parent.getArchetype().getName() << std::endl;

														 return true;
													 }, nullptr);
		
	std::cout << Class2::staticGetArchetype().getFieldByName("class1")->getType().getArchetype()->getName() << std::endl;
	std::cout << Class2::staticGetArchetype().getFieldByName("vec")->getType().getArchetype() << std::endl;

	rfk::Struct const* arch2 = rfk::getDatabase().getNamespaceByName("test")->getStructByName("Struct1");

	std::cout << arch2->getName() << std::endl;

	return EXIT_SUCCESS;
}