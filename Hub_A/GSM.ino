void sendAlert(byte txt)
{ 
  cell.listen();
  delay(500);
  cell.FwdSMS2Serial();
  cell.Rcpt(AlertPhone);
  
  switch(txt)
  {
    case 1:
      cell.Message("Critical Temperature and Humidity!");
      break;
    case 2:
      cell.Message("Critical Temperature!");
      break;
    case 3:
      cell.Message("Critical Humidity!");
      break;
  }
  
  cell.SendSMS();
  cell.DeleteAllSMS();
  
}

void alertPortal(char * message)
{
  cell.listen();
  delay(500);
  cell.FwdSMS2Serial();
  cell.SendSMS(PortalPhone, message);
}

void GSMcommand()
{
  cell.SendSMS(AlertPhone, "received");
  cell.listen();
  delay(500);
  cell.FwdSMS2Serial();
  cell.ReceiveSMS();
  Serial.println(cell.inmessage);
  BTSerial.listen();
}
