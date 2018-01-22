/*
    src/example2.cpp -- C++ version of an example application that shows
    how to use the form helper class. For a Python implementation, see
    '../python/example2.py'.

    NanoGUI was developed by Wenzel Jakob <wenzel.jakob@epfl.ch>.
    The widget drawing code is based on the NanoVG demo application
    by Mikko Mononen.

    All rights reserved. Use of this source code is governed by a
    BSD-style license that can be found in the LICENSE.txt file.
*/


#include <nanogui/nanogui.h>
#include <iostream>
#include "widgets/w_robot_status_sensor.h"

using namespace nanogui;


std::string strval = "A string";
Color colval(0.5f, 0.5f, 0.7f, 1.f);

int main(int /* argc */, char ** /* argv */) {
    nanogui::init();

    /* scoped variables */ {
        Screen *screen = nullptr;


        screen = new Screen(Eigen::Vector2i(1024, 768), "DNT interface");
        //bool enabled = true;
        //FormHelper *gui = new FormHelper(screen);

        //ref<Window> window = gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");

        wRobotStatusSensor *robot_status_sensor_widget_ = new wRobotStatusSensor(screen);


        
        screen->setVisible(true);
        screen->drawAll();
        screen->performLayout();

        nanogui::mainloop();
    }

    nanogui::shutdown();
    return 0;
}
