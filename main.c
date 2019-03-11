#pragma config(Sensor, in3,    inLightSensor,  sensorReflection)
#pragma config(Sensor, in4,    outLightSensor, sensorReflection)
#pragma config(Sensor, dgtl4,  armSwitch,      sensorTouch)
#pragma config(Sensor, dgtl5,  allClearSwitch, sensorTouch)
#pragma config(Sensor, dgtl6,  red1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  blue1,          sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  red2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  blue2,          sensorLEDtoVCC)
#pragma config(Motor,  port1,           windowFlashlight2, tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port3,           windowFlashlight1, tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port4,           doorFlashlight, tmotorVexFlashlight, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void LEDShow()
{
	turnLEDOn(red1);
}
int darkness;


task main()
{
	while(true)
	{
		turnFlashlightOn(windowFlashlight1);
		turnFlashlightOn(windowFlashlight2);
		turnFlashlightOn(doorFlashlight);
		if(SensorValue(armSwitch) == 1)	//if you touch the arm button
		{
			wait(10);	//wait 10
			darkness = SensorValue(inLightSensor);
		}
		while(SensorValue(outLightSensor) < 1000)
		{
			if(SensorValue(inLightSensor) < 1000) //if the light senosor senses a higher light level
			{
				wait(5); 	//wait 5
				if(SensorValue(allClearSwitch) == 1) //if touch the all clear button
				{
					stopAllTasks(); //end program
				}
				else //else
				{
					while(SensorValue(outLightSensor) < 100)
					{
					LEDShow(); //light up LEDs
					}
					if(SensorValue(outLightSensor) < 50) //if keyLightSensor gets a low value (lazer)
					{
						stopAllTasks(); //then end program
					}
				}
			}
		}	
	}
}
