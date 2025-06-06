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


#ifndef TGUI_TEXT_HPP
#define TGUI_TEXT_HPP

#include <TGUI/Font.hpp>
#include <TGUI/Color.hpp>
#include <TGUI/Vector2.hpp>
#include <TGUI/TextStyle.hpp>
#include <TGUI/RenderStates.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class BackendTextBase;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class TGUI_API Text
    {
    public:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns a small distance that text should be placed from the side of a widget as padding.
        ///
        /// This distance is slightly smaller than getExtraHorizontalOffset.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static float getExtraHorizontalPadding(Font font, unsigned int characterSize, TextStyles textStyle = {});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns an extra distance that text should be placed from the side of a widget as padding.
        ///
        /// This distance is slightly larger than getExtraHorizontalPadding.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static float getExtraHorizontalOffset(Font font, unsigned int characterSize, TextStyles textStyle = {});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the distance that text should be placed from the bottom of the widget as padding.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static float getExtraVerticalPadding(unsigned int characterSize);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the height of a single line of text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static float getLineHeight(Font font, unsigned int characterSize, TextStyles textStyle = {});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the width of a single line of text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static float getLineWidth(const String &text, Font font, unsigned int characterSize, TextStyles textStyle = {});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Finds the best character size for the text
        ///
        /// @param font    Font of the text
        /// @param height  Height that the text should fill
        /// @param fit     0 to choose best fit, 1 to select font of at least that height, -1 to select font of maximum that height
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static unsigned int findBestTextSize(Font font, float height, int fit = 0);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// The line spacing of a font gives the distance between two lines. There may however be an overlap between the highest
        /// character on the bottom line and the smallest one on the top line. This function calculates that distance.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static float calculateExtraVerticalSpace(Font font, unsigned int characterSize, TextStyles style = {});


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// Takes a string and inserts newlines into it so that the width does not exceed maxWidth.
        ///
        /// @param maxWidth         Maximum width of the text
        /// @param text             The text to wrap
        /// @param font             Font of the text
        /// @param textSize         The text size
        /// @param bold             Should the text be bold?
        /// @param dropLeadingSpace Should a single space at the beginning of a line be removed?
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static String wordWrap(float maxWidth, const String& text, Font font, unsigned int textSize, bool bold, bool dropLeadingSpace = true);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public:


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Default constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Text();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Text(const Text&);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Move constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Text(Text&&) noexcept = default;

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Overload of copy assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Text& operator=(const Text&);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Move assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Text& operator=(Text&&) noexcept = default;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the position of the text
        ///
        /// @param position  Position of the text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setPosition(Vector2f position);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the position of the text
        ///
        /// @return Text position
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getPosition() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the text
        ///
        /// @return Size required for drawing the text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text
        ///
        /// @param string  The new text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setString(const String& string);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text
        ///
        /// @return The current text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const String& getString() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the character size of the text
        ///
        /// @param size  The new text size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setCharacterSize(unsigned int size);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the character size of the text
        ///
        /// @return The current text size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        unsigned int getCharacterSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text fill color
        ///
        /// @param color  The new text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text fill color
        ///
        /// @return text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the opacity of the text
        ///
        /// @param opacity  The text opacity
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setOpacity(float opacity);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the opacity of the text
        ///
        /// @return text opacity
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getOpacity() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the font used for the text
        ///
        /// @param font  The new font
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setFont(Font font);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the font of the text
        ///
        /// @return text font
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Font getFont() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the style of the text
        ///
        /// The possible styles can be found in the tgui::TextStyle::Style enum.
        /// You can also pass a combination of multiple styles, for example tgui::TextStyle::Bold | tgui::TextStyle::Italic.
        /// The default style is tgui::TextStyle::Regular.
        ///
        /// @param style  New text style
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setStyle(TextStyles style);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the style of the text
        ///
        /// @return The current text style
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TextStyles getStyle() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text outline color
        ///
        /// @param color  The new text outline color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setOutlineColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text outline color
        ///
        /// @return text outline color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getOutlineColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text outline thickness
        ///
        /// @param thickness  The new text outline thickness
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setOutlineThickness(float thickness);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text outline thickness
        ///
        /// @return text outline thickness
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getOutlineThickness() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Return the position of the @a index-th character
        ///
        /// If @a index is out of range, the position of the end of the string is returned.
        ///
        /// @param index Index of the character
        ///
        /// @return Position of the character
        ///
        /// @warning Unlike the function in sf::Text, this function does not take global transformations into account.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f findCharacterPos(std::size_t index) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns a small distance that text should be placed from the side of a widget as padding.
        ///
        /// This distance is slightly smaller than getExtraHorizontalOffset.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getExtraHorizontalPadding() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns an extra distance that text should be placed from the side of a widget as padding.
        ///
        /// This distance is slightly larger than getExtraHorizontalPadding.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getExtraHorizontalOffset() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the height of a single line of text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getLineHeight() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the width of a single line of text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getLineWidth() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the internal text
        /// @return Backend text that is used internally
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<BackendTextBase> getBackendText() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        std::shared_ptr<BackendTextBase> m_backendText;
        String       m_string;
        Vector2f     m_position;
        Font         m_font;
        Color        m_color;
        Color        m_outlineColor;
        TextStyles    m_textStyle = TextStyle::Regular;
        unsigned int m_characterSize = 32;
        float        m_outlineThickness = 0;
        float        m_opacity = 1;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_TEXT_HPP
