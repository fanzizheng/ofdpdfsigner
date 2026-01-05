//
//  Created by zizheng fan on 2022/11/21.
//
#ifndef FZZCOMMONUTIL_H
#define FZZCOMMONUTIL_H
class FZZCommonUtil
{
public:
    static double millimetersToPixel(double mm, double dpi) {
        //Millimeter to pixel:mm * dpi / 25.4
        return (double) (mm * dpi / 25.4f);
    }
    static double pixelToMillimeters(double px, double dpi) {
        //Pixel to mm : px * 25.4 / dpi
        return (double) ((px * 25.4f) / dpi);
    }

    /**
     * Get the number of pixels per millimeter under the specified DPI
     *
     * @param dpi Pixels per inch, such as 72
     * @return Pixels per mm
     * 
     */
    static double dpiToPpm(int dpi) {
        return ((0.01 / 0.254) * dpi);
    }
};

#endif //FZZCOMMONUTIL_H

