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


#ifndef TGUI_COMBO_BOX_RENDERER_HPP
#define TGUI_COMBO_BOX_RENDERER_HPP


#include <TGUI/Renderers/WidgetRenderer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class TGUI_API ComboBoxRenderer : public WidgetRenderer
    {
    public:

        using WidgetRenderer::WidgetRenderer;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the borders
        ///
        /// @param borders  Size of the borders
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorders(const Borders& borders);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the borders
        ///
        /// @return border size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Borders getBorders() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the padding of the combo box
        ///
        /// @param padding  The padding width and height
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setPadding(const Padding& padding);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the size of the padding
        ///
        /// @return padding size
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Padding getPadding() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text style
        ///
        /// @param style  New text style
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextStyle(TextStyles style);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns text style
        ///
        /// @return Style of the text
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TextStyles getTextStyle() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the text style of the default text (the text drawn when no item is selected)
        ///
        /// @param style  The new default text style
        ///
        /// @code
        /// comboBox->getSharedRenderer()->setDefaultTextStyle(tgui::TextStyle::Italic | tgui::TextStyle::Bold);
        /// @endcode
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setDefaultTextStyle(TextStyles style);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the text style of the default text (the text drawn when no item is selected)
        ///
        /// @return Style of the default text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        TextStyles getDefaultTextStyle() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the combo box
        ///
        /// @param backgroundColor  The new background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColor(Color backgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color
        ///
        /// @return Background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background color of the combo box when the combo box is disabled
        ///
        /// @param backgroundColor  The new disabled background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackgroundColorDisabled(Color backgroundColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background color when the combo box is disabled
        ///
        /// @return Disabled background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getBackgroundColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text
        ///
        /// @param textColor  The new text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColor(Color textColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the text
        ///
        /// @return Text color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getTextColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the text when the combo box is disabled
        ///
        /// @param textColor  The new disabled text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextColorDisabled(Color textColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the text when the combo box is disabled
        ///
        /// @return Disabled text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getTextColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the color of the default text that can optionally be displayed when no item is selected
        ///
        /// @param defaultTextColor  The new default text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setDefaultTextColor(Color defaultTextColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the default text that can optionally be displayed when no item is selected
        ///
        /// @return Default text color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getDefaultTextColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color behind the arrow
        ///
        /// @param color  The new arrow background color
        ///
        /// This color will be ignored when a up and down arrow image were loaded.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowBackgroundColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color behind the arrow
        ///
        /// @return Arrow background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getArrowBackgroundColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color behind the arrow in hover state (when the mouse is on top of it)
        ///
        /// @param color  The new hover arrow background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowBackgroundColorHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color behind the arrow in hover state (when the mouse is on top of it)
        ///
        /// @return Hover arrow background color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getArrowBackgroundColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color behind the arrow when the combo box is disabled
        ///
        /// @param color  The new disabled arrow background color
        ///
        /// This color will be ignored when a up and down arrow image were loaded.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowBackgroundColorDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color behind the arrow when the combo box is disabled
        ///
        /// @return Disabled arrow background color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getArrowBackgroundColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the arrow
        ///
        /// @param color  The new arrow color
        ///
        /// This color will be ignored when a up and down arrow image were loaded.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowColor(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the arrow
        ///
        /// @return Arrow color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getArrowColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the arrow in hover state (when the mouse is on top of it)
        ///
        /// @param color  The new hover arrow color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowColorHover(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the arrow in hover state (when the mouse is on top of it)
        ///
        /// @return Hover arrow color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getArrowColorHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the arrow when the combo box is disabled
        ///
        /// @param color  The new disabled hover arrow color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowColorDisabled(Color color);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the arrow when the combo box is disabled
        ///
        /// @return Disabled hover arrow color
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getArrowColorDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the color of the borders
        ///
        /// @param borderColor  The new border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBorderColor(Color borderColor);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the color of the borders
        ///
        /// @return Border color
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Color getBorderColor() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background image of the combo box
        ///
        /// @param texture  The background texture
        ///
        /// When this image is set, the background color property will be ignored.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureBackground(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background image of the combo box
        ///
        /// @return Background texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const Texture& getTextureBackground() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the background image of the combo box when the combo box is disabled
        ///
        /// @param texture  The disabled background texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureBackgroundDisabled(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the background image of the combo box when the combo box is disabled
        ///
        /// @return Disabled background texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const Texture& getTextureBackgroundDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image of the arrow
        ///
        /// @param texture  The new arrow texture
        ///
        /// When this image is set, the arrow color properties will be ignored.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureArrow(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image of the arrow
        ///
        /// @return Arrow texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const Texture& getTextureArrow() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image of the arrow that is displayed when the mouse is on top of it
        ///
        /// @param texture  The new hover arrow texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureArrowHover(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image of the arrow that is displayed when the mouse is on top of it
        ///
        /// @return Hover arrow texture
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const Texture& getTextureArrowHover() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the image of the arrow that is displayed when the combo box is disabled
        ///
        /// @param texture  The new disabled arrow texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setTextureArrowDisabled(const Texture& texture);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image of the arrow that is displayed when the combo box is disabled
        ///
        /// @return Disabled arrow texture
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const Texture& getTextureArrowDisabled() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the list box
        ///
        /// @param rendererData  Data about how the list box should look
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setListBox(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the list box
        ///
        /// @return Data about how the list box looks
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getListBox() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_COMBO_BOX_RENDERER_HPP
