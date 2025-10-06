//
// Created by Mateusz Moskwin on 16/05/2025.
//

#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H
void forward(uint8_t speed);
void backward(uint8_t speed);
void turnLeft(uint8_t speed);
void turnRight(uint8_t speed);
void stop();
void setPWM(uint16_t L,uint16_t R);
typedef struct steering {
    int16_t leftSpeed;
    int16_t rightSpeed;

}steering;
#endif //MOTORDRIVER_H
