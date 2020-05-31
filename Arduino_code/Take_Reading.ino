

//This code takes a reading from the AS7265X Spectroscopy sensor
// it then sends the recording to the open log 

  void Take_Reading()
{
      sensor.takeMeasurementsWithBulb(); //This is a hard wait while all 18 channels are measured
    
      OpenLog.print(material);
      OpenLog.print(F(","));
      OpenLog.print(color);
      OpenLog.print(F(","));
      OpenLog.print(color2);
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedA());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedB());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedC());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedD());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedE());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedF());
      OpenLog.print(F(","));
    
      OpenLog.print(sensor.getCalibratedG());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedH());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedI());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedJ());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedK());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedL());
      OpenLog.print(",");
    
      OpenLog.print(sensor.getCalibratedR());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedS());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedT());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedU());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedV());
      OpenLog.print(F(","));
      OpenLog.print(sensor.getCalibratedW());
      OpenLog.print(F(","));
    
      OpenLog.println();
  //break;
  return;
}
