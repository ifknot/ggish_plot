#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include "plot_composite.h"
#include "theme.h"

namespace R {

    class plot_paper : public wxPanel, R::plot_composite {

    public:

        plot_paper(wxFrame* parent);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        void render(wxDC& dc) override final;

        DECLARE_EVENT_TABLE()

    public:

        theme_t theme;

    };

}

