/*
 * Bit_Math.h
 *
 * Created: 9/14/2022 6:03:17 PM
 *  Author: Ahmed Aboraya
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg, Bit)		(Reg |= (1<<Bit))
#define RESET_BIT(Reg,Bit)		(Reg &=~ (1<<Bit))
#define TOGGLE_BIT(Reg,Bit)		(Reg ^= (1<<Bit))
#define GET_BIT(Reg,Bit)		((Reg >> Bit) & (0X01))

#define ASSIGN_PORT(Port, Bit)		(Port = Bit)

#define TOGGLE_PIN(Port,Pin)	(Port ^= Pin)



#endif /* BIT_MATH_H_ */
