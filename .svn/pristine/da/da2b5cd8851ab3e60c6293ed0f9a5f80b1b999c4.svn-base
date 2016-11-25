#include "player.h"

Player::Player(unsigned short nLifes,
               unsigned short nBullets,
               unsigned short armorLevel,
               unsigned short shotFactor) :
  nLifes(nLifes),
  nBullets(nBullets),
  armorLevel(armorLevel),
  shotFactor(shotFactor)
{}
unsigned short Player::getLifes() const { return nLifes; }
unsigned short Player::getArmorLevel() const { return armorLevel; }
unsigned short Player::getNbrBullets() const { return nBullets; }

bool Player::isAlive() const {
  if (getLifes() > 0) {
    return true;
  } else {
    return false;
  }
}

void Player::setLifes(unsigned short nLifes) {
  if (isAlive()) {
    this->nLifes += nLifes;
  }
}
void Player::setArmorLevel(unsigned short level) {
  if (isAlive()) {
    this->armorLevel += level;
  }
}
void Player::chargeCartridge(unsigned short nBullets) {
  if (isAlive()) {
    this->nBullets += nBullets;
  }
}
void Player::receiveShot() {
  if (isAlive()) {
    if (getArmorLevel() <= this->shotFactor) {
      this->armorLevel = 0;
      this->nLifes -= 1;
    } else {
      this->armorLevel -= shotFactor;
    }
  }
}
void Player::fireMachineGun() {
  if (isAlive() && (this->nBullets > 0)) {
    this->nBullets--;
  }
}
