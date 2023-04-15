import processing.serial.*;
Serial serial;
int ser = 255;

void setup() {
  size(240, 160);
  //print(Serial.list());
  serial = new Serial(this, "/dev/ttyUSB0", 9600);
}

void draw() {
  serial.write('w');
  serial.write(122);
}
