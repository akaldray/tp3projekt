#include "planar_quadrotor_visualizer.h"
#include <cmath>
PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr) : quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer)
{
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0]; // frame 1280,720
    q_y = state[1];
    q_theta = state[2];
    SDL_Rect rect1 = {};
    SDL_Rect location;
    location.h = 20;
    location.w = 100;
    location.x = q_x + 640;
    location.y = q_y + 360;

    SDL_SetRenderDrawColor(gRenderer.get(), 0xFF, 0x00, 0x00, 0xFF);
   
    thickLineRGBA(gRenderer.get(), location.x - location.w / 2 * cos(q_theta), location.y - location.w / 2 * sin(q_theta), location.x + location.w / 2 * cos(q_theta), location.y + location.w / 2 * sin(q_theta), location.h, 20, 26, 26, 100);
    thickLineRGBA(gRenderer.get(), location.x -cos(0.927295+q_theta)*50, location.y - sin(0.643501+q_theta)*50, location.x -cos(0.321751+q_theta)*10*sqrt(10), location.y -sin(1.24905+q_theta)*10*sqrt(10), location.h/2, 20, 26, 26, 100);//left 
    thickLineRGBA(gRenderer.get(), location.x +cos(0.927295+q_theta)*50, location.y -sin(0.643501+q_theta)*50, location.x +cos(0.321751+q_theta)*10*sqrt(10), location.y -sin(1.24905+q_theta)*10*sqrt(10), location.h/2, 20, 26, 26, 100);//right
}