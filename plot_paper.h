#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

namespace R {

    class plot_paper : public wxPanel {

    public:

        plot_paper(wxFrame* parent);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        void render(wxDC& dc);

        DECLARE_EVENT_TABLE()

    };

}

