/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus' Graphical User Interface
// Copyright (C) 2012-2022 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_ABSOLUTE_OR_RELATIVE_VALUE_HPP
#define TGUI_ABSOLUTE_OR_RELATIVE_VALUE_HPP

#include <TGUI/Global.hpp>
#include <TGUI/String.hpp>
#include <type_traits>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Class to store the a value that is either a constant or a ratio
    ///
    /// You don't have to explicitly create an instance of this class, numbers and strings are implicitly cast.
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API AbsoluteOrRelativeValue
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_CONSTEXPR AbsoluteOrRelativeValue()
        {
            // Constructor isn't defined as "= default" because this leads to an IntelliSense error
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Constructor to set constant
        ///
        /// @param constant  Value to set
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
        TGUI_CONSTEXPR AbsoluteOrRelativeValue(T constant) :
            m_constant    {true},
            m_value       {static_cast<float>(constant)}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Construct the value from a string that either contains a value or a percentage
        ///
        /// @param expression  String to parse
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        AbsoluteOrRelativeValue(const char* expression) :
            AbsoluteOrRelativeValue{String{expression}}
        {
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Construct the value from a string that either contains a value or a percentage
        ///
        /// @param expression  String to parse
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        AbsoluteOrRelativeValue(const String& expression)
        {
            if (!expression.empty() && (expression.back() == '%'))
            {
                m_constant = false;
                m_ratio    = expression.substr(0, expression.length()-1).toFloat() / 100.f;
            }
            else
            {
                m_constant = true;
                m_value    = expression.substr(0, expression.length()).toFloat();
            }
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the value
        ///
        /// @return The constant value or the value based on the given ratio and parent size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_CONSTEXPR float getValue() const
        {
            return m_value;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the stored ratio
        ///
        /// @return The ratio that is multiplied with the parent size to get the value, when the value isn't a constant
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_CONSTEXPR float getRatio() const
        {
            return m_ratio;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the value is constant or a ratio
        ///
        /// @return Does the value contain a constant?
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_CONSTEXPR bool isConstant() const
        {
            return m_constant;
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Update the size to which the value depends on if the value is relative
        ///
        /// @param newParentSize  New size from which to take the relative value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TGUI_CONSTEXPR void updateParentSize(float newParentSize)
        {
            if (!m_constant)
            {
                m_parentValue = newParentSize;
                m_value = m_ratio * newParentSize;
            }
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Converts the value to a string
        ///
        /// @return String representation of the value
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        String toString() const
        {
            if (m_constant)
                return String::fromNumber(m_value);
            else
                return String::fromNumber(m_ratio * 100) + '%';
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        bool  m_constant     = true;
        float m_value        = 0;
        float m_ratio        = 0;
        float m_parentValue  = 0;
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Helper class to create an AbsoluteOrRelativeValue object containing a relative value without using a string
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct TGUI_API RelativeValue : AbsoluteOrRelativeValue
    {
        explicit TGUI_CONSTEXPR RelativeValue(float ratio)
        {
            m_constant = false;
            m_ratio    = ratio;
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_ABSOLUTE_OR_RELATIVE_VALUE_HPP
