
#include <stdio.h>
#include <stdlib.h>
void  turn_on_vehicle();
void  turn_off_vehicle();
void quit();
void  system_state();
void set_traffic_light_color();
void set_room_temperatue();
void set_engine_temperature();
void based_on_traffic_light_data();
void based_on_room_temperature();
void based_on_engine_temperature();
void if_vehicle_speed_is_30();
void display();
char input;
char engine_status=0; //initial condition for engine=on
char quit_system=0;  //initial condition for system=on
char choice;
char traffic_color='R';
int room_temperature=25;
int engine_temperature=120;
char AC;
char engine_temperature_controller;
int vehicle_speed;
int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	//ask the user about the action he wants to do
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	scanf(" %c",&input);
	switch(input)
	{
	case 'a':
		turn_on_vehicle();
		break;
	case 'b':
		turn_off_vehicle();
		break;
	case 'c':
		quit();
		break;
	default:
		printf("invalid input \n");

	}
	while((engine_status==0)&&(quit_system==0)) //if the engine is off and system is still on
	{
		//ask the user about the action he wants to do
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n");
		scanf(" %c",&input);
		switch(input)
		{
		case 'a':
			turn_on_vehicle();
			break;
		case 'b':
			turn_off_vehicle();a
			break;
		case 'c':
			quit();
			break;
		default:
			printf("invalid input \n");
		}
	}

	system_state(); //display the current system status

	while(quit_system==0)
	{
		printf("a. Turn off the engine\n");
		printf("b. Set the traffic light color\n");
		printf("c. Set the room temperature (Temperature Sensor)\n");
		printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
		scanf(" %c",&choice);
		switch(choice)//menu to ask which choice you want
		{
		case 'a':
			turn_off_vehicle();
			break;
		case 'b':
			set_traffic_light_color();
			break;
		case 'c':
			set_room_temperatue();
			break;
		case 'd':
			set_engine_temperature();
			break;
		default:
			printf("invalid input \n");
		}
		based_on_traffic_light_data();
		based_on_room_temperature();
		based_on_engine_temperature();
		if_vehicle_speed_is_30();
		display();
		while((engine_status==0)&&(quit_system==0)) //if the engine is off and system is still on
		{
			//ask the user about the action he wants to do
			printf("a. Turn on the vehicle engine\n");
			printf("b. Turn off the vehicle engine\n");
			printf("c. Quit the system\n");
			scanf(" %c",&input);
			switch(input)
			{
			case 'a':
				turn_on_vehicle();
				break;
			case 'b':
				turn_off_vehicle();
				break;
			case 'c':
				printf("the system is now off \n");
				quit();
				break;
			default:
				printf("invalid input \n");
			}
		}

	}


	return 0;
}

void  turn_on_vehicle()//function to turn on the engine
{
	engine_status=1;

}
void  turn_off_vehicle()//function to turn off the engine
{
	engine_status=0;
}
void quit()// function to quit system
{
	quit_system=1;
	engine_status=0;

}

void  system_state()//print current state
{
	if(engine_status==1)
	{
		printf("the vehicle is on \n");
	}
	else
	{
		printf("the vehicle is off \n");

	}
	if(quit_system==1)
	{
		printf("the system is off \n");

	}
	else
	{
		printf("the system is on \n");

	}


}
void set_traffic_light_color() //to set current traffic light
{
	printf("please enter the current traffic color G  O  R\n");
	scanf(" %c",&traffic_color);
}

void set_room_temperatue()//set room temperature
{
	printf("please enter the current room temperature\n");
	scanf(" %d",&room_temperature);
}

void set_engine_temperature() //set engine temperature
{
	printf("please enter the current engine temperature\n");
	scanf(" %d",&engine_temperature);
}
void based_on_traffic_light_data()//control vehicle speed
{
	if((traffic_color=='G')||(traffic_color=='g'))
	{
		vehicle_speed=100;
	}
	if((traffic_color=='O')||(traffic_color=='o'))
	{
		vehicle_speed=30;
	}
	if((traffic_color=='R')||(traffic_color=='r'))
	{
		vehicle_speed=0;
	}
}
void based_on_room_temperature()//function to control ac and room temperature
{
	if(room_temperature<10)
	{
		AC=1;//turn on AC
		room_temperature=20;
	}
	else if(room_temperature>30)
	{
		AC=1;//turn on AC
		room_temperature=20;
	}
	else
	{
		AC=0;//turn off AC
	}

}
void based_on_engine_temperature()
{
	if(engine_temperature<100)
	{
		engine_temperature_controller=1;//turn on engine temperature controller
		engine_temperature=125;
	}
	else if(engine_temperature>150)
	{
		engine_temperature_controller=1;//turn on engine temperature controller
		engine_temperature=125;
	}
	else
	{
		engine_temperature_controller=0;//turn off engine temperature controller

	}

}

void if_vehicle_speed_is_30()//check if current speed is 30 and do some actions
{
	if(vehicle_speed==30)
	{
		AC=1;
		room_temperature=(room_temperature*1.25)+1;
		engine_temperature_controller=1;
		engine_temperature=(engine_temperature*1.25)+1;
	}
}
void display()
{
	if(engine_status==1)
	{
		printf("the vehicle is on \n");
	}
	else
	{
		printf("the vehicle is off \n");

	}
	if(AC==1)
	{
		printf("the AC is on \n");
	}
	else
	{
		printf("the AC is off \n");

	}
	printf("the current speed is %d \n",vehicle_speed);
	printf("the current room temperature is %d \n",room_temperature);
	if(engine_temperature_controller==1)
	{
		printf("the engine temperature controller is on \n");
	}
	else
	{
		printf("the engine temperature controller is off \n");

	}
	printf("the current engine temperature is %d \n",engine_temperature);



}






