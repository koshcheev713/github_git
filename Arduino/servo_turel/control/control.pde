import processing.serial.*;

// The serial port:
Serial port;

// List all the available serial ports:
int x = 90;
int y = 90;

void setup() {
  fill(0);
  size(360, 360);
  // Open the port you are using at the rate you want:
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  circle(x*2, y*2, 50);
  port.write('x');
  port.write(180);
  delay(1000);
  
  port.write('x');
  port.write(0);
  delay(1000);
  
  port.write('y');
  port.write(180);
  delay(1000);
  
  port.write('x');
  port.write(0);
  delay(1000);
  
  port.write('x');
  port.write(90);
  port.write('y');
  port.write(90);
  delay(1000);
}
