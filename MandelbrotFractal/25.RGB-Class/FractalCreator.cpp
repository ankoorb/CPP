//
// Created by Ankoor Bhagat on 8/21/18.
//

#include "FractalCreator.h"
#include "Mandelbrot.h"

namespace fractal {

    void FractalCreator::run(string name) {
        addZoom(Zoom(295, m_height - 202, 0.1));
        addZoom(Zoom(312, m_height - 304, 0.1));
        calculateIteration();
        calculateTotalIterations();
        drawFractal();
        writeBitmap(name);
    }

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

    void FractalCreator::drawFractal() {
        for(int x=0; x<m_width; x++){
            for(int y=0; y<m_height; y++){

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;

                int iterations = m_fractal[y * m_width + x];

                if(iterations != Mandelbrot::MAX_ITERATIONS){
                    uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

                    double hue = 0;

                    for(int i=0; i<=iterations; i++){
                        hue += ((double)m_histogram[i])/m_total;
                    }

                    //red = pow(255, hue);
                    red = hue * 255;
                }

                m_bitmap.setPixel(x, y, red, green, blue);

            }
        }
    };

    void FractalCreator::addZoom(const Zoom &zoom) {
        m_zoomlist.add(zoom);
    };

    void FractalCreator::writeBitmap(string name) {
        m_bitmap.write(name);
    };

}