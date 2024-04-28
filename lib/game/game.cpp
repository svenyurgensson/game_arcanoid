#include "game.h"

Game::Game() 
{
    init();
}

void Game::init() 
{
    state = Menu; // Menu PlayGame     

    for (int i = 0; i< 100; i++) {
        oled.circle(64, 32, i, 0xff);
        oled.update();
        delay(1);
    }

    blink_counter = 0;
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
        current_level = 0;    
        draw_press_fire();
        check_for_start_pressed();        
        break;
    case PlayGame:
        game_loop();        
        if(JOY_BOTH_LEFT_RIGHT_PRESSED) state = Menu; 
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

    paddle->move(control);
    paddle->draw();

    ball->draw_and_check_collisions();

    uint8_t remain_bricks = level_builder->handle_collisions(ball);
    if (remain_bricks < 1) state = Win;

    check_fault();
    renderer.render(current_level);
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
    check_for_start_pressed();
    state = PlayGame;
}

void Game::draw_fault()
{
    oled.clear();
    oled.drawBitmap(0, 0, fail1, 128, 64);
    oled.setScale(2);
    oled.setCursor(0, 0);
    oled.print("++ FAIL ++");    
    oled.update();
    audio_command_play(FAIL);

    delay(6000);
    state = Menu;
    //delete level_builder;
    //delete paddle;
    //delete ball;
}

void Game::check_fault()
{
    if (level_builder->is_fault() || (ball->ball_state == DIE))
    {
        state = Fault;
    }
}

const int max_counter = 20;

void Game::draw_press_fire()
{
    oled.clear();
    oled.drawBitmap(0, 0, arcanoid2, 128, 64);
    oled.setScale(1);
    if (blink_counter > max_counter) {
        oled.textMode(BUF_ADD);
        oled.setCursor(5, 7);
        oled.print("PRESS FIRE TO START");
        if (blink_counter > (2 * max_counter))
            blink_counter = 0;
    }  
    blink_counter++;
    oled.update();
}

void Game::check_for_start_pressed()
{
    if (is_start_pressed())
    {
        state = PlayGame;        
        // Первоначальные положения биты, мяча и кирпичей
        level_builder = new Level(current_level);
        paddle = new Paddle(((128-12) / 2), 56);
        ball = new Ball(((128-12) / 2) + 8, 50, this);        
    }
}

bool Game::is_start_pressed()
{
    return (control.read() && (control.up == 0));
}

// ждем отжатия кнопки старт
void Game::wait_until_start_pressed()
{
    while(is_start_pressed()) { delay(1); } 
}