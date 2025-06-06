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


#ifndef TGUI_BITMAP_BUTTON_HPP
#define TGUI_BITMAP_BUTTON_HPP


#include <TGUI/Widgets/Button.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Button widget with an image displayed next to the text (or centered in the button without text)
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API BitmapButton : public Button
    {
    public:

        typedef std::shared_ptr<BitmapButton> Ptr; //!< Shared widget pointer
        typedef std::shared_ptr<const BitmapButton> ConstPtr; //!< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Constructor
        /// @param typeName     Type of the widget
        /// @param initRenderer Should the renderer be initialized? Should be true unless a derived class initializes it.
        /// @see create
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BitmapButton(const char* typeName = "BitmapButton", bool initRenderer = true);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Copy constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BitmapButton(const BitmapButton&);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Move constructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BitmapButton(BitmapButton&&);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Overload of copy assignment operator
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BitmapButton& operator=(const BitmapButton&);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Move assignment
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BitmapButton& operator=(BitmapButton&&);

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Destructor
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ~BitmapButton();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Creates a new bitmap button widget
        ///
        /// @param text  The text to display on the button
        ///
        /// @return The new bitmap button
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static BitmapButton::Ptr create(const String& text = "");


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Makes a copy of another button
        /// @param button  The other button
        /// @return The new button
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        static BitmapButton::Ptr copy(BitmapButton::ConstPtr button);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the size of the button
        /// @param size  The new size of the button
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(const Layout2d& size) override;
        using Widget::setSize;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the caption of the button
        /// @param text  New text to draw on top of the button
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void setText(const String& text) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the image that should be displayed next to the text
        /// @param image  Glyph to display
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setImage(const Texture& image);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the image being displayed next to the text
        /// @return Glyph displayed next to text
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const Texture& getImage() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the relative size of the image to display next to the text
        /// @param relativeHeight  Value between 0 and 1 that determines the height of the image compared to the button height.
        ///                        If set to 0 (default), the image will always have its original size, no matter what the
        ///                        button size is.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setImageScaling(float relativeHeight);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the relative size of the image displayed next to the text
        /// @return Value between 0 and 1 that determines the height of the image compared to the button height.
        ///         If 0 (default), the image has its original size and is unaffected by the button size
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getImageScaling() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Function called when one of the properties of the renderer is changed
        ///
        /// @param property  Name of the property that was changed
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void rendererChanged(const String& property) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Saves the widget as a tree node in order to save it to a file
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<DataIO::Node> save(SavingRenderersMap& renderers) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the widget from a tree of nodes
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void load(const std::unique_ptr<DataIO::Node>& node, const LoadingRenderersMap& renderers) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Called when size of button is updated
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateSize() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void initComponentsBitmapButton();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void updateComponentPositions();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the widget
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Widget::Ptr clone() const override
        {
            return std::make_shared<BitmapButton>(*this);
        }


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Recalculates the glyph size based on the set relative glyph height
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void recalculateGlyphSize();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private:

        priv::dev::StyleProperty<Texture> icon;

        // The component must be declared AFTER the style property
        std::shared_ptr<priv::dev::ImageComponent> m_imageComponent;

        float m_relativeGlyphHeight = 0;

        std::uint64_t m_textStyleChangedCallbackId = 0;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_BITMAP_BUTTON_HPP

