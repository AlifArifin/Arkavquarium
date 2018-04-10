#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
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
    Aquarium aquarium();
    Point p1(100,100);
    Guppy g1();

    aquarium.add(g1);

    double prevtime = time_since_start();

    while (running) {
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
        draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        
        aquarium.moveAll(sec_since_last);

        for (int i = 0; i < list_food.size(); i++) {
            draw_image(list_food.get(i).image(), list_food.get(i).getPosition().getX(), list_food.get(i).getPosition().getX());
        }
        
        for (int i = 0; i < list_guppy.size(); i++) {
            draw_image(list_guppy.get(i).image(), list_guppy.get(i).getPosition().getX(), list_guppy.get(i).getPosition().getX());
        }
        
        for (int i = 0; i < list_piranha.size(); i++) {
            draw_image(list_piranha.get(i).image(), list_piranha.get(i).getPosition().getX(), list_piranha.get(i).getPosition().getX());
        }
        
        for (int i = 0; i < list_coin.size(); i++) {
            draw_image(list_coin.get(i).image(), list_coin.get(i).getPosition().getX(), list_coin.get(i).getPosition().getX());
        }

        for (int i = 0; i < list_snail.size(); i++) {
            draw_image(list_snail.get(i).image(), list_snail.get(i).getPosition().getX(), list_snail.get(i).getPosition().getX());
        }

        
        update_screen();
    }

    close();

    return 0;
}
