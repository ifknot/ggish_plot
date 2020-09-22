#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include "data_frame.h"
#include "figure.h"
#include "theme.h"
#include "plot_composite.h"

namespace R {

    class plot_figure : public wxPanel, public plot_composite {

    public:

        plot_figure(wxFrame* parent, data_frame& data, figure_t& fig, theme_t& theme);

        //void layer(...);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        //build up the plot elements: panel, plot, title, subtitle, caption, tag, ...
        void init_paper();

        DECLARE_EVENT_TABLE()

    private:

        data_frame data;
        // copy of the physical metrics and strings for the figure
        figure_t fig;
        // copy of the aesthetic theme values
        theme_t theme;
        // use graphics context (wxWidgets 2.9.0) or not if available (i.e. < 2.9.0)
        bool use_gcdc{ true };

    };

}

