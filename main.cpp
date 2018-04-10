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

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_tapped_keys()) {
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
            case SDLK_4:
                if (aqu.getAccount().buyEgg()) {
                    
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

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_image("Aquarium.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        
        // Menampilkan uang
        draw_text("Money : " + to_string(aqu.getAccount().getMoney()), 18, 500, 30, 0, 0, 0);
        draw_text("Egg   : " + to_string(aqu.getAccount().getEgg_Phase()), 18, 500, 60, 0, 0, 0);

        aqu.moveAll(sec_since_last);
        aqu.showAll();

        update_screen();
    }

    close();

    return 0;
}
