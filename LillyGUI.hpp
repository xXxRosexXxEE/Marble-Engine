#ifndef _LILLYGUI_HPP
#define _LILLYGUI_HPP

			struct LillyGUI
			{
					int Button( int x_axis , int y_axis , bool show , const int type, int color);
					int Window( const int type , int x_axis , int y_axis , bool show , int frame_color , int background_color , int border_type );
			};

#endif