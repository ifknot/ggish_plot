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

        //void element_text(R::element_text_t& text);

        //void element_line(R::element_line_t& line);

        //void element_rect(R::element_rect_t& rect);

        //void element_circle(R::element_circle_t& circle);

        DECLARE_EVENT_TABLE()

    public:

    };

}

