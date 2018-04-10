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
    Point p1(250,250), p2(200, 0);
    Guppy g1(p1);
    Food f1(p2);

    aqu.add(g1);
    aqu.add(f1);

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

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_image("Aquarium.jpg", SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
        draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        //draw_text(to_string(sec_since_last), 18, 10, 30, 0, 0, 0);
        
        aqu.moveAll(sec_since_last);
        aqu.showAll();

        update_screen();
    }

    close();

    return 0;
}
