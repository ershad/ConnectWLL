/*
 *      connectwll.cpp
 *
 *      Copyright 2009 Ershad K  ershad92@gmail.com
 *      Licensed under GPL Version 3
 *
 *      Please change USERNAME, PASSWORD and compile with g++
 *      To compile - g++ connectwll.cpp
 *      To execute - ./a.out
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main ()
{
	char username[25];
	char password[25];
	
	puts("\n Connect WLL easily!  www.ershadk.wordpress.com\n\n");
	
	ifstream conf("wllconf");
	conf.getline(username,25);
	conf.getline(password,25);
	conf.close();
	
	ofstream myfile;
	system("sudo wvdialconf");
	myfile.open ("/etc/widial.conf");
        myfile << "[Dialer Defaults]\nInit1 = ATZ\nInit2 = ATQ0 V1 E1 S0=0 "
               << "&C1 &D2 +FCLASS=0\nInit3 = at+crm=1;+cmux=1;+cps=33;+cta=0"
               << "\nModem Type = Analog Modem\nISDN = 0\nPhone = #777\nModem"
               << " = /dev/ttyUSB0\nUsername = "<<username<<"\nPassword = "
               <<password<<"\nBaud = 460800\nStupid Mode = 1\nAuto DNS\nCheck"
                <<" Def Route";
	myfile.close();
	system("sudo wvdial");
	cout << "\a";
	return 0;
}
