#include "game.h"

Game::Game() 
{
    init();
}

void Game::init() 
{
    current_level = 0;
    state = Menu; // Menu PlayGame
    refresh();
}

/* 
    Обновляем экран
*/
void Game::refresh() 
{
    switch (state)
    {
    case Menu:
        draw_menu();
        wait_for_start();        
        break;
    case PlayGame:
        game_loop();
        if(JOYPAD_DOWN_PRESSED) { 
            for (int i = 0; i < 20000; i++) {
                if (JOYPAD_DOWN_UNPRESSED) break;
            } 
            state = Menu; 
        } 
        break;
    case Win:
        draw_win();
        break;        
    case Fault:
        draw_fault();
        break;            
    default:
        break;
    }
}

void Game::draw_menu()
{
    oled.clear();
    oled.setScale(2);
    oled.setCursor(2<<3, 1);
    oled.print("ARCANOID");
    oled.setCursor(5, 5);
    oled.print("PRESS FIRE TO START");
    oled.update();
    oled.setScale(1);
}

void Game::game_loop()
{
    renderer.start();

    level_builder->draw();
    // Draw paddle
    paddle->move(control);
    paddle->draw();

    ball->draw_and_check_collisions();

    uint8_t remain_bricks = level_builder->handle_collisions(ball);
    if (remain_bricks < 1)
    {
        state = Win;
    } 

    handle_fault();
    renderer.render();
}

void Game::draw_win()
{
    // TODO: draw effect
    current_level += 1;
    // TODO: set next level or rotate to first
    oled.clear();
    oled.setScale(2);
    oled.setCursor(2<<3, 1);
    oled.print("YOU WIN!!!");
    delay(1000);
    oled.update();
    // TODO: play win music
    delay(2000);
    state = Menu;
}

void Game::draw_fault()
{
    // TODO: draw effect
    oled.setScale(2);
    oled.setCursor(1<<3, 3);
    oled.print("YOU LOSE!!!");
    oled.update();
    delay(3000);
    // TODO: play lose music
    state = Menu;
    //delete level_builder;
    //delete paddle;
    //delete ball;
}

void Game::handle_fault()
{
    if (level_builder->is_fault() || (ball->ball_state == DIE))
    {
        state = Fault;
    }
}

void Game::wait_for_start()
{
    if (control.read() && ((control.cross == 0) || (control.up == 0)))
    {
        while((control.cross == 0) || (control.up == 0)) { control.read(); delay(1); } // ждем отжатия кнопки
        state = PlayGame;
        current_level = 0;
        level_builder = new Level(current_level);
        paddle = new Paddle(((128-12) / 2), 56);
        ball = new Ball(((128-12) / 2) + 8, 50, this);
        // TODO: play start music
    }
}