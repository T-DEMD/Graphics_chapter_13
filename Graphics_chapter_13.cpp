#include "C:\Users\mkhit\OneDrive\Документы\fltk_gui\GUI\Simple_window.h"
#include "C:\Users\mkhit\OneDrive\Документы\fltk_gui\GUI\Graph.h"

// Chapter 13.
// Solved: 1, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19
// Not solvet: 3, 18
// Annotation:

using namespace Graph_lib;

//--------------------------------------------------------------------

struct Arch : Shape
{
	Arch() {};
	Arch(Point p, int rr);
	void draw_lines() const;
	Point center() const;
	int radius() const { return r; }
	int set_radius(int rr)
	{
		set_point(0, Point{ center().x - rr,center().y - rr });
		r = rr;
	}
private:
	int r;
};

Arch::Arch(Point p, int rr) : r(rr)
{
	add(Point{ p.x - r,p.y - r });
}

Point Arch::center() const
{
	return{ point(0).x + r, point(0).y + r };
}

void Arch::draw_lines()const
{
	if (color().visibility())
		fl_arc(point(0).x, point(0).y, r + r, r + r, 180, 360);
}

//--------------------------------------------------------------------

struct Box : Arch
{
	Box() { }
	void draw_lines()const;
	
	void add_box(Point xy, int w, int h)
	{
		width = w;
		height = h;
		int x, y = 0;
		x = xy.x;
		y = xy.y;
		add(Point{ x + corner,y });
		add(Point{ (x - corner) + w ,y });
		add(Point{ x + w,(y + corner) });
		add(Point{ x + w,(y - corner) + h });
		add(Point{ (x - corner) + w,y + h });
		add(Point{ (x + corner),y + h });
		add(Point{ x,(y - corner) + h });
		add(Point{ x,(y + corner) });
	}
	
private:
	int width = 0;
	int height = 0;
	int corner = 10;
};

void Box::draw_lines()const 
{
	if (color().visibility())
	{
		for (int i = 1; i < number_of_points(); i += 2)
		{
			fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
		}
			
		fl_arc(point(0).x - corner, point(0).y, corner + corner, corner + corner, 90, 180);
		fl_arc(point(0).x + (width - corner * 3), point(0).y, corner + corner, corner + corner, 0, 90);
		fl_arc(point(0).x - corner, point(0).y + (height - corner * 2), corner + corner, corner + corner, 180, 270);
		fl_arc(point(0).x + (width - corner * 3), point(0).y + (height - corner * 2), corner + corner, corner + corner, 270, 360);
	}
}

//--------------------------------------------------------------------

struct Designations_rect 
{
	friend class Rectangle;
	friend class Text;
	Designations_rect() {}
	Designations_rect(Graph_lib::Rectangle& rec) { /*get_funktion(rec);*/  }
	Point n(Graph_lib::Rectangle& rec);
	Point s(Graph_lib::Rectangle& rec);
	Point e(Graph_lib::Rectangle& rec);
	Point w(Graph_lib::Rectangle& rec);
	Point center(Graph_lib::Rectangle& rec);
	Point ne(Graph_lib::Rectangle& rec);   
	Point se(Graph_lib::Rectangle& rec);
	Point sw(Graph_lib::Rectangle& rec);
	Point nw(Graph_lib::Rectangle& rec);
};

Point Designations_rect::n(Graph_lib::Rectangle& rec)
{
	int xx;
	int yy;
	xx = rec.point(0).x + (rec.width() / 2);
	yy = rec.point(0).y;
	Point p{ xx,yy };
	return p;
}

Point Designations_rect::s(Graph_lib::Rectangle& rec)
{
	int xx;
	int yy;
	xx = rec.point(0).x + (rec.width() / 2);
	yy = rec.point(0).y + rec.height();
	Point p{ xx,yy + 10 };
	return p;
}

Point Designations_rect::e(Graph_lib::Rectangle& rec) 
{
	int xx;
	int yy;
	xx = rec.point(0).x + rec.width();
	yy = rec.point(0).y + (rec.height() / 2);
	Point p{ xx,yy };
	return p;
}

Point Designations_rect::w(Graph_lib::Rectangle& rec) 
{
	int xx;
	int yy;
	xx = rec.point(0).x;
	yy = rec.point(0).y + (rec.height() / 2);
	Point p{ xx - 15,yy };
	return p;
}

