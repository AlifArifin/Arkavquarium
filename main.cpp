#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include "Aquarium.hpp"
#include "Matrix.hpp"
#include "Summonable.hpp"
#include "Account.hpp"
#include "Coin.hpp"
#include "Fish.hpp"
#include "Guppy.hpp"
#include "Piranha.hpp"
#include "ListObj.hpp"
#include "Point.hpp"
#include "Snail.hpp"

using namespace std;

int main( int argc, char* args[] )
{
    init();

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    bool running = true;
    bool quit = false;
    double delay = 0;
    // Inisiasi game
    srand(time(NULL));
    
    Aquarium aqu;
    Point p1(250,250), p2(200, 0), p3(200, SCREEN_HEIGHT);
    Guppy g1(p1);
    Food f1(p2);
    Snail s1(p3);

    aqu.add(g1);
    aqu.add(f1);
    aqu.add(s1);

    double prevtime = time_since_start();

    while (running) {
        srand(time(NULL));
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;
        delay -= sec_since_last;

        handle_input();
        if (quit_pressed()) {
            running = false;
            quit = true;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_tapped_keys()) {
            srand(time(NULL));
            switch (key) {
            case SDLK_1:    //beli guppy
                if (aqu.getAccount().buyGuppy()) {
                    Point ptemp(rand() % 640 - 1, rand() % 480 - 1);
                    Guppy gtemp(ptemp);
                    aqu.add(gtemp);
                } else {
                    
                }
                break;
            case SDLK_2:    //beli 
                if (aqu.getAccount().buyPiranha()) {
                    Point ptemp(rand() % 640 - 1, rand() % 480 - 1);
                    Piranha itemp(ptemp);
                    aqu.add(itemp);
                } else {

                }
                break;
            case SDLK_3:
                if (aqu.getAccount().buyFood()) {
                    Point ptemp(rand() % 640 - 1, rand() % 480 - 1);
                    Food ftemp(ptemp);
                    aqu.add(ftemp);
                } else {

                }
                break;
            case SDLK_4:
                if (aqu.getAccount().buyEgg()) {
                }
                break;
            }
        }

        if (delay < 0) {
            for (auto key : get_clicked_mouse()) {
                switch (key) {
                case SDL_BUTTON(SDL_BUTTON_LEFT) :
                    delay = 0.25;
                    int x, y;
                    SDL_GetMouseState(&x, &y);
                    Point ptemp(x, 0);
                    Point p1(x, y);
                    bool find = false;
                    
                    for (int i = 0; i < aqu.getList_Coin().size(); i++) {
                        if (p1.isInRadius(aqu.getList_Coin().get(i).getPosition(), Coin::getRadius_Coin())) {
                            find = true;
                            aqu.removeCoin(i);
                            break;
                        }
                    }

                    if (!find) {
                        if (aqu.getAccount().buyFood()) {
                            Food ftemp(ptemp);
                            aqu.add(ftemp);
                        }
                    }

                    break;
                }
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }

        //mengecek kondisi menang dan kalah
        if (aqu.getAccount().win()) {
            running = false;
        }

        if (aqu.lose()) {
            running = false;
        } 

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_image("Aquarium.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        
        // Menampilkan uang
        draw_text("Money : " + to_string(aqu.getAccount().getMoney()), 18, 500, 10, 0, 0, 0);
        draw_text("Egg   : " + to_string(aqu.getAccount().getEgg_Phase()), 18, 500, 40, 0, 0, 0);

        aqu.moveAll(sec_since_last);
        aqu.showAll();

        update_screen();
    }

    running = true;

    if (!quit) {
        while (running) {
            handle_input();
            if (quit_pressed()) {
                running = false;
            }
            for (auto key : get_tapped_keys()) {
                switch (key) {
                case SDLK_ESCAPE :
                    running = false;
                }
            }

            clear_screen();
            
            draw_image("Aquarium.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

            aqu.showAll();
                    
            if (aqu.lose()) {
                draw_image("lose.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            } else if (aqu.getAccount().win()) {
                draw_image("win.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            }
            
            update_screen();
        }
    }
    
    close();

    return 0;
}
