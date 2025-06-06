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


#ifndef TGUI_BOX_LAYOUT_RATIOS_HPP
#define TGUI_BOX_LAYOUT_RATIOS_HPP

#include <TGUI/Widgets/BoxLayout.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @brief Abstract class for box layout containers
    ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class TGUI_API BoxLayoutRatios : public BoxLayout
    {
    public:

        typedef std::shared_ptr<BoxLayoutRatios> Ptr; //!< Shared widget pointer
        typedef std::shared_ptr<const BoxLayoutRatios> ConstPtr; //!< Shared constant widget pointer


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @internal
        /// @brief Constructor
        /// @param typeName     Type of the widget
        /// @param initRenderer Should the renderer be initialized? Should be true unless a derived class initializes it.
        /// @see create
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BoxLayoutRatios(const char* typeName, bool initRenderer);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Adds a widget at the end of the layout
        ///
        /// @param widget      Pointer to the widget you would like to add
        /// @param widgetName  An identifier to access to the widget later
        ///
        /// The widget will have a ratio of 1.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void add(const Widget::Ptr& widget, const String& widgetName = "") override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Adds a widget at the end of the layout
        ///
        /// @param widget      Pointer to the widget you would like to add
        /// @param ratio       Ratio to determine the size compared to other widgets
        /// @param widgetName  An identifier to access to the widget later
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void add(const Widget::Ptr& widget, float ratio, const String& widgetName = "");


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Inserts a widget to the layout
        ///
        /// @param widget      Pointer to the widget you would like to add
        /// @param index       Index of the widget in the container
        /// @param widgetName  An identifier to access to the widget later
        ///
        /// The widget will have a ratio of 1.
        ///
        /// If the index is too high, the widget will simply be added at the end of the list.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void insert(std::size_t index, const Widget::Ptr& widget, const String& widgetName = "") override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Inserts a widget to the layout
        ///
        /// @param index       Index of the widget in the container
        /// @param widget      Pointer to the widget you would like to add
        /// @param ratio       Ratio to determine the size compared to other widgets
        /// @param widgetName  An identifier to access to the widget later
        ///
        /// The ratio is relative to all other widgets in the layout. If one widget has ratio 10 and the other has ratio 5,
        /// the first widget will be twice as large as the second one.
        ///
        /// If the index is too high, the widget will simply be added at the end of the list.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void insert(std::size_t index, const Widget::Ptr& widget, float ratio, const String& widgetName = "");


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes a single widget that was added to the container
        ///
        /// @param index  Index in the layout of the widget to remove
        ///
        /// @return False if the index was too high
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool remove(std::size_t index) override;
        using BoxLayout::remove;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Removes all widgets that were added to the container
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void removeAllWidgets() override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Add an extra space after the last widget
        ///
        /// @param ratio  Ratio to determine the size compared to other widgets
        ///
        /// The space will act as an invisible non-interactable widget, the ratio will be part of the total ratio of all widgets.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void addSpace(float ratio);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Insert an extra space between widgets
        ///
        /// @param index  Index of the widget in the container
        /// @param ratio  Ratio to determine the size compared to other widgets
        ///
        /// The space will act as an invisible non-interactable widget, the ratio will be part of the total ratio of all widgets.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void insertSpace(std::size_t index, float ratio);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the ratio of a widget
        ///
        /// @param widget  Widget from which the ratio should be changed
        /// @param ratio   New ratio to determine the size compared to other widgets
        ///
        /// The ratio is relative to all other widgets in the layout. If one widget has ratio 10 and the other has ratio 5,
        /// the first widget will be twice as large as the second one.
        ///
        /// @return False when the the widget was not found, true when the widget was valid and the ratio was changed
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool setRatio(Widget::Ptr widget, float ratio);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes the ratio of a widget at a certain index
        ///
        /// @param index  Index of the widget or space
        /// @param ratio  New ratio to determine the size compared to other widgets
        ///
        /// The ratio is relative to all other widgets in the layout. If one widget has ratio 10 and the other has ratio 5,
        /// the first widget will be twice as large as the second one.
        ///
        /// @return False when the index was too high, true when the index was valid and the ratio was changed
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool setRatio(std::size_t index, float ratio);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the ratio of a widget at a certain index
        ///
        /// @param widget  Widget from which the ratio should be returned
        ///
        /// @return The ratio of the widget or 0 when the widget was not found
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getRatio(Widget::Ptr widget) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the ratio of a widget at a certain index
        ///
        /// @param index  Index of the widget from which the ratio should be returned
        ///
        /// @return The ratio of the widget or 0 when the index was too high
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        float getRatio(std::size_t index) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Saves the widget as a tree node in order to save it to a file
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::unique_ptr<DataIO::Node> save(SavingRenderersMap& renderers) const override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Loads the widget from a tree of nodes
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void load(const std::unique_ptr<DataIO::Node>& node, const LoadingRenderersMap& renderers) override;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    protected:

        std::vector<float> m_ratios;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };


    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_BOX_LAYOUT_RATIOS_HPP
