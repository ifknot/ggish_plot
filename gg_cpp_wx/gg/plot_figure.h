#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include "aesthetics.h"
#include "figure.h"
#include "theme.h"
#include "plot_pane.h"

#include "..\rpp\data_frame.h"

namespace gg {

    class plot_figure : public wxPanel, public plot_composite {

    public:

        plot_figure(wxFrame* parent, R::data_frame& data, aesthetics_t aes, figure_t& fig, theme_t& theme);

        //void layer(...);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        DECLARE_EVENT_TABLE()

    private:


        R::data_frame&      data;  
        aesthetics_t        aes;  
        figure_t&           fig;        
        theme_t&            theme; 

        void init_layout();

        void add_annotations(plot_pane* pane);

        void add_coordinate_system(plot_pane* pane);

        void add_scales(plot_pane* pane);

        void add_geoms(plot_pane* pane);
       
        bool use_gcdc{ true }; 

    };

}

