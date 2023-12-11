/*
 * timer.h
 *
 *  Created on: Dec 11, 2023
 *      Author: Admin
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

extern int TIMER_CYCLE;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timer_run();

#endif /* INC_TIMER_H_ */
