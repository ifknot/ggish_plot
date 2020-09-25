#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include <map>

#include "data_frame.h"
#include "figure.h"
#include "theme.h"
#include "plot_pane.h"
#include "aesthetics.h"

namespace R {

    class plot_figure : public wxPanel, public plot_composite {

        // 2d grid of facet data mapped using the field names
        using facet_data_t = std::map<std::pair<std::string, std::string>, data_frame>;

    public:

        plot_figure(wxFrame* parent, data_frame& data, aesthetics_t aes, figure_t& fig, theme_t& theme);

        //void layer(...);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        DECLARE_EVENT_TABLE()

    private:


        data_frame&         data;  
        aesthetics_t        aes;  
        figure_t&           fig;        
        theme_t&            theme; 

        facet_data_t        facet_data;

        void init_layout();

        void add_annotations(plot_pane* pane);

        void add_coordinate_system(plot_pane* pane);

        void add_scales(plot_pane* pane);

        void add_geoms(plot_pane* pane);
       
        
        
        bool use_gcdc{ true }; 

    };

}

