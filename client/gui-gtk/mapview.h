/********************************************************************** 
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/
#ifndef __MAPVIEW_H
#define __MAPVIEW_H

#include <gtk/gtk.h>

#include <graphics.h>

struct unit;
struct city;

/* don't change this unless you also put more entries in data/Freeciv */
#define MAX_NUM_UNITS_BELOW 4

#define CORNER_TILES	 0

#define NUKE_TILE0	  1*20+17
#define NUKE_TILE1	  1*20+18
#define NUKE_TILE2	  1*20+19
#define NUKE_TILE3	  2*20+17
#define NUKE_TILE4	  2*20+18
#define NUKE_TILE5	  2*20+19
#define NUKE_TILE6	  3*20+17
#define NUKE_TILE7	  3*20+18
#define NUKE_TILE8	  3*20+19

#define GRASSLAND_TILES  1*20
#define DESERT_TILES	 2*20
#define ARCTIC_TILES	 3*20
#define JUNGLE_TILES	 4*20
#define PLAINS_TILES	 5*20
#define SWAMP_TILES	 6*20
#define TUNDRA_TILES	 7*20

/* jjm@codewell.com 30dec1998a
   Moved road and rail tiles to roads.xpm; added tiles for diagonals.
   (Lots of rearranging of tile indices.)
*/

extern int ROAD_TILES;
extern int RAIL_TILES;

#define RIVER_TILES	 8*20
#define OUTLET_TILES	 8*20+16
#define OCEAN_TILES	 9*20
#define HILLS_TILES	 10*20
#define FOREST_TILES	 10*20+4
#define MOUNTAINS_TILES  10*20+8
#define DENMARK_TILES	 10*20+12
#define X_TILE  	 10*20+19

#define CROSS_TILE	 9*20+17
#define AUTO_TILE	 9*20+18
#define PLUS_TILE	 9*20+19

#define SPECIAL_TILES	 11*20
#define O_TILE  	 11*20+12
#define S_TILE  	 11*20+13
#define G_TILE  	 11*20+14
#define M_TILE  	 11*20+15
#define P_TILE  	 11*20+16
#define R_TILE  	 11*20+17
#define I_TILE  	 11*20+18
#define F_TILE  	 11*20+19

/*  The tiles for the units are now stored in flags.xpm */
extern int FLAG_TILES;

/*
#define UNIT_TILES	 15*20
The tiles for the units are now stored in units.xpm
*/
extern int UNIT_TILES;

#define IRRIGATION_TILE  12*20+8
#define HILLMINE_TILE	 12*20+9
#define DESERTMINE_TILE  12*20+10
#define POLLUTION_TILE   12*20+11
#define CITY_TILE	 12*20+12
#define CITY_WALLS_TILE  12*20+13
#define HUT_TILE	 12*20+14
#define FORTRESS_TILE	 12*20+15

#define BORDER_TILES	 13*20

#define NUMBER_TILES	 14*20
#define NUMBER_MSD_TILES 14*20+9

#define SHIELD_NUMBERS   15*20
#define TRADE_NUMBERS	 15*20+10

#define HP_BAR_TILES	 16*20

#define CITY_FLASH_TILE  16*20+14
#define CITY_FOOD_TILES  16*20+15
#define CITY_MASK_TILES  16*20+17
#define CITY_SHIELD_TILE 16*20+19

#define FOOD_NUMBERS	 17*20

#define BULB_TILES	 18*20
#define GOVERNMENT_TILES 18*20+8
#define SUN_TILES	 18*20+14
#define PEOPLE_TILES	 18*20+22
#define RIGHT_ARROW_TILE 18*20+30

#define THUMB_TILES	 18*20+31

void update_info_label(void);
GdkPixmap *get_thumb_pixmap(int onoff);
GdkPixmap *get_citizen_pixmap(int frame);
void set_bulb_sol_government(int bulb, int sol, int government);
void update_turn_done_button(int do_restore);
void update_timeout_label(void);
void update_unit_info_label(struct unit *punit);
int map_canvas_adjust_x(int x);
int map_canvas_adjust_y(int y);
void refresh_tile_mapcanvas(int x, int y, int write_to_screen);
int tile_visible_mapcanvas(int x, int y);
int tile_visible_and_not_on_border_mapcanvas(int x, int y);
void move_unit_map_canvas(struct unit *punit, int x0, int y0, int x1, int y1);
void get_center_tile_mapcanvas(int *x, int *y);
void center_tile_mapcanvas(int x, int y);
gint overview_canvas_expose(GtkWidget *w, GdkEventExpose *ev);
void refresh_overview_canvas(void);
void overview_update_tile(int x, int y);
void refresh_overview_viewrect(void);
gint map_canvas_expose(GtkWidget *w, GdkEventExpose *ev);
void update_map_canvas(int tile_x, int tile_y, int width, int height, int write_to_screen);

void put_city_pixmap(struct city *pcity, GdkPixmap *pm, int xtile, int ytile);
void put_city_tile_output(GdkDrawable *pm, int x, int y, 
			  int food, int shield, int trade);
void put_unit_pixmap(struct unit *punit, GdkPixmap *pm, int xtile, int ytile);
void put_unit_gpixmap(struct unit *punit, GtkPixmap *p, int xtile, int ytile);

void put_unit_gpixmap_city_overlays(struct unit *punit, GtkPixmap *p,
				    int unhappiness, int upkeep);
void put_nuke_mushroom_pixmaps(int abs_x0, int abs_y0);
void pixmap_put_black_tile(GdkDrawable *pm, int x, int y);
void pixmap_frame_tile_red(GdkDrawable *pm, int x, int y);
void pixmap_put_tile(GdkDrawable *pm, int x, int y, int map_x, int map_y, 
		     int citymode);

void put_cross_overlay_tile(int x,int y);
void put_city_workers(struct city *pcity, int color);

void decrease_unit_hp_smooth(struct unit *punit0, int hp0, 
			     struct unit *punit1, int hp1);
void blink_active_unit(void);

void set_overview_dimensions(int x, int y);


void update_unit_pix_label(struct unit *punit);

void scrollbar_jump_callback(GtkAdjustment *adj, gpointer hscrollbar);
void update_map_canvas_scrollbars(void);
void update_map_canvas_scrollbars_size(void);
#endif
