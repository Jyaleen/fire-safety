
int photoresistor = 0;              //this variable will hold a value based on the brightness of the ambient light
int threshold = 900;                //if the photoresistor reading is below this value the the light will turn on
int counter = 0;                   //how many times has the photoresister been hit?

void setup()
{
  Serial.begin(9600);               //start a serial connection with the computer

  pinMode(13, OUTPUT);              //set pin 13 as an output that can be set to HIGH or LOW
}

void loop()
{
  //read the brightness of the ambient light
  photoresistor = analogRead(A0);   //set photoresistor to a number between 0 and 1023 based on how bright the ambient light is
  Serial.println(photoresistor);    //print the value of photoresistor in the serial monitor on the computer

  //if the photoresistor value is higher the threshold turn the light on, otherwise turn it off
  if ((photoresister > threshold) && (counter >= 3)) {
    digitalWrite(13, HIGH);       // Turn on the LED
    counter = 0;
  } else {
    digitalWrite(13, LOW);        // Turn off the LED
  }
  delay(100);                       //short delay to make the printout easier to read
}