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
typedef struct steering {
    uint8_t direction;// Forwawd/Backward
    uint16_t speed;
    uint8_t turn;
    uint16_t turn_ratio;
}steering;
#endif //MOTORDRIVER_H
