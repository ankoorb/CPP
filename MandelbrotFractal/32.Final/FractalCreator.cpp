//
// Created by Ankoor Bhagat on 8/21/18.
//

#include <iostream>
#include <assert.h>
#include "FractalCreator.h"
#include "Mandelbrot.h"
using namespace std;

namespace fractal {

    void FractalCreator::run(string name) {
        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();
        writeBitmap(name);
    }

    void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
        m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
        m_colors.push_back(rgb);

        if(m_bGotFirstRange){
            m_rangeTotals.push_back(0);
        }

        m_bGotFirstRange = true;

    }

    int FractalCreator::getRange(int iterations) const {
        int range = 0;

        for(int i=1; i<m_ranges.size(); i++){
            range = i;
            if(m_ranges[i] > iterations){
                break;
            }
        }

        range--;

        assert(range > -1);
        assert(range < m_ranges.size());

        return range;
    }

    void FractalCreator::addZoom(const Zoom &zoom) {
        m_zoomlist.add(zoom);
    };

    FractalCreator::FractalCreator(int width, int height):
            m_width(width),
            m_height(height),
            m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{}),
            m_fractal(new int[m_width * m_height]{}),
            m_bitmap(m_width, m_height),
            m_zoomlist(m_width, m_height){

        m_zoomlist.add(Zoom(m_width/2, m_height/2, 4.0/m_width));

    };

    FractalCreator::~FractalCreator() {};

    void FractalCreator::calculateIteration() {
        for(int x=0; x<m_width; x++){
            for(int y=0; y<m_height; y++){
                pair<double, double> coords = m_zoomlist.doZoom(x, y);

                int iterations = Mandelbrot::getIterations(coords.first, coords.second);

                m_fractal[y * m_width + x] = iterations;

                if(iterations != Mandelbrot::MAX_ITERATIONS){
                    m_histogram[iterations]++;  // Incrementing pointer
                }
            }
        }
    };

    void FractalCreator::calculateTotalIterations() {
        for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){
            m_total += m_histogram[i];
        }
    }

    void FractalCreator::calculateRangeTotals() {

        int rangeIndex = 0;

        for(int i=0; i<Mandelbrot::MAX_ITERATIONS; i++){
            int pixels = m_histogram[i];

            if(i >= m_ranges[rangeIndex + 1]){
                rangeIndex++;
            }

            m_rangeTotals[rangeIndex] += pixels;
        }
    }

    void FractalCreator::drawFractal() {

        RGB startColor(0, 0, 00);
        RGB endColor(0, 0, 255);

        RGB colorDiff = endColor - startColor;

        for(int x=0; x<m_width; x++){
            for(int y=0; y<m_height; y++){

                int iterations = m_fractal[y * m_width + x];
                int range = getRange(iterations);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                RGB& startColor = m_colors[range];
                RGB& endColor = m_colors[range + 1];
                RGB colorDiff = endColor - startColor;

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                if(iterations != Mandelbrot::MAX_ITERATIONS){

                    int totalPixels = 0;

                    for(int i=rangeStart; i<=iterations; i++){
                        totalPixels += m_histogram[i];
                    }

                    red = startColor.r + colorDiff.r * totalPixels/(double)rangeTotal;
                    green = startColor.g + colorDiff.g * totalPixels/(double)rangeTotal;
                    blue = startColor.b + colorDiff.b * totalPixels/(double)rangeTotal;
                }

                m_bitmap.setPixel(x, y, red, green, blue);

            }
        }
    };

    void FractalCreator::writeBitmap(string name) {
        m_bitmap.write(name);
    };

}
