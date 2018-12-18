//**5V in**

//set analog pin
int ThermistorPin = A0;

//set constant resistance for know resistor
float R1 = 10000;

//initial value for Steinhart-Hart equation 
//used for convert the resistance of the thermistor to a temperature reading
int Vo;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
  //get analogRead from analog pin
  Vo = analogRead(ThermistorPin);

  //Steinhart-Hart equation
  //the T ouput is Kelvin
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));

  //Convert Kelvin to Celsius
  T = T - 273.15;

  //print the value
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C"); 

  //set delay output in millisecond (ms)
  delay(1000);
}
