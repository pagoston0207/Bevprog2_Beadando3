#include "Sprite.h"
#include <iostream>
#include <fstream>
using genv::gout;
using genv::stamp;
using genv::move_to;
using genv::color;
using genv::dot;
using genv::box;
using std::ifstream;
using std::cerr;
using std::endl;
Sprite::Sprite( Vector2 _size, Widget* _parent,string _graphicFileName):  Widget(_size,_parent), graphicFileName(_graphicFileName)
{
    InitializeSprite();
}
void Sprite::Print()
{
    if(!enabled)
        return;
    Widget::Print();
    gout<<stamp(_canvas,GetWorldPos().x-size.x/2,GetWorldPos().y-size.y/2);
}
void Sprite::SetGraphic(string path)
{
    if(graphicFileName != path)
    {
        graphicFileName = path;
        InitializeSprite();
    }
}
void Sprite::InitializeSprite()
{
    _canvas.open(size.x,size.y);
    if(graphicFileName != "")
    {
        ifstream f(graphicFileName);
        if(!f.good())
        {
            cerr<<"Baj van a fájl megnyitásával"<<endl;
        }
        else
        {
            int XX;
            int YY;
            f>>XX>>YY;
            int r,g,b;
            bool found=false;
            for(int c=0; c<10&&!found;c++)
            {
                if((XX*c==size.x&&YY*c==size.y))
                {
                    found=true;
                    for(int i =0;i<YY;i++)
                    {
                        for(int j=0;j<XX;j++)
                        {
                            f>>r>>g>>b;
                            for(int k =0; k<c; k++)
                            {
                                for(int l=0;l<c;l++)
                                {
                                    _canvas<<move_to(j*c+k,i*c+l)<<color(r,g,b)<<dot;
                                }

                            }
                        }
                    }
                }

            }
        }
    }
    else
    {
        int r =125;
        _canvas<<move_to(0,0)<<color(r,r,r)<<box(size.x,size.y);
        _canvas<<move_to(size.x*0.1,size.y*0.1)<<color(255,255,255)<<box(size.x*0.8,size.y*0.8);
    }
}
