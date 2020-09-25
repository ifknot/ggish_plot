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

        plot_figure(wxFrame* parent, data_frame& source, figure_t& fig, theme_t& theme);

        //void layer(...);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        DECLARE_EVENT_TABLE()

    private:

        void init_layout();

        void add_annotations(plot_composite* pane);

        void add_coordinate_system();

        void add_scales();

        void add_geoms();
       
        figure_t fig; // copy of the physical metrics and strings for the figure
        
        theme_t theme; // copy of the aesthetic theme values
        
        bool use_gcdc{ true }; 

    };

}

