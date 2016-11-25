#include "bateries.h"
#include <iostream>
using namespace std;

Batery::Batery() {}
Batery::~Batery() {}

B2Batery::B2Batery(float charge[2]) {
  this->charge[0] = charge[0];
  this->charge[1] = charge[1];
  
  this->prop[0] = this->charge[0]/getTotalCharge();
  this->prop[1] = this->charge[1]/getTotalCharge();
}
B2Batery::~B2Batery() {}

float B2Batery::getCharge(int pos) { return this->charge[pos]; }
float B2Batery::getTotalCharge() { return getCharge(0) + getCharge(1); }
float B2Batery::setDischarge(float amount) {
  if (getCharge(0) > 0) {
    this->charge[0] -= (amount * this->prop[0]);
  }
  if (getCharge(1) > 0) {
    this->charge[1] -= (amount * this->prop[1]);
  }
  return getTotalCharge();
}
float getTotalBateries(Batery **bateries, int nBateries) {
  float total;
  for (int i = 0; i < nBateries; i++) {
    total += bateries[i]->getTotalCharge();
  }
  return total;
}
