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


#ifndef TGUI_FILE_DIALOG_RENDERER_HPP
#define TGUI_FILE_DIALOG_RENDERER_HPP


#include <TGUI/Renderers/ChildWindowRenderer.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    class TGUI_API FileDialogRenderer : public ChildWindowRenderer
    {
    public:

        using ChildWindowRenderer::ChildWindowRenderer;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the list view
        ///
        /// @param rendererData  Data about how the list view should look
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setListView(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the list view
        ///
        /// @return Data about how the list view looks
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getListView() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the path and filename edit boxes
        ///
        /// @param rendererData  Data about how the edit boxes should look
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setEditBox(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the path and filename edit boxes
        ///
        /// @return Data about how the edit boxes looks
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getEditBox() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the filename label
        ///
        /// @param rendererData  Data about how the filename label should look
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setFilenameLabel(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the filename label
        ///
        /// @return Data about how the filename label looks
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getFilenameLabel() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the file type combo box
        ///
        /// @param rendererData  Data about how the file type combo box should look
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setFileTypeComboBox(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the file type combo box
        ///
        /// @return Data about how the file type combo box looks
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getFileTypeComboBox() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the cancel and confirm buttons
        ///
        /// @param rendererData  Data about how the buttons should look
        ///
        /// When BackButton, ForwardButton or UpButton are set to nullptr (default), then this property is also used for them
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setButton(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the cancel and confirm buttons
        ///
        /// @return Data about how the buttons look
        ///
        /// When BackButton, ForwardButton or UpButton are set to nullptr (default), then this property is also used for them
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getButton() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the back button
        ///
        /// @param rendererData  Data about how the back button should look
        ///
        /// When set to a nullptr (default), the Button property will be used as renderer data for the back button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setBackButton(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the back button
        ///
        /// @return Data about how the back button looks
        ///
        /// When this returns a nullptr (default), then the Button property is used as renderer data for the back button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getBackButton() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the forward button
        ///
        /// @param rendererData  Data about how the forward button should look
        ///
        /// When set to a nullptr (default), the Button property will be used as renderer data for the forward button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setForwardButton(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the forward button
        ///
        /// @return Data about how the forward button looks
        ///
        /// When this returns a nullptr (default), then the Button property is used as renderer data for the forward button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getForwardButton() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Sets the renderer data of the up button
        ///
        /// @param rendererData  Data about how the up button should look
        ///
        /// When set to a nullptr (default), the Button property will be used as renderer data for the up button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setUpButton(std::shared_ptr<RendererData> rendererData);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns the renderer data of the up button
        ///
        /// @return Data about how the up button looks
        ///
        /// When this returns a nullptr (default), then the Button property is used as renderer data for the up button.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        std::shared_ptr<RendererData> getUpButton() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Changes whether the arrows are shown on the back, forward and up buttons
        ///
        /// @param showArrows  Should an arrow character be displayed on top of the navigation buttons?
        ///
        /// The arrows are shown by default. You may want to hide them if you use textures for those buttons which include an
        /// icon. The arrows are meant to be used only when the buttons have a generic theme without an icon on them.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setArrowsOnNavigationButtonsVisible(bool showArrows);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// @brief Returns whether the arrows are shown on the back, forward and up buttons
        ///
        /// @return Is an arrow character displayed on top of the navigation buttons?
        ///
        /// @see setArrowsOnNavigationButtonsVisible
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool getArrowsOnNavigationButtonsVisible() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_BUTTON_RENDERER_HPP
