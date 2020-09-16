#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include "figure.h"
#include "theme.h"
#include "plot_composite.h"

namespace R {

    class plot_paper : public wxPanel, plot_composite {

    public:

        plot_paper(wxFrame* parent);

        plot_paper(wxFrame* parent, unit_t width, unit_t height);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        void render(wxDC& dc) override final;

        DECLARE_EVENT_TABLE()

    public:

        bool use_gcdc{ true };
        figure_t fig;
        theme_t theme;

    };

}

