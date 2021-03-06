// ColorGrab
// Copyright (c) 2015 Niels Sonnich Poulsen (http://nielssp.dk)
// Licensed under the MIT license.
// See the LICENSE file or http://opensource.org/licenses/MIT for more information.

#ifndef COLORMODELS_H
#define COLORMODELS_H

#include <wx/colour.h>

/// Conversion between color models.
class IColorModel
{
public:
    virtual ~IColorModel(){};

    virtual std::string getName() const = 0;
    virtual wxColour getColor() const = 0;
    virtual std::string getLabel(int i) const = 0;
    virtual int getNumComponents() const = 0;
    virtual int getValue(int i) const = 0;
    virtual int getMin(int i) const = 0;
    virtual int getMax(int i) const = 0;
    virtual void setColor(const wxColour& color) = 0;
    virtual void setValue(int i, int value) = 0;
};

/// Red, green, blue.
class RGBModel : public IColorModel
{
private:
    wxColour color;
    
public:
    virtual std::string getName() const;
    virtual wxColour getColor() const;
    virtual std::string getLabel(int i) const;
    virtual int getNumComponents() const;
    virtual int getValue(int i) const;
    virtual int getMin(int i) const;
    virtual int getMax(int i) const;
    virtual void setColor(const wxColour& color);
    virtual void setValue(int i, int value);
};

int hueToRgb(double m1, double m2, double hue);
wxColour hslToRgb(double h, double s, double l);

/// Hue, saturation, lightness.
class HSLModel : public IColorModel
{
private:
    int h;
    int s;
    int l;

public:
    virtual std::string getName() const;
    virtual wxColour getColor() const;
    virtual std::string getLabel(int i) const;
    virtual int getNumComponents() const;
    virtual int getValue(int i) const;
    virtual int getMin(int i) const;
    virtual int getMax(int i) const;
    virtual void setColor(const wxColour& color);
    virtual void setValue(int i, int value);
};

wxColour hsvToRgb(double h, double s, double l);

/// Hue, saturation, value.
class HSVModel : public IColorModel
{
private:
    int h;
    int s;
    int v;

public:
    virtual std::string getName() const;
    virtual wxColour getColor() const;
    virtual std::string getLabel(int i) const;
    virtual int getNumComponents() const;
    virtual int getValue(int i) const;
    virtual int getMin(int i) const;
    virtual int getMax(int i) const;
    virtual void setColor(const wxColour& color);
    virtual void setValue(int i, int value);
};

/// Cyan, magenta, yellow, key.
class CMYKModel : public IColorModel
{
private:
    int c;
    int m;
    int y;
    int k;

public:
    virtual std::string getName() const;
    virtual wxColour getColor() const;
    virtual std::string getLabel(int i) const;
    virtual int getNumComponents() const;
    virtual int getValue(int i) const;
    virtual int getMin(int i) const;
    virtual int getMax(int i) const;
    virtual void setColor(const wxColour& color);
    virtual void setValue(int i, int value);
};

#endif // colormodels_H