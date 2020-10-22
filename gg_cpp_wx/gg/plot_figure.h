#pragma once

#include "wx/wx.h"
#include "wx/sizer.h"

#include "aesthetics.h"
#include "figure.h"
#include "theme.h"
#include "plot_background.h"

#include "..\rpp\data_frame.h"

namespace gg {

    class plot_figure : public wxPanel {

    public:

        plot_figure(wxFrame* parent, const R::data_frame& data, const aesthetics_t aes, const figure_t& fig, const theme_t& theme);

        void paintEvent(wxPaintEvent& evt);

        void paintNow();

        DECLARE_EVENT_TABLE()

    private:


        const R::data_frame&    data;  
        const aesthetics_t      aes;  
        const figure_t&         fig;        
        const theme_t&          theme; 

        plot_composite      plot;

        void init_layout();
       
        bool use_gcdc{ true }; 

    };

}