Point Designations_rect::center(Graph_lib::Rectangle& rec)
{
	int xx;
	int yy;
	xx = rec.point(0).x + (rec.width() / 2.5);
	yy = rec.point(0).y + (rec.height() / 2);
	Point p{ xx,yy };
	return p;
}

Point Designations_rect::ne(Graph_lib::Rectangle& rec)
{
	int xx;
	int yy;
	xx = rec.point(0).x + rec.width();
	yy = rec.point(0).y;
	Point p{ xx,yy };
	return p;
}

Point Designations_rect::se(Graph_lib::Rectangle& rec)
{
	int xx;
	int yy;
	xx = rec.point(0).x + rec.width();
	yy = rec.point(0).y + rec.height();
	Point p{ xx,yy + 10 };
	return p;
}

Point Designations_rect::sw(Graph_lib::Rectangle& rec)
{
	int xx;
	int yy;
	xx = rec.point(0).x;
	yy = rec.point(0).y + rec.height();
	Point p{ xx - 20,yy + 10 };
	return p;
}

Point Designations_rect::nw(Graph_lib::Rectangle& rec)
{
	int xx;
	int yy;
	xx = rec.point(0).x;
	yy = rec.point(0).y;
	Point p{ xx - 20,yy };
	return p;
}

//--------------------------------------------------------------------

struct Designations_ellipse
{
	friend class Ellipse;
	friend class Text;
	Designations_ellipse() {}
	Point n(Graph_lib::Ellipse& ell);
	Point s(Graph_lib::Ellipse& ell);
	//Point w(Graph_lib::Ellipse& ell);
	//Point e(Graph_lib::Ellipse& ell);
	Point c(Graph_lib::Ellipse& ell);
};

Point Designations_ellipse::n(Graph_lib::Ellipse& ell)
{
	int x;
	int y;
	x = ell.point(0).x + (ell.focus1().x * 0.1);
	y = ell.point(0).y;
	Point p{ x,y };
	return p;
}

Point Designations_ellipse::s(Graph_lib::Ellipse& ell)
{
	int x;
	int y;
	x = ell.point(0).x + (ell.focus1().x * 0.1);
	y = ell.point(0).y + ell.focus2().y * 0.4;
	Point p{ x,y };
	return p;
}

Point Designations_ellipse::c(Graph_lib::Ellipse& ell)
{
	int x;
	int y;
	x = ell.point(0).x + (ell.focus1().x * 0.1);
	y = ell.point(0).y + ell.focus2().y * 0.2;
	Point p{ x,y };
	return p;
}

//--------------------------------------------------------------------

struct Box_t : Shape
{
	using Shape::Shape;
	friend Text;
	Box_t() {}
	void draw_lines()const;
	void add_box(Point p);
	string label() const
	{
		return lab;
	}
	void set_point(){}
private:
	string lab = "TEXT";
	int width;
	int height;
	int line;
};

void Box_t::draw_lines()const
{
	if (color().visibility())
	{
		for(int i = 1; i < number_of_points(); i += 2)
		{
			fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
			fl_draw(lab.c_str(), point(0).x, point(0).y);
			fl_draw(lab.c_str(), point(1).x, point(1).y);
			fl_draw(lab.c_str(), point(1).x + 30, point(1).y + 50);
		}
	}
}

void Box_t::add_box(Point p)
{
	int xx, yy;
	int width = 150;
	int height = 40;
	xx = p.x;
	yy = p.y;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });

	add(Point{ xx + width,yy + height });
	xx *= 3;
	add(Point{ xx + (width / 2),yy + (height + 60) });
	add(Point{ xx + width / 2,yy + height });
	add(Point{ xx + (width / 2),yy + (height + 60) });

	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });
	
	xx *= 1.7;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });

	xx = p.x;
	yy *= 2;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });

	xx *= 3;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });

	xx *= 1.7;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });

	xx = p.x;
	yy *= 1.5;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });

	xx *= 3;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });

	xx *= 1.7;
	add(Point{ xx,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy });
	add(Point{ xx + width,yy + height });
	add(Point{ xx + width,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy + height });
	add(Point{ xx,yy });
}

//--------------------------------------------------------------------

