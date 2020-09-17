#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include "figure.h"
#include "theme.h"
#include "plot_composite.h"

namespace R {

    class plot_paper : public wxPanel, plot_composite {

    public:

        plot_paper(wxFrame* parent, figure_t& fig, theme_t& theme);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        void render(wxDC& dc) override final;

        DECLARE_EVENT_TABLE()

    private:

        void init_plot();

        // physical metrics
        figure_t fig;
        // aesthetic values
        theme_t theme;
        // use graphics context (wxWidgets 2.9.0) or not if available (i.e. < 2.9.0)
        bool use_gcdc{ true };

    };

}

