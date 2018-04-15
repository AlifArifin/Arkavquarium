#include "src/oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include "src/Aquarium.hpp"
#include "src/Matrix.hpp"
#include "src/Summonable.hpp"
#include "src/Account.hpp"
#include "src/Coin.hpp"
#include "src/Fish.hpp"
#include "src/Guppy.hpp"
#include "src/Piranha.hpp"
#include "src/ListObj.hpp"
#include "src/Point.hpp"
#include "src/Snail.hpp"

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
    running = true;

    srand(time(NULL));

    Aquarium aqu;
    Point p1(250,250), p2(360, 360), p3(200, SCREEN_HEIGHT);
    Guppy g1(p1), g2(p2);
    Snail s1(p3);

    aqu.add(g1);
    aqu.add(g2);
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
        
        aqu.showImage();
        
        // Menampilkan uang
        
        draw_text("Money : " + to_string(aqu.getAccount().getMoney()), 18, 475, 10,230, 126, 34);
        
        draw_text("Egg   : " + to_string(aqu.getAccount().getEgg_Phase()) + "/3", 18, 475, 40,230, 126, 34);
        draw_text("Press '2' to buy Piranha (300)", 12, 475, 85,230, 126, 34);
        draw_text("Press '1' to buy Guppy (100)", 12, 475, 70,230, 126, 34);
        draw_text("Press '4' to buy Egg (1000)", 12, 475, 100,230, 126, 34);

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
            
            aqu.showImage();

            aqu.showAll();
                    
            if (aqu.lose()) {
                draw_image("img/lose.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            } else if (aqu.getAccount().win()) {
                draw_image("img/win.png", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            }
            
            update_screen();
        }
    }
    
    close();

    return 0;
}