struct Right_triangle : Shape
{
	Right_triangle(Point p, int hh, int ww, string s);
	void add();
	void draw_line()const
	{
		if (color().visibility())
		{
			for (int i = 1; i < number_of_points(); i += 2)
			{
				fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
				fl_color(fill_color().as_int());
				fl_begin_complex_polygon();
				for (int i = 0; i < number_of_points(); ++i) {
					fl_vertex(point(i).x, point(i).y);
				}
				fl_end_complex_polygon();
				fl_color(color().as_int());
			}
		}
	}

	void north_west();
	void north_east();
	void south_east();
	void south_west();

private:
	int h;
	int w;
	string s;
	Point p;
};

Right_triangle::Right_triangle(Point pp, int hh, int ww, string ss) : h{hh}, w{ww}, p{pp}, s{ss}
{
	add();
}

void Right_triangle::add()
{
	if (s == "NW")
	{
		north_west();
	}
	if (s == "NE")
	{
		north_east();
	}
	if (s == "SE")
	{
		south_east();
	}
	if (s == "SW")
	{
		south_west();
	}
}

void Right_triangle::north_east() 
{
	Point px;
	Point py;
	px.x = p.x + w;
	px.y = p.y;
	py.x = p.x;
	py.y = p.y - h;
	Shape::add(p);
	Shape::add(px);
	Shape::add(px);
	Shape::add(py);
	Shape::add(py);
	Shape::add(p);
}

void Right_triangle::north_west() 
{
	Point px, py;
	px.x = p.x - w;
	px.y = p.y;
	py.x = p.x;
	py.y = p.y - h;
	Shape::add(p);
	Shape::add(px);
	Shape::add(px);
	Shape::add(py);
	Shape::add(py);
	Shape::add(p);
}

void Right_triangle::south_east() 
{
	Point px, py;
	px.x = p.x + w;
	px.y = p.y;
	py.x = p.x;
	py.y = p.y + h;
	Shape::add(p);
	Shape::add(px);
	Shape::add(px);
	Shape::add(py);
	Shape::add(py);
	Shape::add(p);
}
void Right_triangle::south_west() 
{
	Point px, py;
	px.x = p.x - w;
	px.y = p.y;
	py.x = p.x;
	py.y = p.y + h;
	Shape::add(p);
	Shape::add(px);
	Shape::add(px);
	Shape::add(py);
	Shape::add(py);
	Shape::add(p);
}

//struct Regular_rectangle : Shape // ñäåëàë â ôàéëå	3-7-13
//{
//	Regular_rectangle(){}
//	Regular_rectangle(Point p, int R, int cor);
//	Regular_rectangle(Point p, int R, string cor);
//	void draw_lines()const 
//	{
//		if (color().visibility())
//		{
//			for (int i = 1; i < number_of_points(); i+=2)
//			{
//				fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
//			}
//		}
//	}
//	void add(int c);
//	void triangle();
//	void square();
//	void pentagon();
//	void hexagon();
//
//private:
//	int corner;
//	int s_corner;
//	int R;
//	int r;
//};
//
//Regular_rectangle::Regular_rectangle(Point p, int R, int cor)
//{
//	add(cor);
//}
//void Regular_rectangle::add(int c)
//{
//	switch (c)
//	{
//	case 3:
//		triangle();
//	case 4:
//		square();
//	case 5:
//		pentagon();
//	case 6:
//		hexagon();
//		break;
//	}
//}
//void Regular_rectangle::triangle()
//{
//
//}
//void Regular_rectangle::square()
//{
//
//}
//void Regular_rectangle::pentagon()
//{
//
//}
//void Regular_rectangle::hexagon()
//{
//
//}

//--------------------------------------------------------------------

struct Test_rectangle : Rectangle
{
	using Rectangle::Rectangle;
	void draw_lines()const;
	
private:
	Point p;
};

void Test_rectangle::draw_lines() const
{
	Rectangle::draw_lines();
	if (2 > number_of_points() && color().visibility())
	{
		fl_line(point(number_of_points() - 1).x, point(number_of_points() - 1).y, (point(number_of_points() - 1).x + width() / 2), (point(number_of_points() - 1).y - height() / 2));
		fl_line(point(number_of_points() - 1).x + width(), point(number_of_points() - 1).y, (point(number_of_points() - 1).x + width() / 2), (point(number_of_points() - 1).y - height() / 2));
	}
}

//--------------------------------------------------------------------

