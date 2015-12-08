
#include	"servo.h"

#include	<stdlib.h>
#include	<stdio.h>

servo_t		*servo_attach(firmata_t *firmata, int pin)
{
  servo_t	*res;

  if (!firmata || !firmata->isReady)
    {
      perror("servo_new::Firmata is not ready");
      return (NULL);
    }
  res = malloc(sizeof(servo_t));
  if (!res)
    {
      perror("servo_new::malloc failed");
      return (NULL);
    }
  res->firmata = firmata;
  res->pin = pin;
  firmata_pinMode(res->firmata, pin, MODE_SERVO);
  return (res);
}

int		servo_write(servo_t *servo, int value)
{
  return (firmata_analogWrite(servo->firmata, servo->pin, value));
}
