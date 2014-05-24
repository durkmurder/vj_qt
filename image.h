/*
 *  TU Eindhoven
 *  Eindhoven, The Netherlands
 *
 *  Name            :   image.h
 *
 *  Author          :   Francesco Comaschi (f.comaschi@tue.nl)
 *
 *  Date            :   November 12, 2012
 *
 *  Function        :   Functions to manage .pgm images and integral images
 *
 *  History         :
 *      12-11-12    :   Initial version.
 *
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program;  If not, see <http://www.gnu.org/licenses/>
 *
 * In other words, you are welcome to use, share and improve this program.
 * You are forbidden to forbid anyone else to use, share and improve
 * what you give them.   Happy coding!
 */

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>

struct MyImage
{
    int width;
    int height;
    int maxgrey;
    unsigned char* data;
    int flag;
};

struct MyIntImage
{
    int width;
    int height;
    int* data;
    int flag;
};

class Image
{
public:
    Image();
    Image(MyImage *im);
    ~Image();
    int readPgm(char *fileName);
    int writePgm(char *fileName);
    int cpyPgm(MyImage *dst);
    void createImage(int width, int height);
    void createSumImage(int width, int height);
    int freeImage();
    int freeSumImage();
    void setImage(int width, int height);
    void setSumImage(int width, int height);
    const unsigned char *data() const;
    const int width() const;
    const int height() const;

private:
    MyImage *image;
    MyIntImage *intImage;
};

#endif
