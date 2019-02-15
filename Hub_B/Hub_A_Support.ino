/*  Most of the Hub_A Softserial support code is in
 *  the libaray "SerialB2A" 
 */

/***** CASE 0 *****/
void Reset()
{
  //restore the default settings
  //pass the default config to A.
  //put the flag pin low.
}

/***** CASE 5 *****/
int TurnOffFlag()
{
  digitalWrite(FLAG, LOW);
  //Clock.checkIfAlarm(1);
  //byte m = (Clock.getMinute() + logFreq) % 60;
  //Clock.setA1Time(Clock.getDate(), 0, m, 0, ALARM_BITS, false, h12, PM);
  //Serial.println(F("Alarm has been set!"));
  return 0;
}
