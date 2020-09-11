#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include "elements.h"

namespace R {

    class plot_paper : public wxPanel {

    public:

        // TODO: elements, line circle rectangle text

        plot_paper(wxFrame* parent);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        void render(wxDC& dc);

        DECLARE_EVENT_TABLE()

    public:

        R::element_text_t text;

    };

}

