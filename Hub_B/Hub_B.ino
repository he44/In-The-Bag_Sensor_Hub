//==============================================================================
// Program:      Hub_B.ino
// Author:       Haowen Zhang
// Target:       Hub B
// Date:         2016/08/10
//==============================================================================


//=====[ INCLUDE ]==============================================================
#include <DS3231.h>
#include <SoftwareSerial.h>
#include <TalkB2A.h>
#include <SPI.h>
#include <SD.h>


//=====[ PINS ]=================================================================
//SD Card
#define CS          10
#define MOSI        11
#define MISO        12
#define CLK         13

#define FLAG        8
#define ALARM       2

//RTC
#define SDA         A4
#define SCL         A5

// SerialB2A
#define DATAIN      7
#define DATAOUT     6


//=====[ CONSTANTS ]============================================================
// Temperature and Humidity definitions
#define criticalTemp 50
#define criticalHum  80
//#define ALARM_BITS 8
#define ALARM_BITS 12

//=====[ VARIABLES ]============================================================
bool Century = false;
bool h12;
bool PM;
byte logFreq = 1;
char* AlertPhone = "+19546621746";


//=====[ OBJECTS ]==============================================================
TalkB2A SerialB2A(DATAIN, DATAOUT);
DS3231 Clock;

//=====[ SETUP ]================================================================
void setup() 
{
  Wire.begin();// RTC uses wire libaray
  Serial.begin(9600);
  SerialB2A.begin(9600);
  
  pinMode(ALARM, INPUT);
  pinMode(FLAG, OUTPUT);
  digitalWrite(FLAG, HIGH);
  

  // potentially dead loop here
  Serial.println(F("Setting up SD card..."));
  if (!SD.begin(CS)) 
  {
    Serial.println(F("SD failed!"));
    return;
  }
  
  SerialB2A.ClearAllBuffer();
  
  Clock.turnOnAlarm(1);
  byte m = (Clock.getMinute() + logFreq) % 60;
  Clock.setA1Time(Clock.getDate(), 0, m, 0, ALARM_BITS, false, h12, PM);
  Serial.println(F("Alarm has been set!"));

  Serial.println(F("Setup done."));
  digitalWrite(FLAG, LOW);
    //  Added for debug
    Serial.println(F("Hub B has written Flag to LOW, so Hub A can say Hub B is ready"));
}
//==============================================================================


//=====[ LOOP ]=================================================================
void loop() 
{
  //Check if it's time to remind Hub_A to check sensors
  if(Clock.checkIfAlarm(1))
  {
    digitalWrite(FLAG, HIGH);
    //Every Hour
    //byte h = (Clock.getHour(h12,PM) + logFreq) % 24;
    //Clock.setA1Time(Clock.getDate(), h, 0, 0, ALARM_BITS, false, h12, PM);
    
    //Every Minute
    byte m = (Clock.getMinute() + logFreq) % 60;
    Clock.setA1Time(Clock.getDate(), 0, m, 0, ALARM_BITS, false, h12, PM);
    Serial.println(F("Alarm has been set! In HubB's loop!"));
  }
  
  //Standby and wait for commands from Hub_A
  if(SerialB2A.available() > 0)
  {
    //Serial.println(F("Start Reading"));
    SerialB2A.listen();
    SerialB2A.ReadCommand();
    int i = atoi(SerialB2A.Parameter[0]);
    Serial.flush();

    switch(i)
    {
      case 1:
//      {SerialB2A.ReplyStatus(Reset());break;}
      case 2: // GetHubID
        {GetHubID();break;}
      case 3: // SetHubID
        {SerialB2A.ReplyStatus(SetHubID());break;}
      case 4: // CheckErrorHistory*
        {break;}
      case 5: // Turn off flag*
        {TurnOffFlag();break;}
      case 6: // Get a sensorID/ MAC address
        {GetMacAddress(atoi(SerialB2A.Parameter[1]));break;}
      case 7: // Set a sensor ID
        {break;}
      case 8: // SetMacAddress
        {SerialB2A.ReplyStatus(SetMacAddress());break;}
      case 9: //***
        {break;}
      case 10: // RemoveAllSensors
        {RemoveAllSensor();break;}
      case 11: // GetAlertPhone
        {GetNotificationPhone();break;}
      case 12: // SetAlertPhone
        {SerialB2A.ReplyStatus(SetNotificationPhone());break;}
      case 13: // GetPortalPhone
        {GetPortalPhone();break;}
      case 14: // SetPortalPhone
        {SerialB2A.ReplyStatus(SetPortalPhone());break;}
      case 15: // Get portal notification frequency
        {GetPortalNotificationFreq();break;}
      case 16: // Set portal notification frequency
        {SerialB2A.ReplyStatus(SetPortalNotificationFreq());break;}
      case 17: // Get Logging Frequency
        {GetLoggingFreq();break;}
      case 18: // Set Logging Frequency
        {SerialB2A.ReplyStatus(SetLoggingFreq());break;}
      case 19: // Get hub time
        {GetTime();break;}
      case 20: // Set hub time
        {SerialB2A.ReplyStatus(SetupTime());break;}
      case 21: // Get hub date
        {GetDate();break;}
      case 22: // Set hub date
        {SerialB2A.ReplyStatus(SetupDate());break;}
      case 23: // Get critical temperature
        {GetCritTemp();break;}
      case 24: // Set critical temperature
        {SerialB2A.ReplyStatus(SetCritTemp());break;}
      case 25: // Get critical humidity
        {GetCritHumidity();break;}
      case 26: // Set critical humidity
        {SerialB2A.ReplyStatus(SetCritHumidity());break;}
      case 27: // Get data
        {GetData();break;}
      case 28: // Record data
        {SerialB2A.ReplyStatus(RecordData());break;}
    }
    //Serial.println(F("done"));
  }
  else delay(100);

}
