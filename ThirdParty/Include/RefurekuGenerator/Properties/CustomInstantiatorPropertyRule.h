/**
*	Copyright (c) 2020 Julien SOYSOUVANH - All Rights Reserved
*
*	This file is part of the Refureku library project which is released under the MIT License.
*	See the README.md file for full license details.
*/

#pragma once

#include <Kodgen/Properties/DefaultSimplePropertyRule.h>

namespace rfk
{
	class CustomInstantiatorPropertyRule : public kodgen::DefaultSimplePropertyRule
	{
		public:
			CustomInstantiatorPropertyRule()										noexcept;
			CustomInstantiatorPropertyRule(CustomInstantiatorPropertyRule const&)	= default;
			CustomInstantiatorPropertyRule(CustomInstantiatorPropertyRule&&)		= default;
			virtual ~CustomInstantiatorPropertyRule()								= default;

			virtual bool	isPropertyGroupValid(kodgen::PropertyGroup const&	propertyGroup,
												 kodgen::uint8					propertyIndex,
												 std::string&					out_errorDescription)	const noexcept override;

			virtual bool	isEntityValid(kodgen::EntityInfo const& entity,
										  kodgen::uint8				propertyIndex,
										  std::string&				out_errorDescription)				const noexcept override;
	};
}