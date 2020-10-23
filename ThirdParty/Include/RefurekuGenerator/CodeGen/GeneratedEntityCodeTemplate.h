/**
*	Copyright (c) 2020 Julien SOYSOUVANH - All Rights Reserved
*
*	This file is part of the Refureku library project which is released under the MIT License.
*	See the README.md file for full license details.
*/

#pragma once

#include <Kodgen/CodeGen/GeneratedCodeTemplate.h>
#include <Kodgen/InfoStructures/EntityInfo.h>

namespace rfk
{
	class GeneratedEntityCodeTemplate : public kodgen::GeneratedCodeTemplate
	{
		protected:
			/** Prefix used to build internal macros. */
			static constexpr char const* const	internalPrefix = "__RFK";
			
			/** Prefix used to build user exposed macros. */
			static constexpr char const* const	externalPrefix = "";

			/** Class global string hasher. */
			static std::hash<std::string> const	stringHasher;

			/**
			*	@brief Get the provided entity id as string.
			*	
			*	@param entity Entity we retrieve the id from.
			*
			*	@return The provided entity id as string.
			*/
			static inline std::string	getEntityId(kodgen::EntityInfo const& entity)							noexcept;

			/**
			*	@brief Generates a string containing the code which adds properties to the entity.
			*
			*	@param info				Source entity.
			*	@param entityVarName	Target entity variable name in the generated code.
			*	
			*	@return The generated code which adds the properties to the entity.
			*/
			std::string					fillEntityProperties(kodgen::EntityInfo const&	info,
															 std::string const&			entityVarName)	const	noexcept;

			/**
			*	@brief Write in the generated file #ifdef macroName #undef macroName #endif
			*	
			*	@param generatedFile	File to write into.
			*	@param macroName		Macro to undef if defined.
			*/
			void						ifDefUndefMacro(kodgen::GeneratedFile&	generatedFile,
														std::string const&		macroName)				const	noexcept;

		public:
			GeneratedEntityCodeTemplate()									= default;
			GeneratedEntityCodeTemplate(GeneratedEntityCodeTemplate const&)	= default;
			GeneratedEntityCodeTemplate(GeneratedEntityCodeTemplate&&)		= default;
			virtual ~GeneratedEntityCodeTemplate()							= default;
	};

	#include "RefurekuGenerator/CodeGen/GeneratedEntityCodeTemplate.inl"
}
