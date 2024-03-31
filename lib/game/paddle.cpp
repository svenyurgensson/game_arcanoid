#include "paddle.h"

void Paddle::draw()
{
    renderer.draw_paddle(pos_x, pos_y);
}

const uint8_t steps[12] = {2, 2, 3, 3, 4, 4, 5, 6, 6, 8, 10, 12};
static constexpr uint8_t steps_count{sizeof(steps)};
static constexpr uint8_t max_right_x_pos = (127 - 24);

void Paddle::move(Joystick control)
{
    if (control.read())
    {
        if (control.left == 0 && pos_x > 0)
        {
            last_direction = -1;
            r_step_idx = 0;

            pos_x -= steps[l_step_idx];

            if (pos_x < 0)
                pos_x = 0;

            l_step_idx++;

            if (l_step_idx >= steps_count)
            {
                l_step_idx = steps_count - 1;
            }
        }

        if (control.right == 0 && pos_x < max_right_x_pos)
        {
            last_direction = 1;
            l_step_idx = 0;

            pos_x += steps[r_step_idx];

            if (pos_x > max_right_x_pos)
                pos_x = max_right_x_pos;

            r_step_idx++;

            if (r_step_idx >= steps_count)
            {
                r_step_idx = steps_count - 1;
            }
        }
    }
    else
    {
        l_step_idx = 0;
        r_step_idx = 0;
        last_direction = 0;
    }
}