const int relayPin = 3;
const int ldrSensor = A0;
int mySensorValue = 0;
int spraytTime = 10000;
int sprayInterval = 24000000;

void setup()
{
  Serial.begin(9600);
  pinMode(relayPin,OUTPUT);
}

void loop ()
{
  mySensorValue = analogRead(ldrSensor); //sensor reads the status of the ldrSensor

  firstSpray();       // starts spraying if the value still satisfied ie still during the day for 10 secs
  delay(sprayInterval);  // waits for four hours before the second spraying
  secondSpray();        // starts the second spraying after four hours then does it for 10 secs
  delay(sprayInterval);  // waits for four hours before the second spraying
  thirdSpray();        // starts the third spraying after four hours then does it for 10 secs
  delay(sprayInterval);
  fourthSpray();      // starts the fourth spraying after four hours then does it for 10 secs
  delay(sprayInterval);

}


void spray ()
{
  digitalWrite(relayPin,HIGH); // enables the pump to start spraying
}

void stopSpraying ()       // function that enables stopping of the pump hence spraying stops
{
  digitalWrite(relayPin,LOW);
}


void switchOff()         // for switching off the pump only
{
  digitalWrite(relayPin,LOW);
}


void firstSpray()        // function to do the firstSpraying
{
  takeReading();

  if(mySensorValue > 300)  // checks if its still day time else it switches off the pump diabling the process
  {
    spray();
    delay(spraytTime);
    stopSpraying();
  }

  else
  {
    switchOff();
  }
}
void secondSpray()          // function to do the secondSpraying
{
    takeReading();

  if(mySensorValue > 300)   // checks if its still day time else it switches off the pump diabling the process
  {
    spray();
    delay(spraytTime);
    stopSpraying();
  }

  else
  {
    switchOff();
  }
}


void thirdSpray()          // function to do the thirdSpraying
{
   takeReading();

  if(mySensorValue > 300)   // checks if its still day time else it switches off the pump diabling the process
  {
    spray();
    delay(spraytTime);
    stopSpraying();
  }

  else
  {
    switchOff();
  }
}


void fourthSpray()           // function to do the fourthSpraying
{
    takeReading();

  if(mySensorValue >  300)   // checks if its still day time else it switches off the pump diabling the process
  {
    spray();
    delay(spraytTime);
    stopSpraying();
  }

  else
  {
    switchOff();
  }
}

void takeReading()       // function to keep track of the sensor status
{
  do
  {
    mySensorValue = analogRead(ldrSensor);
  }

  while(mySensorValue < 300); 
}

