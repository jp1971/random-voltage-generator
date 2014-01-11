/* Random Voltage Generator
 * ------------------------
 * This sketch reads the values of two (ideally 10K linear) potentiometers
 * Next, the values are run through the map function to scale the range
 * and invert the rate.  The values are then passed to the random function
 * that generate values for the analogWrite and delay functions.
 *
 * A Fritzing Sketch of this circuit can be found here:
 * http://jp1971.com/
 */
 
/*  Copyright 2014 JP1971 (jameson@jp1971.com)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
*/

// Define these values as necessary
int cvPin = 10;
int rangePin = 21;
int ratePin = 20;
// Leave these values alone
int range = 0;
int rate = 0;

void setup() {
  pinMode( cvPin, OUTPUT );
  Serial.begin(9600);
}

void loop() {
  // Read range potentiometer
  range = analogRead( rangePin );
  // Map value to scale appropriate for analogWrite
  range = map( range, 0, 1023, 0, 255 );
  Serial.print( "range: " );
  Serial.println( range );
  // Read range potentiometer
  rate = analogRead( ratePin );
  // If rate is less than 100, set it to 100.
  if( rate < 100 ) {
    rate = 100;
  }
  // Use map to invert value
  rate = map( rate, 100, 1023, 1023, 100 );
  Serial.print( "rate: " );
  Serial.println( rate );
  // Write CV
  analogWrite( cvPin, random( 0, range ) );
  // Wait
  delay( random( 100, ( rate + 100 ) ) );
}