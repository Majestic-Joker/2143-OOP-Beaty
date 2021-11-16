/*
Each character will be generated as a descendant of BaseFighter. Base fighter has the following attributes:

Name : string
HP : Health points (random from 3 - 8)
RR : Regeneration Rate (random from .15 - .75)
PW : Primary Weapon = Fists and Feet
*/

#include <iostream>
#include <string>
#include "weapon.hpp"

using namespace std;

class BaseFighter{
protected:
  int currenthp, maxhp;
  double regenRate;
  int goodWeapon;
public:
  string name;
  Weapon* weapon;
  Weapon* weapon2;
  BaseFighter(){
    maxhp = 20;
    currenthp = 0;
    regenRate = (rand()%60+15)/100;
    weapon = new Weapon(); //should be fists and feet.
    goodWeapon = rand()%20;
  }
  int getCurrenthp() {
    return currenthp;
  }
  int getMaxhp() {
    return maxhp;
  }
  virtual int attack() = 0;
  //virtual int defend() = 0;
  void takeDamage(int x){
    currenthp -= x;
  }
  
  bool alive(){
    return currenthp > 0;
  }

  int getcurrenthp(){
    return currenthp;
  }

  void heal() {
    int healAmount = rand()%8+2;
    if (this->currenthp+healAmount < this->maxhp){
      currenthp += healAmount;
    }
    else
      currenthp = maxhp;
  }

  void regen(){
    currenthp += (maxhp * regenRate);
  }

  virtual void upgradeWeapon() = 0;
};

class Wizard: public BaseFighter{
protected:
  int dice;
public:
  Wizard(){
    name = "Wizard";
    dice = 8;
    maxhp += rand() % 3;
    currenthp += maxhp;
    weapon = new Wand();
  }
  int attack(){
    cout<<"Wizard attack: ";
    int r = weapon->die->roll();
    cout<<r<<endl;
    return r;
  }
  void upgradeWeapon(){
    if(!goodWeapon)
      weapon = new NapalmStaff();
  }
};

class Warrior: public BaseFighter{
protected:
  int dice;
public:
  Warrior(){
    name = "Warrior";
    dice = 8;
    maxhp += rand() % 10;
    currenthp += maxhp;
    weapon = new Sword();
  }
  int attack(){
    cout << "Warrior attack: ";
    int r = weapon->die->roll();
    cout<<r<<endl;
    return r;
  }

  void upgradeWeapon(){
    if(!goodWeapon)
      weapon = new Excalibur();
  }
  
};

class Dragonborn: public BaseFighter{
protected:
  int dice;
public:
  Dragonborn(){
    name = "Dragonborn";
    dice = 7;
    maxhp += rand() % 8;
    currenthp += maxhp;
    weapon = new Breath();
    weapon2 = new Magic();
  }

  int attack(){
    cout << "Dragonborn attack: ";
    int r = weapon->die->roll();
    cout<<r<<endl;
    return r;
  }

  void upgradeWeapon(){
    if(!goodWeapon)
      weapon = new Shout();
  }

};

class Archer : public BaseFighter{
  protected:
    int dice;
  public:
    Archer(){
      name = "Archer";
      dice = 6;
      maxhp += rand() % 5;
      currenthp += maxhp;
      weapon = new Bow();
    }
    int attack(){
      cout << "Archer attack: ";
      int r = weapon->die->roll();
      cout << r << endl;
      return r;
    }

    void upgradeWeapon(){
    if(!goodWeapon)
      weapon = new KillerBow();
  }
};

class Elf: public BaseFighter{
protected:
  int dice;
public: 
  Elf(){
    name = "Elf";
    dice = 9;
    maxhp += rand() % 4;
    currenthp += maxhp;
    weapon = new SneakyKnife();
    weapon2 = new Magic();
  }
  int attack(){
    cout << "Elf attack: ";
    int r = weapon->die->roll() + weapon2->die->roll();
    cout<<r<<endl;
    return r;
  }

  void upgradeWeapon(){
    if(!goodWeapon)
      weapon = new MehrunesRazor();
  }
};