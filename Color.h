#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct Color
{
    unsigned char r,g,b;
    Color();
    Color(int r,int g,int b);
    Color(unsigned char r,unsigned char g,unsigned char b);
};

#endif // COLORHEADER_H_INCLUDED
