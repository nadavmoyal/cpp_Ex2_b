/**
 * Unit-Test for notebook exercise.
 * 
 * Author: Nadav Moyal
 * Since : 2022-03
 */
#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace ariel;

TEST_CASE("negative input for page / row / column / length "){
    Notebook n;
    int i=-1;
    while(i>-10){
    CHECK_THROWS(n.write(i,6,6,Direction::Horizontal,"nadav_moyal"));
    CHECK_THROWS(n.read(2,3,i,Direction::Horizontal,2));
    CHECK_THROWS(n.erase(0,i,10,Direction::Horizontal,5));
    CHECK_THROWS(n.read(0,10,10,Direction::Horizontal,i));
    CHECK_THROWS(n.show(i));
    i=i-1;
    }
}

TEST_CASE("write to place that already has words "){
    Notebook n;
    int i=1;
    while(i<10){
        
    n.write(i,i,i,Direction::Horizontal,"nadav_moyal");
    CHECK_THROWS(n.write(i,6,6,Direction::Horizontal,"nadav_moyal"));
    i=i+1;
    }
}

TEST_CASE("write again to place that already has erased "){
  Notebook n;
    int i=1;
    while(i<40){
    n.write(i,i,i,Direction::Horizontal,"nadav");
    n.erase(i,i,i,Direction::Horizontal,5);
    CHECK_THROWS(n.write(i,i,i,Direction::Horizontal,"shalom"));
    i=i+10;
    }
}