int main()
{
	Point t1(400, 300);

	Simple_window win(t1, 600, 400, "Canvas");
	Line horizontal{ Point{100,100},Point{200,100} };
	Line vertical{ Point{150,50}, Point {150,150} };
	Lines x;
	x.add(Point{ 300,100 }, Point{ 500,100 });
	x.add(Point{ 350,50 }, Point{ 350,150 });
	horizontal.set_color(Color::dark_cyan);
	vertical.set_color(Color::black);
	x.set_color(Color::green);
	win.attach(horizontal);
	win.attach(vertical);
	win.attach(x);
	win.wait_for_button();

	Simple_window win2(t1, 900, 700, "Grid");
	int x_size = win2.x_max();
	int y_size = win2.y_max();
	int x_grid = 80;
	int y_grid = 40;
	Lines grid;
	for (int x = x_grid; x < x_size; x+=x_grid)
	{
		grid.add(Point{ x,0 }, Point{ x,y_size });
	}
	for (int y = y_grid; y < y_size; y+=y_grid)
	{
		grid.add(Point{ 0,y }, Point{ x_size,y });
	}
	Graph_lib::Lines xx;
	xx.add(Point{ 70,30 }, Point{ 400,140 } );
	xx.set_color(Color(120));
	xx.set_style(Line_style(Line_style::solid, 5));
	grid.set_style(Line_style::dash);
	grid.set_color(Color::black);
	win2.attach(grid);
	win2.attach(xx);
	win2.wait_for_button();
	Simple_window win3{ t1,900,700,"color" };
	Vector_ref<Graph_lib::Rectangle> rect;
	Graph_lib::Rectangle n{ Point{100,200},150,270 };
	n.set_color(Color::blue);
	n.set_fill_color(Color::blue);
	Text t{ Point{100,200}, "Point 100x200" };
	rect.push_back(n);
	rect.push_back(new Graph_lib::Rectangle{ Point{50,60},Point{120,130} });
	win3.attach(n);
	win3.attach(t);
	Arch arc(Point{ 300,300 }, 50);
	arc.set_color(Color::white);
	win3.attach(arc);
	win3.wait_for_button();
	for (int i = 0; i < rect.size(); ++i)
	{
		rect[i].move(50, 50);
		rect[rect.size() - 1].set_fill_color(Color::yellow);
		win3.attach(rect[rect.size() - 1]);
	}
	n.set_color(Color::red);
	win3.wait_for_button();
	Simple_window win4{ t1,900,700,"16*16 color matrix" };
	Vector_ref<Graph_lib::Rectangle> vr;
	for (int i = 0; i < 16; ++i)
	{
		for(int j = 0; j < 16; ++j)
		{
			vr.push_back(new Graph_lib::Rectangle{ Point{i * 20,j * 20},22,22 });
			vr[vr.size() - 1].set_fill_color(Color{ i * 16 + j });
			vr[vr.size() - 1].set_color(Color{ i * 16 + j }); // 13 óïð.
			win4.attach(vr[vr.size() - 1]);
		}
	}
	win4.wait_for_button();

	Simple_window win5{ t1,900,700,"box" };
	Box b;
	b.add_box(Point{ 150,150 }, 300, 200);
	b.set_color(Color::yellow);
	b.set_style(Line_style(Line_style::solid,2));
	Box c;
	c.add_box(Point{ 300,300 }, 400, 200);
	c.set_color(Color::cyan);
	c.set_style(Line_style(Line_style::solid, 5));
	win5.attach(b);
	win5.attach(c);
	win5.wait_for_button();
	
	Simple_window win6{ t1,900,700,"Point" };
	Graph_lib::Rectangle rec(Point{ 200,200 }, 130, 140);
	rec.set_color(Color::green);
	Designations_rect dr(rec);
	
	Text nord(dr.n(rec), "N");
	nord.set_color(Color::black);
	win6.attach(nord);
	Text south(dr.s(rec), "S");
	nord.set_color(Color::black);
	win6.attach(south);
	Text west(dr.w(rec), "W");
	nord.set_color(Color::black);
	win6.attach(west);
	Text east(dr.e(rec), "E");
	nord.set_color(Color::black);
	win6.attach(east);
	Text nord_west(dr.nw(rec), "NW");
	nord.set_color(Color::black);
	win6.attach(nord_west);
	Text south_west(dr.sw(rec), "SW");
	nord.set_color(Color::black);
	win6.attach(south_west);
	Text south_east(dr.se(rec), "SE");
	nord.set_color(Color::black);
	win6.attach(south_east);
	Text nord_east(dr.ne(rec), "NE");
	nord.set_color(Color::black);
	win6.attach(nord_east);
	Text center_(dr.center(rec), "Center");
	nord.set_color(Color::black);
	win6.attach(center_);
	win6.attach(rec);

	Graph_lib::Ellipse ell(Point{ 400,400 }, 40, 70);
	ell.set_color(Color::blue);
	win6.attach(ell);
	Graph_lib::Ellipse ell1(Point{ 500,500 }, 50, 80);
	ell1.set_color(Color::cyan);
	win6.attach(ell1);
	
	Designations_ellipse de;
	Text tc(de.c(ell), "Ellipse");
	Text tn(de.n(ell), "N");
	Text ts(de.s(ell), "S");
	tc.set_color(Color::black);
	tn.set_color(Color::black);
	ts.set_color(Color::black);
	win6.attach(tc);
	win6.attach(tn);
	win6.attach(ts);

	Designations_ellipse de1;
	Text tc1(de1.c(ell1), "Ellipse");
	Text tn1(de1.n(ell1), "N");
	Text ts1(de1.s(ell1), "S");
	tc1.set_color(Color::red);
	tn1.set_color(Color::red);
	ts1.set_color(Color::red);
	win6.attach(tc1);
	win6.attach(tn1);
	win6.attach(ts1);

	win6.wait_for_button();

	Simple_window win7{ t1,900,700,"Box_t" };

	Box_t bt;
	bt.add_box(Point{ 100,100 });
	bt.set_color(Color::black);
	bt.label();
	win7.attach(bt);
	Graph_lib::Ellipse ell2(Point{ 400,300 }, 300, 200);
	Graph_lib::Line lx(Point{ 50,300 }, Point{ 450,300 });
	Graph_lib::Line ly(Point{ 400,350 }, Point{ 400,50 });
	lx.set_color(Color::black);
	ly.set_color(Color::black);
	ell2.set_color(Color::dark_cyan);
	win7.attach(ell2);
	win7.attach(lx);
	win7.attach(ly);
	Graph_lib::Text txt_x(Point{ 150,313 }, "Fx");
	Graph_lib::Text txt_y(Point{ 403,200 }, "Fy");
	txt_x.set_color(Color::dark_blue);
	txt_y.set_color(Color::dark_blue);
	win7.attach(txt_x);
	win7.attach(txt_y);
	Graph_lib::Line line_px(Point{ 150,300 }, Point{ 300,112 });
	Graph_lib::Line line_py(Point{ 300,112 }, Point{ 400,200 });
	line_px.set_color(Color::cyan);
	line_py.set_color(Color::cyan);
	win7.attach(line_px);
	win7.attach(line_py);

	Graph_lib::Ellipse ell3(Point{ 500,300 }, 300, 200);
	Text txt_focus1(ell3.focus1(), "focus1");
	Text txt_focus2(ell3.focus2(), "focus2");

	Point start_line;
	Point end_line;
	Point p1;

	if (ell3.major() >= ell3.minor())
	{
		start_line.x = ell3.focus1().x + 100;
		start_line.y = ell3.focus1().y;
		end_line.x = ell3.focus2().x - 100;
		end_line.y = ell3.focus2().y;
		p1.x = ell3.center().x;
		p1.y = ell3.focus2().y - ell3.minor();
	}
	else
	{
		start_line.x = ell3.focus1().x;
		start_line.y = ell3.focus1().y + 100;
		end_line.x = ell3.focus2().x;
		end_line.y = ell3.focus2().y - 100;
		p1.x = ell3.center().x - ell3.minor() / 2;
		p1.y = ell3.focus2().y + ell3.major();
	}
	Line line_x(start_line, end_line);
	Line lxx(p1, ell3.focus1());
	Line lyy(p1, ell3.focus2());
	ell3.set_color(Color::red);
	txt_focus1.set_color(Color::dark_blue);
	txt_focus2.set_color(Color::dark_blue);
	line_x.set_color(Color::green);
	lxx.set_color(Color::dark_green);
	lyy.set_color(Color::dark_green);
	win7.attach(ell3);
	win7.attach(line_x);
	win7.attach(lxx);
	win7.attach(lyy);
	win7.attach(txt_focus1);
	win7.attach(txt_focus2);

	int px = 50;
	int py = 50;
	Graph_lib::Ellipse ell4(Point{ 200,200 }, px, py);
	Point point_spher(200, 150);
	Text txt_spher(point_spher, "X");
	txt_spher.set_color(Color::black);
	ell4.set_color(Color::magenta);
	win7.attach(txt_spher);
	win7.attach(ell4);

	win7.wait_for_button();
	Simple_window win8(t1, 900, 700, "WIN8");
	ell4.move(20, 0);
	txt_spher.move(27, 2);
	ell4.set_color(Color::dark_magenta);
	txt_spher.set_color(Color::yellow);
	win8.attach(ell4);
	win8.attach(txt_spher);

	Right_triangle nw{ Point{350,300},100,100, "NW"};
	nw.set_color(Color::cyan);
	win8.attach(nw);

	Graph_lib::Polygon poly_n;
	poly_n.add(Point{ 350,200 });
	poly_n.add(Point{ 450,200 });
	poly_n.add(Point{ 400,250 });
	poly_n.set_color(Color::red);
	win8.attach(poly_n);

	Right_triangle ne{ Point{450,300},100,100, "NE" };
	ne.set_color(Color::yellow);
	win8.attach(ne);

	Graph_lib::Polygon poly_e;
	poly_e.add(Point{ 550,400 });
	poly_e.add(Point{ 550,300 });
	poly_e.add(Point{ 500,350 });
	poly_e.set_color(Color::red);
	win8.attach(poly_e);

	Right_triangle se{ Point{450,400},100,100, "SE" };
	se.set_color(Color::green);
	win8.attach(se);

	Graph_lib::Polygon poly_s;
	poly_s.add(Point{ 350,500 });
	poly_s.add(Point{ 450,500 });
	poly_s.add(Point{ 400,450 });
	poly_s.set_color(Color::red);
	win8.attach(poly_s);

	Right_triangle sw{ Point{350,400},100,100, "SW" };
	sw.set_color(Color::black);
	win8.attach(sw);

	Graph_lib::Polygon poly_w;
	poly_w.add(Point{ 250,400 });
	poly_w.add(Point{ 250,300 });
	poly_w.add(Point{ 300,350 });
	poly_w.set_color(Color::red);
	win8.attach(poly_w);

	win8.wait_for_button();

	Simple_window win9(t1, 900, 700, "WIN9");
	ell4.move(20, 0);
	txt_spher.move(31, 3);
	ell4.set_color(Color::magenta);
	txt_spher.set_color(Color::blue);
	win9.attach(ell4);
	win9.attach(txt_spher);

	Right_triangle rt_1(Point{ 400,200 }, 20, 35, "NW");
	Right_triangle rt_2(Point{ 440,190 }, 25, 20, "SW");
	Right_triangle rt_3(Point{ 470,210 }, 24, 43, "SE");
	Right_triangle rt_4(Point{ 370,230 }, 20, 25, "NE");
	Right_triangle rt_5(Point{ 434,235 }, 18, 20, "NW");
	Right_triangle rt_6(Point{ 400,205 }, 20, 25, "SW");
	Right_triangle rt_7(Point{ 360,175 }, 20, 35, "SE");
	Right_triangle rt_8(Point{ 410,215 }, 36, 20, "NE");
	rt_1.set_color(Color::green);
	rt_1.set_fill_color(Color::green);
	rt_2.set_color(Color::red);
	rt_3.set_color(Color::cyan);
	rt_4.set_color(Color::yellow);
	rt_5.set_color(Color::black);
	rt_5.set_fill_color(Color::black);
	rt_6.set_color(Color::black);
	rt_7.set_color(Color::dark_blue);
	rt_8.set_color(Color::blue);
	win9.attach(rt_1);
	win9.attach(rt_2);
	win9.attach(rt_3);
	win9.attach(rt_4);
	win9.attach(rt_5);
	win9.attach(rt_6);
	win9.attach(rt_7);
	win9.attach(rt_8);

	win9.wait_for_button();

	Simple_window win10(t1, 900, 700, "WIN10");
	ell4.move(20, 0);
	txt_spher.move(35, 6);
	ell4.set_color(Color::dark_magenta);
	ell4.set_fill_color(Color::dark_magenta);
	txt_spher.set_color(Color::yellow);
	win10.attach(ell4);
	win10.attach(txt_spher);

	Test_rectangle r(Point{ 200,300 }, 200, 100);
	r.set_color(Color::red);
	r.set_fill_color(Color::red);
	win10.attach(r);

	win10.wait_for_button();

	return 0;
}