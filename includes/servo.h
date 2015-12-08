
#ifndef		__H_FIRMATA_SERVO__
#define		__H_FIRMATA_SERVO__

#include	"firmata.h"

typedef struct	s_servo
{
  firmata_t	*firmata;
  int		pin;
}		servo_t;

servo_t		*servo_attach(firmata_t *firmata, int pin);
int		servo_write(servo_t *servo, int value);

#endif
