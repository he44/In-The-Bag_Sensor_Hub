/***** CASE 2 *****/
void GetHubID(){
  File dataFile = SD.open(F("config.txt"));
  if (dataFile) {
    SeekLine(&dataFile,0);
    MoveCursor(&dataFile);
      if (dataFile.available()) {
        ReadUntilSpace(&dataFile);
//      dataFile.read(SerialB2A.Buffer,4);
      Serial.println(SerialB2A.Buffer);
      SerialB2A.SendData();
      }
      else{
        SerialB2A.ReplyStatus(2);//No infomation error
      }
  }
  else
  {
    SerialB2A.ReplyStatus(1);//Cannot open file error
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}

/***** CASE 3 *****/
int SetHubID(){
  File dataFile = SD.open(F("config.txt"), FILE_WRITE);
  if(dataFile) {
  InitailLine(&dataFile,0);
  Serial.print(SerialB2A.Parameter[1]);
  dataFile.print(SerialB2A.Parameter[1]);
  SerialB2A.ClearAllBuffer();
  dataFile.close();
  return 0;
  }
  else
  {
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 1;
  }
}

/***** CASE 4 *****/
void CheckErrorHistory()
{
  
}


/***** CASE 6 *****/
void GetMacAddress(int sensorNum)
{
  File dataFile = SD.open(F("SensAddr.txt"));
  if (dataFile)
  {
    SeekLine(&dataFile,sensorNum);
    Serial.println(dataFile.available());
    if (dataFile.available()>0)
    {
      dataFile.read(SerialB2A.Buffer,12);
      Serial.println(SerialB2A.Buffer);
      SerialB2A.SendData();
    }
    else
    {
        SerialB2A.ReplyStatus(2);//No infomation error
    }
  }
  else
  {
    SerialB2A.ReplyStatus(1);//Cannot open file error
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}


/***** CASE 8 *****/
int SetMacAddress()
{
  File dataFile = SD.open(F("SensAddr.txt"), FILE_WRITE);
  if(dataFile) 
  {
//  SeekLine(&dataFile,atoi(SerialB2A.Parameter[1]));//Move the curse to the right line.
//  dataFile.print(SerialB2A.Parameter[1]);//Sensor number,2 digits
//  dataFile.print(' ');
    dataFile.println(SerialB2A.Parameter[1]);//MAC Address
    Serial.println(SerialB2A.Parameter[1]);
//  dataFile.flush();
    Serial.println(0);
    SerialB2A.ClearAllBuffer();
    Serial.println(1);
    dataFile.close();
    return 0;
  }
  else
  {
    SerialB2A.ClearAllBuffer();
    return 1;
  }
}

/***** CASE 10 *****/
void RemoveAllSensor()
{
  SD.remove(F("SensAddr.txt"));
}







/***** CASE 11 *****/
void GetNotificationPhone(){
  File dataFile = SD.open(F("config.txt"));
  if (dataFile) {
    SeekLine(&dataFile,1);
    MoveCursor(&dataFile);
    if (dataFile.available()) {
      ReadUntilSpace(&dataFile);
      Serial.println(SerialB2A.Buffer);
      SerialB2A.SendData();
    }
    else{
        SerialB2A.ReplyStatus(2);//No infomation error
    }
  }
  else{
    SerialB2A.ReplyStatus(1);//Cannot open file error
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}

/***** CASE 12 *****/
int SetNotificationPhone(){
  File dataFile = SD.open(F("config.txt"), FILE_WRITE);
  if(dataFile) 
  {
    InitailLine(&dataFile,1);
    Serial.print(SerialB2A.Parameter[1]);
    dataFile.print(SerialB2A.Parameter[1]);
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 0;
  }
  else
  {
    SerialB2A.ClearAllBuffer();
    return 1;
  }
}

/***** CASE 13 *****/
void GetPortalPhone()
{
  File dataFile = SD.open(F("config.txt"));
  if (dataFile)
  {
    SeekLine(&dataFile,2);
    MoveCursor(&dataFile);
    if (dataFile.available())
    {
      ReadUntilSpace(&dataFile);
      Serial.println(SerialB2A.Buffer);
      SerialB2A.SendData();
    }
    else
        SerialB2A.ReplyStatus(2);//No infomation error
  }
  else
    SerialB2A.ReplyStatus(1);//Cannot open file error

  SerialB2A.ClearAllBuffer();
  dataFile.close();
}


/***** CASE 14 *****/
int SetPortalPhone()
{
  File dataFile = SD.open(F("config.txt"), FILE_WRITE);
  if(dataFile)
  {
    InitailLine(&dataFile,2);
    Serial.print(SerialB2A.Parameter[1]);
    dataFile.print(SerialB2A.Parameter[1]);
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 0;
  }
  else
  {
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 1;
  }
}







/***** CASE 15 *****/
void GetPortalNotificationFreq(){
  File dataFile = SD.open(F("config.txt"));
  if (dataFile) {
  SeekLine(&dataFile,3);
  MoveCursor(&dataFile);
    if (dataFile.available()) {
      ReadUntilSpace(&dataFile);
    Serial.println(SerialB2A.Buffer);
    SerialB2A.SendData();
    }
    else{
        SerialB2A.ReplyStatus(2);//No infomation error
    }
  }
  else{
    SerialB2A.ReplyStatus(1);//Cannot open file error
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}


/***** CASE 16 *****/
int SetPortalNotificationFreq(){
  File dataFile = SD.open(F("config.txt"), FILE_WRITE);
  if(dataFile) {
    InitailLine(&dataFile,3);
    Serial.print(SerialB2A.Parameter[1]);
    dataFile.print(SerialB2A.Parameter[1]);
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 0;
  }
  else{
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 1;
  }
}


/***** CASE 17 *****/
void GetLoggingFreq()
{
  File dataFile = SD.open(F("config.txt"));
  if (dataFile) 
  {
    SeekLine(&dataFile,4);
    MoveCursor(&dataFile);
    if(dataFile.available()) 
    {
      ReadUntilSpace(&dataFile);
      Serial.println(SerialB2A.Buffer);
      SerialB2A.SendData();
      logFreq = atoi(SerialB2A.Buffer);
    }
    else
    {
        SerialB2A.ReplyStatus(2);//No infomation error
    }
  }
  else
  {
    SerialB2A.ReplyStatus(1);//Cannot open file error
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}


/***** CASE 18 *****/
int SetLoggingFreq()
{
  File dataFile = SD.open(F("config.txt"), FILE_WRITE);
  if(dataFile) 
  {
    InitailLine(&dataFile,4);
    Serial.print(SerialB2A.Parameter[1]);
    dataFile.print(SerialB2A.Parameter[1]);
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    logFreq = atoi(SerialB2A.Parameter[1]);
    return 0;
  }
  else
  {
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 1;
  }
}



/***** CASE 23 *****/
void GetCritTemp()
{
  File dataFile = SD.open(F("config.txt"));
  if (dataFile) 
  {
    SeekLine(&dataFile,5);
    MoveCursor(&dataFile);
    if (dataFile.available()) {
      ReadUntilSpace(&dataFile);
      Serial.println(SerialB2A.Buffer);
      SerialB2A.SendData();
    }
    else
    {
        SerialB2A.ReplyStatus(2);//No infomation error
    }
  }
  else
  {
    SerialB2A.ReplyStatus(1);//Cannot open file error
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}

/***** CASE 24 *****/
int SetCritTemp()
{
  File dataFile = SD.open(F("config.txt"), FILE_WRITE);
  if(dataFile) {
  InitailLine(&dataFile,5);
  Serial.println(SerialB2A.Parameter[1]);
  dataFile.print(SerialB2A.Parameter[1]);
  dataFile.close();
  SerialB2A.ClearAllBuffer();
  return 0;
  }
  else
  {
    dataFile.close();
    SerialB2A.ClearAllBuffer();
    return 1;
  }
}


/***** CASE 25 *****/
void GetCritHumidity()
{
  File dataFile = SD.open(F("config.txt"));
  if (dataFile) 
  {
    SeekLine(&dataFile,6);
    MoveCursor(&dataFile);
    if (dataFile.available()) 
    {
      ReadUntilSpace(&dataFile);
      Serial.println(SerialB2A.Buffer);
      SerialB2A.SendData();
    }
    else
    {
        SerialB2A.ReplyStatus(2);//No infomation error
    }
  }
  else
  {
    SerialB2A.ReplyStatus(1);//Cannot open file error
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}


/***** CASE 26 *****/
int SetCritHumidity()
{
  File dataFile = SD.open(F("config.txt"), FILE_WRITE);
  if(dataFile) 
  {
    InitailLine(&dataFile,6);
    Serial.print(SerialB2A.Parameter[1]);
    dataFile.print(SerialB2A.Parameter[1]);
    dataFile.close();
    SerialB2A.ClearAllBuffer();
    return 0;
  }
  else
  {
    dataFile.close();
    SerialB2A.ClearAllBuffer();
    return 1;
  }
}



/***** CASE 27 *****/
void GetData(){
  int Year = atoi(SerialB2A.Parameter[1]);
  int Month = atoi(SerialB2A.Parameter[2]);
  int Day = atoi(SerialB2A.Parameter[3]);
  SerialB2A.GetFilename(Year,Month,Day,0);
  Serial.println(SerialB2A.TimeBuffer);
  File dataFile = SD.open(SerialB2A.TimeBuffer);
  SerialB2A.ClearAllBuffer();
  if(dataFile)
  {
      while(dataFile.available())
      {
        strcpy(SerialB2A.Buffer,dataFile.readString().c_str());
        Serial.println(SerialB2A.Buffer);
        SerialB2A.SendData();
      }
  }
  SerialB2A.ClearAllBuffer();
  dataFile.close();
}

//  Need to print out what happens before, within and after this function
//  Based on the terminal output, this function might never get called
/***** CASE 28 *****/
int RecordData()
{
  Serial.println(F("Recording!"));
  Serial.flush();
  int year = Clock.getYear();
  int month = Clock.getMonth(Century);
  int day = Clock.getDate();
  SerialB2A.GetFilename(year,month,day, 0);
  Serial.println(SerialB2A.TimeBuffer);
  File dataFile = SD.open(SerialB2A.TimeBuffer, FILE_WRITE);
  if(dataFile)
  {
    if(dataFile.size() <= 1)
    { // Add the headings
      dataFile.println(F("Date,Time,Sensor ID,Temperature,Humidity"));
    }
    dataFile.print(F("20"));
    dataFile.print(year,DEC);
    dataFile.print('-');
    dataFile.print(month,DEC);
    dataFile.print('-');
    dataFile.print(day,DEC);
    dataFile.print(',');
    dataFile.print(Clock.getHour(h12,PM),DEC);
    dataFile.print(':');
    dataFile.print(Clock.getMinute(),DEC);
    dataFile.print(':');
    dataFile.print(Clock.getSecond(),DEC);
    dataFile.print(',');
    dataFile.print(SerialB2A.Parameter[1]);
    Serial.println(SerialB2A.Parameter[1]);
    dataFile.print(',');
    dataFile.print(SerialB2A.Parameter[2]);
    Serial.println(SerialB2A.Parameter[2]);
    dataFile.print(',');
    dataFile.println(SerialB2A.Parameter[3]);
    Serial.println(SerialB2A.Parameter[3]);
    SerialB2A.ClearAllBuffer();
    dataFile.close();
    return 0;
  }
  else
  {
    Serial.println("Error creating data files");
    SerialB2A.ClearAllBuffer();
    return 1;
  }
}












