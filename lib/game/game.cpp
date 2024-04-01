#include "game.h"

Game::Game() 
{
    init();
}

void Game::init() 
{
    current_level = 0;
    state = Menu; // Menu PlayGame     

    for (int i = 0; i< 100; i++) {
        oled.circle(64, 32, i, 1);
        oled.update();
        delay(1);
    }

    counter = 0;
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
    current_level += 1;
    if (current_level >= levels_count) current_level = 0; // Если прошли последний уровень возвращаемся к 0 
    oled.clear();
    oled.drawBitmap(0, 0, bitmap_win, 128, 64);
    oled.setScale(1);
    oled.setCursor(2<<3, 1);
    oled.print("YOU WIN!!!");
    oled.update();
    audio_command_play(WIN);    
    delay(1000);
    wait_for_start();
    state = PlayGame;
}

void Game::draw_fault()
{
    // TODO: draw effect
    oled.clear();
    oled.drawBitmap(0, 0, fail1, 128, 64);
    oled.setScale(2);
    oled.setCursor(1, 0);
    oled.print("YOU LOSE!!!");
    audio_command_play(FAIL);
    oled.update();
    delay(6000);
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

const int max_counter = 20;

void Game::draw_menu()
{
    oled.clear();
    oled.drawBitmap(0, 0, arcanoid2, 128, 64);
    oled.setScale(1);
    if (counter > max_counter) {
        oled.textMode(BUF_ADD);
        oled.setCursor(5, 7);
        oled.print("PRESS FIRE TO START");
        if (counter > (2 * max_counter))
            counter = 0;
    }     
    counter++;
    oled.update();
}

void Game::wait_for_start()
{
    wait_until_start_pressed();
    if (control.read() && ((control.cross == 0) || (control.up == 0)))
    {
        wait_until_start_pressed();
        state = PlayGame;
        current_level = 0;
        // Первоначальные положения биты, мяча и кирпичей
        level_builder = new Level(current_level);
        paddle = new Paddle(((128-12) / 2), 56);
        ball = new Ball(((128-12) / 2) + 8, 50, this);
        // TODO: play start music
        audio_command_play(START);
    }
}

// ждем отжатия кнопки старт
void Game::wait_until_start_pressed()
{
    while((control.cross == 0) || (control.up == 0)) { control.read(); delay(1); } 
}